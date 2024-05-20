CREATE TABLE Videos (
    id SERIAL PRIMARY KEY,
    created TIMESTAMP DEFAULT current_timestamp,
    file_name VARCHAR(40) NOT NULL,
    file_url VARCHAR(200) NOT NULL,
    status INTEGER DEFAULT 0,
    frames_processed INTEGER DEFAULT 0,
    frames_total INTEGER DEFAULT 100,
    task_id VARCHAR(50) NULL
);

CREATE TABLE Profiles (
    id SERIAL PRIMARY KEY,
    id_video SERIAL NOT NULL,
    crop_name VARCHAR(40) NOT NULL,
    crop_url VARCHAR(200) NOT NULL,
    FIO VARCHAR(100) NULL,
    gender VARCHAR(1) NULL,
    birth_date TIMESTAMP NULL,
    CONSTRAINT fk_profile_video
      FOREIGN KEY(id_video)
        REFERENCES Videos(id)
) PARTITION BY RANGE (id);