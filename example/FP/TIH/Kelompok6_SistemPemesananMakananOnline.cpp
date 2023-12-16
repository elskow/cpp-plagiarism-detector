#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Makanan {
    string nama;
    float harga;
};
 
int main() {
    vector<Makanan> daftar_makanan = {
        {"Bakso", 10000},
        {"Mie Ayam", 12000},
        {"Nasi Goreng", 8000},
        {"Ayam Geprek", 10000},
        {"Nasi Pecel", 7000},
        {"Nasi Katsu", 10000},
        {"Batagor", 8000},
        {"Gado Gado", 10000},
    };

    vector<pair<string, int>> keranjang_belanja;
    int nomor_makanan;
    int jumlah_pesanan;
    float total = 0;
    string nama, alamat;

    cout << "================ Rumah Makan Google ================" << endl;
    cout << "== Jl. Raya Arjuno no. 35, Kec. Sawahan, Surabaya ==" << endl;
    cout << "----------------------------------------------------\n" << endl;
    cout << "Masukkan Nama Pemesan\t: " << nama; getline(cin, nama);
    cout << "Masukkan Alamat Anda\t: " << alamat; getline (cin, alamat);
    cout << "\n===================================================" << endl;
    cout << "Menu Makanan yang Tersedia: " << endl;
    cout << "-------------------------------------------" << endl;
    cout << "No.   Nama Makanan          Harga" << endl;
    cout << "-------------------------------------------" << endl;
    for (int i = 0; i < daftar_makanan.size(); ++i) {
        cout << i + 1 << ".    " << daftar_makanan[i].nama;
        for (int j = 0; j < 20 - daftar_makanan[i].nama.length(); ++j)
            cout << " ";
        cout << "Rp " << daftar_makanan[i].harga << endl;
    }
    cout << "-------------------------------------------" << endl;
    cout << "•Masukkan nomor makanan yang ingin dipesan" << endl;
    cout << "•Ketik y jika ingin memesan lagi\n•Ketik n jika Tidak" << endl;
    cout << "\nMasukkan pesanan anda" << endl;

    char beli_lagi = 'y';
    while (beli_lagi == 'y' || beli_lagi == 'Y') {
        cout << "-No\t\t: ";
        cin >> nomor_makanan;

        if (nomor_makanan < 1 || nomor_makanan > daftar_makanan.size()) {
            cout << "Nomor makanan tidak valid." << endl;
        } else {
            cout << "-Jumlah pesanan\t: ";
            cin >> jumlah_pesanan;

            Makanan makanan_dipesan = daftar_makanan[nomor_makanan - 1];
            total += makanan_dipesan.harga * jumlah_pesanan;

            bool makanan_ditemukan = false;
            for (auto &item : keranjang_belanja) {
                if (item.first == makanan_dipesan.nama) {
                    item.second += jumlah_pesanan;
                    makanan_ditemukan = true;
                    break;
                }
            }
            if (!makanan_ditemukan) {
                keranjang_belanja.push_back({makanan_dipesan.nama, jumlah_pesanan});
            }
        }

        cout << "\nPesan lagi?: ";
        cin >> beli_lagi;
    }

    if (keranjang_belanja.empty()) {
        cout << "Anda belum memesan makanan.\n";
    } else {
        cout << "\n\n====================" << endl;
        cout << "|-Pesanan Berhasil-|" << endl;
        cout << "====================\n" << endl;
        cout << "Nama Pemesan\t: "<< nama <<endl;
        cout << "Alamat Pemesan\t: "<< alamat <<endl;
        cout << "Pesanan Anda\t:" << endl;
        cout << "-------------------------------------------" << endl;
        cout << "Nama Makanan          Jumlah      Harga" << endl;
        cout << "-------------------------------------------" << endl;
        for (const auto &item : keranjang_belanja) {
            cout << item.first;
            for (int i = 0; i < 20 - item.first.length(); ++i)
                cout << " ";
            cout << "x " << item.second;
            for (int i = 0; i < 10; ++i)
                cout << " ";
            float harga_item = 0;
            for (const auto &makanan : daftar_makanan) {
                if (makanan.nama == item.first) {
                    harga_item = makanan.harga * item.second;
                    break;
                }
            }
            cout << "Rp " << harga_item << endl;
        }
        cout << "-------------------------------------------" << endl;
        float total_harga = 0;
        for (const auto &item : keranjang_belanja) {
            for (const auto &makanan : daftar_makanan) {
                if (makanan.nama == item.first) {
                    total_harga += makanan.harga * item.second;
                    break;
                }
            }
        }
        cout << "Total Harga         Rp " << total_harga << endl;
        cout << "-------------------------------------------" << endl;
        cout << "MAKANAN ANDA AKAN SEGERA DIANTAR!" <<endl;
    }

    return 0;
}
