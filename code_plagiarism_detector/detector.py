import re
import hashlib
from nltk.corpus import stopwords
from nltk.stem import PorterStemmer, WordNetLemmatizer
from nltk.util import ngrams
from pygments import lex
from pygments.lexers import get_lexer_by_name
from difflib import SequenceMatcher


class CodePlagiarismDetector:
    def __init__(self, file_path_1: str, file_path_2: str, verbose: bool = False):
        try:
            with open(file_path_1, "r", encoding="utf-8") as file:
                self.source_code_1 = file.read()
        except UnicodeDecodeError:
            print(f"Skipping file {file_path_1} as it's not utf-8 encoded")
            self.source_code_1 = ""

        try:
            with open(file_path_2, "r", encoding="utf-8") as file:
                self.source_code_2 = file.read()
        except UnicodeDecodeError:
            print(f"Skipping file {file_path_2} as it's not utf-8 encoded")
            self.source_code_2 = ""

        self.verbose = verbose

    def _preprocess(self, source_code: str) -> list:
        source_code = self._remove_comments_and_namespaces(source_code)
        tokens = self._get_tokens(source_code)
        tokens = self._normalize_tokens(tokens)
        fingerprints = self._generate_fingerprints(tokens)
        return fingerprints

    @staticmethod
    def _remove_comments_and_namespaces(source_code: str) -> str:
        source_code = re.sub(r"#.*?\n", "", source_code)
        source_code = re.sub(r"using namespace std;", "", source_code)
        return source_code

    def _get_tokens(self, source_code: str) -> list:
        lexer = get_lexer_by_name("c++")
        tokens = list(lex(source_code, lexer))
        tokens = [
            token[1]
            for token in tokens
            if not str(token[0]).startswith(
                ("Token.Punctuation", "Token.Text", "Token.Comment")
            )
        ]
        return tokens

    @staticmethod
    def _normalize_tokens(tokens: list) -> list:
        stop_words = set(stopwords.words("english")).union(
            stopwords.words("indonesian")
        )
        stemmer = PorterStemmer()
        lemmatizer = WordNetLemmatizer()
        tokens = [
            lemmatizer.lemmatize(stemmer.stem(token))
            for token in tokens
            if token not in stop_words
        ]
        return tokens

    @staticmethod
    def _generate_fingerprints(tokens: list) -> list:
        tokens = list(ngrams(tokens, 2))
        common_keywords = ["int", "float", "if", "else", "for", "while"]
        fingerprints = [
            hashlib.md5(" ".join(token).encode()).hexdigest()
            for token in tokens
            if token not in common_keywords
        ]
        return fingerprints

    def _get_similarity(self) -> float:
        fingerprints_1 = self._preprocess(self.source_code_1)
        fingerprints_2 = self._preprocess(self.source_code_2)

        # Use the SequenceMatcher to compare the two sets of fingerprints
        seq_matcher = SequenceMatcher(None, fingerprints_1, fingerprints_2)
        similarity = seq_matcher.ratio()

        return similarity

    @staticmethod
    def _get_plagiarism(similarity: float) -> str:
        if similarity >= 0.9:
            return "Plagiarism detected"
        elif similarity >= 0.8:
            return "Suspicious"
        else:
            return "Plagiarism not detected"

    def run(self) -> tuple:
        similarity = self._get_similarity()
        plagiarism = self._get_plagiarism(similarity)

        if self.verbose:
            print(f"Similarity: {similarity}")
            print(f"Plagiarism: {plagiarism}")

        return similarity, plagiarism


if __name__ == "__main__":
    detector = CodePlagiarismDetector(
        "./example/same_1.cpp", "./example/same_2.cpp", verbose=False
    )
    print(detector.run())
