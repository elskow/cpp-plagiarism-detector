import os
import time
import tempfile
import uvicorn

from fastapi import FastAPI, UploadFile, HTTPException, File, status
from fastapi.responses import JSONResponse
from fastapi.encoders import jsonable_encoder
from fastapi.exceptions import RequestValidationError
from fastapi.middleware.cors import CORSMiddleware
from starlette.exceptions import HTTPException as StarletteHTTPException

from code_plagiarism_detector.iterator import CodePlagiarismIterator
from model import PlagiarismResponse, PlagiarismResult
from util import save_upload_file
from config import HOST, PORT, CONFIG, CLIENT_ORIGIN
from extractor import (
    ZipExtractor,
    RarExtractor,
    TarGzExtractor,
    TarXzExtractor,
    FolderExtractor,
)


app = FastAPI(**CONFIG)

app.add_middleware(
    CORSMiddleware,
    allow_origins=CLIENT_ORIGIN,
    allow_credentials=True,
    allow_methods=["POST", "GET", "OPTIONS"],
    allow_headers=["*"],
)


@app.exception_handler(StarletteHTTPException)
async def http_exception_handler(request, exc):
    return JSONResponse(
        status_code=exc.status_code,
        content=jsonable_encoder({"message": exc.detail}),
    )


@app.exception_handler(RequestValidationError)
async def validation_exception_handler(request, exc):
    return JSONResponse(
        status_code=status.HTTP_422_UNPROCESSABLE_ENTITY,
        content=jsonable_encoder({"message": str(exc)}),
    )


@app.post("/detect_plagiarism", response_model=PlagiarismResponse)
async def detect_plagiarism(file: UploadFile = File(...)):
    with tempfile.TemporaryDirectory() as temp_dir:
        temp_file = os.path.join(temp_dir, file.filename)
        await save_upload_file(file, temp_file)

        file_extension = os.path.splitext(temp_file)[1]

        if file_extension == ".zip":
            extractor = ZipExtractor()
        elif file_extension == ".rar":
            extractor = RarExtractor()
        elif file_extension == ".gz":
            extractor = TarGzExtractor()
        elif file_extension == ".xz":
            extractor = TarXzExtractor()
        elif os.path.isdir(file.filename):
            extractor = FolderExtractor()
        else:
            raise HTTPException(
                status_code=status.HTTP_422_UNPROCESSABLE_ENTITY,
                detail="Unsupported file type",
            )

        extractor.extract(temp_file, temp_dir)

        detector = CodePlagiarismIterator(temp_dir, verbose=False)
        t0 = time.time()
        results = detector.run()
        t1 = time.time()

        results_data = [
            PlagiarismResult(
                file_1=result[0][0].replace(temp_dir, ""),
                file_2=result[0][1].replace(temp_dir, ""),
                similarity=result[1][0],
                plagiarism=result[1][1],
            )
            for result in results
        ]

        response = PlagiarismResponse(
            time_elapsed=t1 - t0,
            total_files=len(
                dict.fromkeys([result[0][0] for result in results])
                | dict.fromkeys([result[0][1] for result in results])
            ),
            total_comparisons=len(results),
            results=results_data,
        )

        return response


@app.get("/")
async def root():
    return {"message": "Hello World"}


if __name__ == "__main__":
    uvicorn.run("main:app", host=HOST, port=PORT)
