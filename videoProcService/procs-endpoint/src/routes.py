from datetime import timedelta
from io import BytesIO

from fastapi import APIRouter, Depends, UploadFile, File
from fastapi.responses import JSONResponse
from sqlalchemy.ext.asyncio import AsyncSession

from .minio import minio_client
from .celery import celery_app
from .config import Config
from .logger import logger
from .db import Video, Profile, get_db


router = APIRouter()


@router.post("/video")
async def upload_file(
    file: UploadFile = File(), 
    db: AsyncSession = Depends(get_db)
):
    try:
        file_contents = await file.read()
        file_stream = BytesIO(file_contents)
        
        upload_res = minio_client.put_object(Config.MINIO_BUCKET_NAME, file.filename, file_stream, len(file_contents))

        url = minio_client.get_presigned_url(
            "GET",
            Config.MINIO_BUCKET_NAME,
            upload_res.object_name,
            expires=timedelta(days=7),
        )

        async with db.begin():
            vid = Video(
                file_name = upload_res.object_name,
                file_url = url
            )
            db.add(vid)
            db.flush()
        
            task = celery_app.send_task("ProcessVideo", (vid.id, 0))

            vid.task_id = task.id
        
        return JSONResponse(
            status_code=200,
            content={
                "video_id": vid.id
            }
        )
    except Exception as e:
        if upload_res:
            minio_client.remove_object(Config.MINIO_BUCKET_NAME, upload_res.object_name)
        logger.info(f"An error while file uploading: {str(e)}")
        return JSONResponse(
            status_code=500,
            content={
                "message": "Something goes wrong"
            }
        )


@router.delete("/video/{video_id}")
async def delete_file(
    video_id: str,
    db: AsyncSession = Depends(get_db)
):
    try:
        async with db.begin():
            db_vid = db.query(Video).get(video_id)
            minio_client.remove_object(Config.MINIO_BUCKET_NAME, db_vid.file_name)
            celery_app.control.revoke(db_vid.task_id, terminate=True)
            db.query(Profile).filter(Profile.id_video == db_vid.id).delete()
            db_vid.delete()
        
        return JSONResponse(
            status_code=200,
            content={
                "message": "File deleted successfully"
            }
        )
    except Exception as e:
        logger.info(f"An error while file deleting: {str(e)}")
        return JSONResponse(
            status_code=500,
            content={
                "message": "Something goes wrong"
            }
        )