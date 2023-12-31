HOST = "0.0.0.0"
PORT = 8000
FILE_NOT_FOUND = "The requested file was not found."

CONFIG = {
    "title": "Code Plagiarism API",
    "description": "API to detect plagiarism in code",
    "version": "1.0.0",
    "contact": {
        "name": "Helmy LuqmanulHakim",
        "url": "https://helmyl.com",
        "email": "helmyl.work@gmail.com",
    },
}

CLIENT_ORIGIN = [
    "http://localhost:8077/",
]

SIMILARITY_THRESHOLD = {
    "Plagiarism": 0.9,
    "Suspicious": 0.4,
    "Not Detected": 0.0,
}
