import uuid
from datetime import datetime

from sqlalchemy import Column, Boolean, String, Integer, DateTime, Float, Sequence
from sqlalchemy.dialects.postgresql import UUID, JSONB, INTERVAL, VARCHAR
from sqlalchemy.orm import declarative_base
from sqlalchemy.sql.schema import ForeignKey

Base = declarative_base()


class Video(Base):
    __tablename__ = "videos"

    id = Column(Integer, Sequence("videos_id_seq"), primary_key=True)
    created = Column(DateTime),
    file_name = Column(VARCHAR(40))
    file_url = Column(VARCHAR(200))
    status = Column(Integer)
    frames_processed = Column(Integer)
    frames_total = Column(Integer)
    task_id = Column(VARCHAR(50))


class Profile(Base):
    __tablename__ = "profiles"

    id = Column(Integer, Sequence("profile_id_seq"), primary_key=True)
    id_video = Column(Integer, Sequence("profiles_id_video_seq"))
    crop_name = Column(VARCHAR(40))
    crop_url = Column(VARCHAR(200))
    FIO = Column(VARCHAR(100))
    gender = Column(VARCHAR(1))
    birth_date = Column(DateTime)