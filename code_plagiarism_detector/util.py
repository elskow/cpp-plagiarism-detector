from fastapi import UploadFile, HTTPException
import aiofiles


async def save_upload_file(upload_file: UploadFile, destination: str):
    try:
        async with aiofiles.open(destination, "wb") as out_file:
            content = await upload_file.read()
            await out_file.write(content)
    except Exception as e:
        raise HTTPException(status_code=500, detail=str(e))
