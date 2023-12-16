//created by:
//M. Eddo Almero (23051204253)
//Dian Qurrota A'yun (23051204278)
//Satria Nugroho Putra (23051204281)

//FYI : username : samlong | password : jfluxury

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Transaksi {
    string tanggal;
    string kategori;
    double jumlah;
    string keterangan;
};

struct Akun {
    string username;
    string password;
    double saldo;
};

bool cekLogin(const string& username, const string& password) {
    return (username == "samlong" && password == "jfluxury");
}

void tampilkanMenuUtama(Akun& akun) {
    cout << "\n=== Menu Utama ===\n";
    cout << "1. Informasi Saldo\n";
    cout << "2. Buat Transaksi\n";
    cout << "3. Histori Transaksi\n";
    cout << "4. Log Out\n";
    cout << "Pilihan Anda: ";
}

void tampilkanInformasiSaldo(Akun& akun) {
    cout << "\nInformasi Saldo:\n";
    cout << "Username: " << akun.username << "\n";
    cout << "Saldo: Rp. " << fixed << akun.saldo << "\n";
}


void buatPemasukan(Akun& akun, ofstream& historiFile) {
    Transaksi transaksi;

    cout << "\n=== Menu Pemasukan ===\n";
    cout << "Masukkan Tanggal (DD/MM/YYYY): ";
    cin >> transaksi.tanggal;
    cout << "Masukkan Kategori: ";
    cin >> transaksi.kategori;
    cout << "Masukkan Jumlah Pemasukan: Rp. ";
    cin >> transaksi.jumlah;
    cout << "Masukkan Keterangan: ";
    cin.ignore();
    getline(cin, transaksi.keterangan);

    akun.saldo += transaksi.jumlah;

    historiFile << "Pemasukan|" << transaksi.tanggal << "|" << transaksi.kategori << "|"
                << transaksi.jumlah << "|" << transaksi.keterangan << "\n";

    cout << "Pemasukan berhasil!\n";
}

void buatPengeluaran(Akun& akun, ofstream& historiFile) {
    Transaksi transaksi;

    cout << "\n=== Menu Pengeluaran ===\n";
    cout << "Masukkan Tanggal (DD/MM/YYYY): ";
    cin >> transaksi.tanggal;
    cout << "Masukkan Kategori: ";
    cin >> transaksi.kategori;

    do {
        cout << "Masukkan Jumlah Pengeluaran: Rp. ";
        cin >> transaksi.jumlah;

        if (transaksi.jumlah > akun.saldo) {
            cout << "Saldo tidak mencukupi. Ulangi input.\n";
        }

    } while (transaksi.jumlah > akun.saldo);

    cout << "Masukkan Keterangan: ";
    cin.ignore();
    getline(cin, transaksi.keterangan);

    akun.saldo -= transaksi.jumlah;

    historiFile << "Pengeluaran|" << transaksi.tanggal << "|" << transaksi.kategori << "|"
                << transaksi.jumlah << "|" << transaksi.keterangan << "\n";

    cout << "Pengeluaran berhasil!\n";
}

void tampilkanHistoriTransaksi(const string& historiFileName) {
    ifstream historiFile(historiFileName);

    if (!historiFile.is_open()) {
        cout << "File histori tidak ditemukan.\n";
        return;
    }

    cout << "\n=== Histori Transaksi ===\n";
    string line;
    while (getline(historiFile, line)) {
        cout << line << "\n";
    }

    historiFile.close();
}

void bacaSaldo(Akun& akun, const string& saldoFileName) {
    ifstream saldoFile(saldoFileName);

    if (saldoFile.is_open()) {
        saldoFile >> akun.saldo;
        saldoFile.close();
    }
}

void simpanSaldo(const Akun& akun, const string& saldoFileName) {
    ofstream saldoFile(saldoFileName);

    if (saldoFile.is_open()) {
        saldoFile << akun.saldo;
        saldoFile.close();
    }
}

int main() {
    Akun akun;
    string username, password;
    string historiFileName = "histori_transaksi.txt";
    string saldoFileName = "saldo.txt";

    bacaSaldo(akun, saldoFileName);

    cout << "Masukkan username: ";
    cin >> username;

    cout << "Masukkan password: ";
    cin >> password;

    if (cekLogin(username, password)) {
        akun.username = username;
        akun.password = password;

        cout << "\nSelamat Datang, " << username << "!\n";

        int pilihan;
        do {
            tampilkanMenuUtama(akun);
            cin >> pilihan;

            ofstream historiFile(historiFileName, ios::app);

            switch (pilihan) {
                case 1:
                    tampilkanInformasiSaldo(akun);
                    break;
                case 2:
                    int subPilihan;
                    cout << "\n=== Menu Buat Transaksi ===\n";
                    cout << "1. Pemasukan\n";
                    cout << "2. Pengeluaran\n";
                    cout << "3. Kembali\n";
                    cout << "Pilihan Anda: ";
                    cin >> subPilihan;

                    switch (subPilihan) {
                        case 1:
                            buatPemasukan(akun, historiFile);
                            break;
                        case 2:
                            buatPengeluaran(akun, historiFile);
                            break;
                        case 3:
                            cout << "Kembali ke Menu Utama.\n";
                            break;
                        default:
                            cout << "Pilihan tidak valid.\n";
                    }

                    break;
                case 3:
                    tampilkanHistoriTransaksi(historiFileName);
                    break;
                case 4:
                    cout << "Log Out.\n";
                    break;
                default:
                    cout << "Pilihan tidak valid.\n";
            }

            simpanSaldo(akun, saldoFileName);

            historiFile.close();
        } while (pilihan != 4);
    } else {
        cout << "\nLogin gagal. Coba lagi.\n";
    }

    return 0;
}





// The - End //