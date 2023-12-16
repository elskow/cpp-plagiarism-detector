#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
- UAS Pemrograman Dasar
- Teknik Informatika, Kelas H, Kelompok 3
- Tema : Sistem Pencetak KTM, dengan protokol user login
- Anggota Kelompok :
1. Afif Nouval Adani, NIM : 23051204254
2. Garin Agil Priambodo, NIM : 23051204260
3. Hildan Abiansyah, NIM : 23051204270
*/

struct Mahasiswa
{
    string nama;
    string nim;
    string prodi;
    string fakultas;
};

void menu(){
    int input;
    Mahasiswa mahasiswa;
    int ktmcount = 0;
    do
    {
        cout << "\tHALAMAN SIADADU" << endl;
        cout << "===========================" << endl;
        cout << "1. Pembuatan KTM" << endl;
        cout << "2. Pencetakan KTM" << endl;
        cout << "3. Exit" << endl;
        cout << "masukan pilihan menu : ";cin >> input;

        if (input == 1)
        {
            cout << "Masukkan nama mahasiswa: ";
            cin.ignore();
            getline(cin, mahasiswa.nama);

            cout << "Masukkan NIM mahasiswa: ";
            getline(cin, mahasiswa.nim);

            cout << "Masukkan prodi mahasiswa: ";
            getline(cin, mahasiswa.prodi);

            cout << "Masukkan fakultas mahasiswa: ";
            getline(cin, mahasiswa.fakultas);
            ktmcount++; 
        }
        else if (input == 2)
        {
            if (ktmcount > 0)  
            {
                ofstream file("data_mahasiswa.txt", ios::app);
                if (file.is_open())
                {
                    file << "========================================" << endl;
                    file << "\t   KARTU TANDA MAHASISWA             " << endl;
                    file << "\tUNIVERSITAS NEGERI SURABAYA          " << endl;
                    file << "========================================" << endl;
                    file << " Nama       : " << mahasiswa.nama <<"  " << endl;
                    file << " NIM        : " << mahasiswa.nim << "  " << endl;
                    file << " Prodi      : " << mahasiswa.prodi<<"  " << endl;
                    file << " Fakultas   : "<<mahasiswa.fakultas<<" " << endl;
                    file << "                                       " << endl;
                    file << "========================================" << endl;
                    cout << "Data mahasiswa telah ditambahkan ke dalam file." << endl;
                    file.close();
                }
                else
                {
                    cout << "Gagal membuka file." << endl;
                }
            }
            else
            {
                cout << "Silakan input data mahasiswa terlebih dahulu." << endl;
            }
        }
    } while (input != 3);
    
}

int main() {
    string LGB, username, uname, password, pass;

    int a = 1;
    cout << "\tHALAMAN REGISTRASI" << endl;

    cout << "Perhatian, username berisikan nama singkat pengguna," << endl;
    cout << "dan password berisikan NIM mahasiswa" << endl;
    cout << "username : ";
    getline(cin, username);
    cout << "password : ";
    getline(cin, password);
    system("cls");
    do {
        cout << "\tHALAMAN LOGIN" << endl;
        cout << "=========================================================" << endl;
        cout << "Silahkan masukan username dan password yang telah dibuat," << endl;
        cout << "dan password berisikan NIM mahasiswa" << endl;
        cout << "username : ";
        getline(cin, uname);
        cout << "password : ";
        getline(cin, pass);
        if (username == uname && password == pass) {
            LGB = "berhasil";
            a += 3;
        } else {
            cout << "Username atau password anda salah" << endl;
            a++;
        }
    } while (a <= 3);
    if (LGB == "berhasil") {
        menu();
    } else {
        cout << "anda telah salah 3 kali, anda diblokir";
    }
    return 0;
}