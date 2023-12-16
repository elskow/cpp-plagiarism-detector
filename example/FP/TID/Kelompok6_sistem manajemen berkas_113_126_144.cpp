#include <iostream>
#include <string>

using namespace std;

// Struktur untuk menyimpan informasi berkas
struct File {
    int berkas;
    string kategori;
    string nama;
    string nama_penulis;
    string tanggal;
};

const int MAX_FILES = 100; // Jumlah maksimum berkas yang dapat disimpan

// Fungsi untuk menambahkan berkas ke dalam array
void addFile(File files[], int& fileCount) {
    if (fileCount < MAX_FILES) {
        File newFile;
        cin.ignore(); // Membersihkan newline dari input sebelumnya
        cout << "Masukkan kategori berkas: ";
        getline(cin, newFile.kategori);
        cout << "Masukkan nama berkas: ";
        getline(cin, newFile.nama);
        cout << "Masukkan nama penulis berkas: ";
        getline(cin, newFile.nama_penulis);
        cout << "Masukkan tanggal berkas (format: dd/mm/yyyy): ";
        getline(cin, newFile.tanggal);

        files[fileCount] = newFile;
        fileCount++;

        cout << "Berkas berhasil ditambahkan.\n";
    } else {
        cout << "Maaf, sudah mencapai batas maksimum berkas.\n";
    }
}

// Fungsi untuk mencari berkas berdasarkan kriteria
void searchFiles(const File files[], int fileCount, const string& searchTerm, int searchCode = -1) {
    bool found = false;

    cout << "Hasil pencarian:\n";
    for (int i = 0; i < fileCount; ++i) {
        if ((searchTerm.empty() || files[i].nama.find(searchTerm) != string::npos ||
            files[i].nama_penulis.find(searchTerm) != string::npos || files[i].tanggal.find(searchTerm) != string::npos)) {
            found = true;
            cout << "Kategori: " << files[i].kategori << "\n";
            cout << "Nama: " << files[i].nama << "\n";
            cout << "Penulis: " << files[i].nama_penulis << "\n";
            cout << "Tanggal: " << files[i].tanggal << "\n\n";
        }
    }

    if (!found) {
        cout << "Tidak ditemukan berkas sesuai kriteria pencarian.\n";
    }
}

// Fungsi untuk menghapus berkas berdasarkan kode berkas
void deleteFile(File files[], int& fileCount, const string& deleteName) {
    bool found = false;
    int index = -1;

    // Mencari indeks berkas yang memiliki nama yang sama dengan deleteName
    for (int i = 0; i < fileCount; ++i) {
        if (files[i].nama == deleteName) {
            found = true;
            index = i;
            break;
        }
    }

    if (found) {
        // Menggeser elemen array ke kiri mulai dari indeks yang ditemukan
        for (int i = index; i < fileCount - 1; ++i) {
            files[i] = files[i + 1];
        }
        // Mengurangi jumlah berkas yang tersimpan
        fileCount--;
        cout << "Berkas berhasil dihapus.\n";
    } else {
        cout << "Berkas tidak ditemukan.\n";
    }
}

int main() {
    File files[MAX_FILES]; // Array untuk menyimpan berkas
    int fileCount = 0;     // Jumlah berkas yang sudah disimpan

    int choice;
    do {
        cout << "=== Program Manajemen Berkas ===\n";
        cout << "1. Tambah Berkas\n";
        cout << "2. Cari Berkas\n";
        cout << "3. Hapus Berkas\n";
        cout << "4. Keluar\n";
        cout << "Pilihan: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addFile(files, fileCount);
                break;
            case 2: {
                string searchTerm;
                cout << "Masukkan kata kunci pencarian (Nama, Penulis, atau Tanggal): ";
                cin.ignore(); // Membersihkan newline dari input sebelumnya
                getline(cin, searchTerm);
                searchFiles(files, fileCount, searchTerm);
                break;
            }
            case 3: {
                string deleteName; // Mengubah tipe data menjadi string
                cout << "Masukkan nama berkas yang akan dihapus: "; // Mengubah pesan menjadi nama berkas
                cin.ignore(); // Membersihkan newline dari input sebelumnya
                getline(cin, deleteName);
                deleteFile(files, fileCount, deleteName); // Mengubah argumen menjadi deleteName
                break;
            }
            case 4:
                cout << "Terima kasih! Program berakhir";
                break;
            default :
                cout << "Pilihan tidak valid";
            
            
        }

    } while (choice != 4);

    return 0;
}