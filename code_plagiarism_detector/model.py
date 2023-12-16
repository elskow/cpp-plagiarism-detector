from pydantic import BaseModel
from typing import List


class PlagiarismResult(BaseModel):
    file_1: str
    file_2: str
    similarity: float
    plagiarism: str


class PlagiarismResponse(BaseModel):
    time_elapsed: float
    total_files: int
    total_comparisons: int
    results: List[PlagiarismResult]
