import tarfile
import zipfile
import rarfile
import shutil


class Extractor:
    def extract(self, file, destination):
        raise NotImplementedError


class ZipExtractor(Extractor):
    def extract(self, file, destination):
        with zipfile.ZipFile(file, "r") as zip_ref:
            zip_ref.extractall(destination)


class RarExtractor(Extractor):
    def extract(self, file, destination):
        with rarfile.RarFile(file, "r") as rar_ref:
            rar_ref.extractall(destination)


class TarGzExtractor(Extractor):
    def extract(self, file, destination):
        with tarfile.open(file, "r:gz") as tar_ref:
            tar_ref.extractall(destination)


class TarXzExtractor(Extractor):
    def extract(self, file, destination):
        with tarfile.open(file, "r:xz") as tar_ref:
            tar_ref.extractall(destination)


class FolderExtractor(Extractor):
    def extract(self, file, destination):
        shutil.copytree(file, destination)
