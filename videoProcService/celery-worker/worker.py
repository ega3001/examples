import uuid
from io import BytesIO
from datetime import timedelta

import cv2

from src.celery import app
from src.config import Config
from src.minio import minio_client
from src.logger import logger
from src.db import Video, Profile, sync_session



@app.task(name='ProcessVideo')
def add(video_id, start_from):
    logger.info(f"Starting process video({video_id})")
    db_vid = get_video(video_id)

    video_capture = cv2.VideoCapture(db_vid.url)
    total_fr = int(video_capture.get(cv2.CAP_PROP_FRAME_COUNT))
    video_capture.set(cv2.CAP_PROP_POS_FRAMES, start_from)
    
    face_cascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_frontalface_default.xml')
    
    faces = []
    proc_frames = start_from
    while True:
        ret, frame = video_capture.read()
        if not ret:
            upload_profiles(video_id, faces)
            break
        
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        
        detected_faces = face_cascade.detectMultiScale(gray, scaleFactor=1.1, minNeighbors=5, minSize=(30, 30))
        
        for (x, y, w, h) in detected_faces:
            face = frame[y:y+h, x:x+w]
            faces.append(face)
        
        proc_frames += 1
        if proc_frames % Config.CELERY_WORKER_PUSH_EVERY == 0:
            upload_profiles(video_id, faces)
            update_video_stats(video_id, total_fr, proc_frames)
            faces.clear()
        logger.info(f"Successfully saved {len(faces)} new objects for video{video_id}!")
    
def get_video(id):
    with sync_session() as session:
        with session.begin():
            db_vid = session.query(Video).get(id)
    return db_vid

def update_video_stats(video_id, total_fr, proc_fr):
    with sync_session() as session:
        with session.begin():
            obj = session.query(Video).get(video_id)
            obj.frames_total = total_fr
            obj.frames_processed = proc_fr

def upload_profiles(video_id, faces):
    logger.info(f"Saving result to db for video{video_id}...")
    profiles = []
    for face in faces:
        crop_bytes = cv2.imencode('.bmp', face)[1].tobytes()
        put_result = minio_client.put_object(
            Config.MINIO_BUCKET_NAME,
            f"{uuid.uuid4()}.bmp",
            BytesIO(crop_bytes),
            len(crop_bytes)
        )
        url = minio_client.get_presigned_url(
            "GET",
            Config.MINIO_BUCKET_NAME,
            put_result.object_name,
            expires=timedelta(days=7),
        )
        profiles.append(
            Profile(
                id_video = video_id,
                crop_name = put_result.object_name,
                crop_url = url
            )
        )
    with sync_session() as session:
        with session.begin():
            session.bulk_save_objects(profiles)