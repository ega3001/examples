from minio import Minio

from .config import Config


minio_client = Minio(
    f"minio-server:{Config.MINIO_SERVER_PORT}",
    access_key=Config.MINIO_ROOT_USER,
    secret_key=Config.MINIO_ROOT_PASSWORD,
    secure=False
)

