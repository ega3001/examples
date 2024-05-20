import uvicorn
from fastapi import FastAPI, status, Request

from src.minio import minio_client
from src.routes import router
from src.config import Config
from src.logger import logger


app = FastAPI(title="File uploader", version="1.0.0")
app.include_router(router, prefix="")


if __name__ == "__main__":
    logger.info(f"Initiating S3...")
    found = minio_client.bucket_exists(Config.MINIO_BUCKET_NAME)
    if not found:
        logger.info(f"Creating bucket '{Config.MINIO_BUCKET_NAME}'...")
        minio_client.make_bucket(Config.MINIO_BUCKET_NAME)
        logger.info(f"Successfully created")
    else:
        logger.info(f"Bucket '{Config.MINIO_BUCKET_NAME}' already exists")
    logger.info("Starting server...")
    uvicorn.run(app, host="0.0.0.0", port=Config.PROCS_END_PORT)