#include <iostream>
using namespace std;

struct Booking {
    char nama[10][10], tanggal[10][10];
    int jumlah, lama[10], total, menu;
} book;

struct Lapangan {
    char nama[20];
    int hargaPerJam;
};


void header() {
    cout << "==========================" << endl;
    cout << "PROGRAM PENYEWAAN LAPANGAN" << endl;
    cout << "==========================" << endl;
}

int main() {
    const int MAX_LAPANGAN = 4;  // Jumlah lapangan
    Lapangan lapanganList[MAX_LAPANGAN] = {
        {"Lapangan Futsal", 30000},
        {"Lapangan Basket", 25000},
        {"Lapangan Volly", 35000},
        {"Lapangan Badminton", 20000}
    };

    header();
    cout << "Daftar Nama Lapangan:" << endl;
    for (int i = 0; i < MAX_LAPANGAN; i++) {
        cout << i + 1 << ". " << lapanganList[i].nama << " - Harga per jam: " << lapanganList[i].hargaPerJam << endl;
    }

    cout << "Masukkan jumlah pembooking: ";
    cin >> book.jumlah;

    for (int i = 0; i < book.jumlah; i++) {
        cout << endl;
        cout << "Pilih lapangan (1-" << MAX_LAPANGAN << "): ";
        int selectedLapangan;
        cin >> selectedLapangan;
        selectedLapangan--;  // Ubah ke indeks array

        if (selectedLapangan >= 0 && selectedLapangan < MAX_LAPANGAN) {
            cout << "Masukkan nama: ";
            cin >> book.nama[i];
            cout << "Masukkan lama waktu penyewaan (jam):";
            cin >> book.lama[i];
            cout << "Masukkan tanggal penyewaan (dd/mm/yyyy): ";
            cin >> book.tanggal[i];
        } else {
            cout << "Lapangan tidak valid!";
            return 1;  // Keluar dari program jika lapangan tidak valid
        }
    }

    cout << endl;
    header();
    cout << "#1 Lihat daftar pembooking" << endl;
    cout << "#2 Keluar" << endl;
    cout << "Pilih menu: ";
    cin >> book.menu;

    if (book.menu == 1) {
        for (int j = 0; j < book.jumlah; j++) {
            cout << endl;
            cout << "Nama pembooking: " << book.nama[j] << endl;
            cout << "Lama waktu penyewaan: " << book.lama[j] << " jam" << endl;
            cout << "Tanggal sewa: " << book.tanggal[j] << endl;
            book.total = lapanganList[j].hargaPerJam * book.lama[j];
            cout << "Total biaya sewa: " << book.total;
        }
    } else if (book.menu == 2) {
        exit(0);
    } else {
        cout << "Menu tidak ada!";
    }

    return 0;
}