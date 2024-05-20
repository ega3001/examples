import os
from typing import get_type_hints, Union


class AppConfigError(Exception):
    pass


class AppConfig:
    POSTGRES_USER: str
    POSTGRES_PASSWORD: str
    POSTGRES_DB: str
    POSTGRES_PORT: int

    MINIO_ROOT_USER: str
    MINIO_ROOT_PASSWORD: str
    MINIO_BUCKET_NAME: str
    MINIO_SERVER_PORT: int

    REDIS_SERVER_PORT: int
    
    PROCS_END_PORT: int

    """
    Map environment variables to class fields according to these rules:
      - Field won't be parsed unless it has a type annotation
      - Field will be skipped if not in all caps
      - Class field and environment variable name are the same
    """

    def _parse_bool(val: Union[str, bool]) -> bool:
        return val if type(val) == bool else val.lower() in ["true", "yes", "1"]

    def __init__(self):
        for field in self.__annotations__:
            if not field.isupper():
                continue

            default_value = getattr(self, field, None)
            if default_value is None and os.getenv(field) is None:
                raise AppConfigError("The {} field is required".format(field))

            try:
                var_type = get_type_hints(AppConfig)[field]
                if var_type == bool:
                    value = self._parse_bool(os.getenv(field, default_value))
                else:
                    value = var_type(os.getenv(field, default_value))

                self.__setattr__(field, value)
            except ValueError:
                raise AppConfigError(
                    'Unable to cast value of "{}" to type "{}" for "{}" field'.format(
                        os.getenv(field, None), var_type, field
                    )
                )

    def __repr__(self):
        return str(self.__dict__)


Config = AppConfig()
