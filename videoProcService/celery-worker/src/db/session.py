from typing import Generator

from sqlalchemy.orm import sessionmaker, Session
from sqlalchemy import create_engine

from ..config import Config


engine = create_engine(
    f"postgresql+psycopg2://{Config.POSTGRES_USER}:{Config.POSTGRES_PASSWORD}@pg-server:{Config.POSTGRES_PORT}/{Config.POSTGRES_DB}",
    future=True,
    echo=False,
    pool_use_lifo=True,
    pool_pre_ping=True,
)

sync_session = sessionmaker(engine, expire_on_commit=False, class_=Session)
