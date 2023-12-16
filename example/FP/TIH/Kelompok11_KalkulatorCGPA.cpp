#include <iostream>
#include <fstream>
using namespace std;

//Kelompok 11 :
// 1. Novita Putri Angellina (23051204252)
// 2. Fakhri Akbar Valley Ramadhani (23051204264)

struct Nilai {
    int Absen;
    int Tugas;
    int PTS;
    int PAS;

void SetNilai(int absen, int tugas, int pts, int pas) {
        Absen = (absen > 100) ? 100 : absen;
        Tugas = (tugas > 100) ? 100 : tugas;
        PTS = (pts > 100) ? 100 : pts;
        PAS = (pas > 100) ? 100 : pas;
    }
};

struct Mahasiswa {
    string Nama;
    string NIM;
    Nilai DataNilai;
};

double HitungRata2 (const Nilai & nilai){
    return (nilai.Absen + nilai.Tugas + nilai.PTS + nilai.PAS) / 4.0;
}

char Penilaian (double HitungRata2){
    if(0<=HitungRata2&&HitungRata2<60){
        return 'E';
    }
    else if (60<=HitungRata2&&HitungRata2<70){
        return 'D';
    }
    else if (70<=HitungRata2&&HitungRata2<80){
        return 'C';
    }
    else if (80<=HitungRata2&&HitungRata2<90){
        return 'B';
    }
    else if (HitungRata2>=90&&HitungRata2<=100){
        return 'A';
    }
    else {
        return 'X';
    }
}

void Simpan (const Mahasiswa& mahasiswa, double rata2, char Penilaian) {
    ofstream file("Data Mahasiswa.txt", ios::app);

    if (file.is_open()) {
        file << "Nama: " << mahasiswa.Nama << endl;
        file << "NIM: " << mahasiswa.NIM << endl;
        if (Penilaian != 'X') {
            file << "Rata-rata nilai: " << rata2 << endl;
            file << "Grade: " << Penilaian << endl << endl;
            cout << "Data telah disimpan." << endl;
        } else {
            file << "Nilai tidak valid" << endl << endl;
        }
        file.close();
    } else {
        cout << "Gagal membuka file untuk disimpan." << endl;
    }
}


int main() {
    Mahasiswa mahasiswa;
    Nilai dataNilai;
    dataNilai.SetNilai(90, 110, 80, 95);

    cout << "Masukkan Nama: ";
    getline(cin, mahasiswa.Nama);

    cout << "Masukkan NIM: ";
    getline(cin, mahasiswa.NIM);

    cout << "Masukkan nilai Absen: ";
    cin >> mahasiswa.DataNilai.Absen;

    cout << "Masukkan nilai Tugas: ";
    cin >> mahasiswa.DataNilai.Tugas;

    cout << "Masukkan nilai PTS: ";
    cin >> mahasiswa.DataNilai.PTS;

    cout << "Masukkan nilai PAS: ";
    cin >> mahasiswa.DataNilai.PAS;

    double rata2 = HitungRata2(mahasiswa.DataNilai);
    char grade = Penilaian(rata2);

    cout << "Rata-rata Nilai: " << rata2 << endl;
    
    if (grade != 'X') {
        cout << "Grade: " << grade << endl;
    } else {
        cout << "Nilai tidak valid." << endl;
    }

    Simpan(mahasiswa, rata2, grade);

    return 0;
}