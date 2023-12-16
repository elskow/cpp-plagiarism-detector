#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Tipekamar {
    string nama;
    double hargaPermalam;
};

struct Pelanggan {
    string nama;
    string email;
};

int main() {
    vector<Tipekamar> tipekamar = {{"Bronze", 100.0},
                                  {"Silver", 150.0},
                                  {"Gold", 200.0},
                                  {"Platinum", 250.0},
                                  {"Diamond", 300.0},
                                  {"Master", 400.0}};

    cout << "=== Pemesanan Kamar Hotel ===" << endl;
    cout << "Pilih jenis kamar yang diinginkan:" << endl;
    for (size_t i = 0; i < tipekamar.size(); ++i) {
        cout << i + 1 << ". " << tipekamar[i].nama << " - Rp" << fixed << setprecision(3) << tipekamar[i].hargaPermalam << " per malam" << endl;
    }

    int Pilihankamar;
    cout << "Masukkan nomor jenis kamar: ";
    cin >> Pilihankamar;

    if (Pilihankamar > 0 && Pilihankamar <= tipekamar.size()) {
        int durasi;
        cout << "Masukkan durasi menginap (jumlah malam): ";
        cin >> durasi;

        double totalbiaya = tipekamar[Pilihankamar - 1].hargaPermalam * durasi;

        Pelanggan Pelangganbaru;
        cout << "Masukkan nama pelanggan: ";
        cin.ignore();
        getline(cin, Pelangganbaru.nama);
        cout << "Masukkan email pelanggan: ";
        cin >> Pelangganbaru.email;

        cout << "\n============================================" << endl;
        cout << "           Tiket Pemesanan Hotel         " << endl;
        cout << "============================================" << endl;
        cout << "Nama Kamar            : " << tipekamar[Pilihankamar - 1].nama << endl;
        cout << "Durasi Menginap       : " << durasi << " malam" << endl;
        cout << "Biaya Kamar           : Rp" << fixed << setprecision(3) << tipekamar[Pilihankamar - 1].hargaPermalam << " per malam" << endl;
        cout << "Total Biaya Pemesanan : Rp" << fixed << setprecision(3) << totalbiaya << endl;
        cout << "Nama Pelanggan        : " << Pelangganbaru.nama << endl;
        cout << "Email Pelanggan       : " << Pelangganbaru.email << endl;
        cout << "============================================" << endl;
        cout << "Terima kasih atas pemesanan Anda! Selamat menikmati penginapan di hotel kami." << endl;
        cout << "============================================" << endl;
    } else {
        cout << "Nomor jenis kamar tidak valid. Pemesanan dibatalkan." << endl;
    }

    return 0;
}
