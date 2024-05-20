from celery import Celery

from .config import Config


celery_app = Celery(
    'video-proc-queue',
    broker=f'redis://redis-server:{Config.REDIS_SERVER_PORT}/',
    backend=f'redis://redis-server:{Config.REDIS_SERVER_PORT}/',
)