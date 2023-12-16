import os
from itertools import combinations
from multiprocessing import Pool
from detector import CodePlagiarismDetector


class CodePlagiarismIterator:
    """
    This class iterates through all the files in a folder and compares them
    """

    def __init__(self, folder_path: str, verbose: bool = False):
        self.folder_path = folder_path
        self.verbose = verbose

    def _compare_files(self, files):
        file_1, file_2 = files
        detector = CodePlagiarismDetector(file_1, file_2, self.verbose)
        similarity, plagiarism = detector.run()
        return (file_1, file_2), (similarity, plagiarism)

    def run(self):
        files = []
        for dirpath, dirnames, filenames in os.walk(self.folder_path):
            for filename in filenames:
                if filename.endswith(".cpp") or filename.endswith(".c"):
                    files.append(os.path.join(dirpath, filename))

        if len(files) < 2:
            raise ValueError(
                "There must be at least two .cpp or .c files in the directory."
            )

        with Pool() as p:
            plagiarism_results = p.map(self._compare_files, combinations(files, 2))

        plagiarism_results = {k: v for k, v in plagiarism_results}

        plagiarism_results = sorted(
            plagiarism_results.items(), key=lambda x: x[1][0], reverse=True
        )

        return plagiarism_results


if __name__ == "__main__":
    import pprint

    detector = CodePlagiarismIterator("./../example/FP", verbose=False)
    plagiarism_results = detector.run()
    pprint.pprint(plagiarism_results)
