#include <iostream>
#include <string>

using namespace std;

// Mendeklarasikan struktur data barang
struct Barang {
  string nama;
  int harga;
};

// Mendeklarasikan array barang
Barang barang[100];

// Mendeklarasikan variabel global
int jumlah_barang;
int total_belanja;
int uang_bayar;

// Fungsi untuk memasukkan data barang
void input_data() {
  // Membaca jumlah barang
  cout << "Masukkan jumlah barang: ";
  cin >> jumlah_barang;

  // Memasukkan data barang
  for (int i = 0; i < jumlah_barang; i++) {
    cout << "Masukkan nama barang ke-" << i + 1 << " : ";
    cin >> barang[i].nama;
    cout << "Masukkan harga barang ke-" << i + 1 << " : ";
    cin >> barang[i].harga;
  }
}

// Fungsi untuk menghitung total belanja
void hitung_total() {
  // Menginisialisasi total belanja
  total_belanja = 0;

  // Menghitung total belanja
  for (int i = 0; i < jumlah_barang; i++) {
    total_belanja += barang[i].harga;
  }
}

// Fungsi untuk menampilkan daftar barang dan total belanja
void cetak_data() {
  // Menampilkan daftar barang
  cout << "Daftar barang:" << endl;
  for (int i = 0; i < jumlah_barang; i++) {
    cout << "Nama barang: " << barang[i].nama << endl;
    cout << "Harga barang: " << barang[i].harga << endl;
    cout << endl;
  }

  // Menampilkan total belanja
  cout << "Total belanja: " << total_belanja << endl;
}

// Fungsi untuk menerima pembayaran
void terima_pembayaran() {
  // Membaca uang bayar
  cout << "Masukkan uang bayar: ";
  cin >> uang_bayar;
}

// Fungsi untuk menghitung kembalian
void hitung_kembalian() {
  // Menginisialisasi kembalian
  int kembalian = 0;

  // Menghitung kembalian
  kembalian = uang_bayar - total_belanja;

  // Menampilkan kembalian
  cout << "Kembalian: " << kembalian << endl;
}

int main() {
  // Menjalankan fungsi input data
  input_data();

  // Menjalankan fungsi hitung total
  hitung_total();

  // Menjalankan fungsi cetak data
  cetak_data();

  // Menjalankan fungsi terima pembayaran
  terima_pembayaran();

  // Menjalankan fungsi hitung kembalian
  hitung_kembalian();

  // Mengakhiri program
  return 0;
}
