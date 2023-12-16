#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;
struct akun{
    char username[15];
    char usernamed[15];
    char pw[15];
    char pwd[15];
};
struct mahasiswa{
    char nama[50];
    float presentase;
    int hadir = 0;
};
int main(){
    int minggu;
    int nim;
    int nu;
    int n = 133;
    char absen;
    char alasan[100];
    akun dosen;
    mahasiswa mhs[n];
    strcpy(mhs[100].nama,"Abdi");
    strcpy(mhs[101].nama,"Bagus");
    strcpy(mhs[102].nama,"Caca");
    strcpy(mhs[103].nama,"Dani");
    strcpy(mhs[104].nama,"Eva");
    strcpy(mhs[105].nama,"Fani");
    strcpy(mhs[106].nama,"Gani");
    strcpy(mhs[107].nama,"Hani");
    strcpy(mhs[108].nama,"Ina");
    strcpy(mhs[109].nama,"Jayat");
    strcpy(mhs[110].nama,"Kofad");
    strcpy(mhs[111].nama,"Lana");
    strcpy(mhs[112].nama,"Maulani");
    strcpy(mhs[113].nama,"Nava");
    strcpy(mhs[114].nama,"Opang");
    strcpy(mhs[115].nama,"Prasetyo");
    strcpy(mhs[116].nama,"Qomariya");
    strcpy(mhs[117].nama,"Rafli");
    strcpy(mhs[118].nama,"Sandi");
    strcpy(mhs[119].nama,"Toni");
    strcpy(mhs[120].nama,"Ucup");
    strcpy(mhs[121].nama,"Vania");
    strcpy(mhs[122].nama,"Winda");
    strcpy(mhs[123].nama,"Xavier");
    strcpy(mhs[124].nama,"Yusuf");
    strcpy(mhs[125].nama,"Zaidan");
    strcpy(mhs[126].nama,"Aldean");
    strcpy(mhs[127].nama,"Zee");
    strcpy(mhs[128].nama,"Azis");
    strcpy(mhs[129].nama,"Nafila");
    strcpy(mhs[130].nama,"Anin");
    strcpy(mhs[131].nama,"Adel");
    strcpy(mhs[132].nama,"Arif");
    strcpy(mhs[133].nama,"Rafly");
    cout << " Masukkan nomor urut dosen anda berdasarkan jadwal mata kuliah : ";
    cin >> nu;
    if (nu == 1){
        strcpy(dosen.usernamed, "ervin");
        strcpy(dosen.pwd, "ervin123");
        cout << " Masukkan username anda : ";
        cin >> dosen.username;
        if(strcmp(dosen.username,dosen.usernamed) == 0){
            cout << " Masukkan password anda : ";
            cin >> dosen.pw;
            if(strcmp(dosen.pw,dosen.pwd) == 0){
                system("cls");
                cout << "== Rekap absensi kehadiran mahasiswa mata kuliah Aljabar Linear ==" << endl;
                for(int i = 100; i <= n; i++){
                cout << " Absensi mahasiswa " << endl;
                minggu = 14;
                for (int j = 1; j <= minggu; j++){
                    cout << " Absensi minggu ke " << j << endl;
                    cout << " Mahasiswa dengan NIM " << i << endl;
                    cout << " Nama \t: " << mhs[i].nama << endl; 
                    cout << " Kehadiran (h/a/i/s)\t: ";
                    cin >> absen;
                    if(absen == 'h' || absen == 'H'){
                        mhs[i].hadir += 1;
                        cout << " Mahasiswa hadir " << endl;
                        mhs[i].presentase = (mhs[i].hadir*100)/14;
                        cout << " Presentase kehadiran : " << mhs[i].presentase << "%" <<endl;
                        cout << endl;
                    }
                    if (absen == 'a' || absen == 'A'){
                        mhs[i].hadir += 0;
                        cout << " Mahasiswa tidak hadir tanpa keterangan" << endl;
                        mhs[i].presentase = (mhs[i].hadir*100)/14;
                        cout << " Presentase kehadiran : " << mhs[i].presentase << "%" <<endl;
                        cout << endl;
                    }
                    if (absen == 'i' || absen == 'I'){
                        mhs[i].hadir += 0;
                        cout << " Mahasiswa izin dengan alasan ";
                        cin.ignore();
                        cin.getline(alasan,100);
                        mhs[i].presentase = (mhs[i].hadir*100)/14;
                        cout << " Presentase kehadiran : " << mhs[i].presentase << "%" <<endl;
                        cout << endl;
                    }
                    if (absen == 's' || absen == 'S'){
                        mhs[i].hadir += 0;
                        cout << " Mahasiswa sakit " << endl;
                        mhs[i].presentase = (mhs[i].hadir*100)/14;
                        cout << " Presentase kehadiran : " << mhs[i].presentase << "%" <<endl;
                        cout << endl;
                    }
                }
                if(mhs[i].presentase < 60 ){
                    cout << " Siswa dengan NIM " << i << " tidak bisa mengikuti UAS mata kuliah Aljabar Linear" << endl << endl << endl;;
                } else{
                    cout << " Siswa dengan NIM " << i << " bisa mengikuti UAS mata kuliah Aljabar Linear" << endl << endl << endl;
                }
            }
            }else{
                cout << " Password anda salah !" << endl;
            }
            
        } else {
            cout << " Username anda salah !" << endl;
        }
    }
    if (nu == 2){
        strcpy(dosen.usernamed, "adit");
        strcpy(dosen.pwd, "adit123");
        cout << " Masukkan username anda : ";
        cin >> dosen.username;
        if(strcmp(dosen.username,dosen.usernamed) == 0){
            cout << " Masukkan password anda : ";
            cin >> dosen.pw;
            if(strcmp(dosen.pw,dosen.pwd) == 0){
                system("cls");
                cout << "== Rekap absensi kehadiran mahasiswa mata kuliah Arsitektur dan Organisasi Komputer ==" << endl;
                for(int i = 100; i <= n; i++){
                cout << " Absensi mahasiswa " << endl;
                minggu = 14;
                for (int j = 1; j <= minggu; j++){
                    cout << " Absensi minggu ke " << j << endl;
                    cout << " Mahasiswa dengan NIM " << i << endl;
                    cout << " Nama \t: " << mhs[i].nama << endl; 
                    cout << " Kehadiran (h/a/i/s)\t: ";
                    cin >> absen;
                    if(absen == 'h' || absen == 'H'){
                        mhs[i].hadir += 1;
                        cout << " Mahasiswa hadir " << endl;
                        mhs[i].presentase = (mhs[i].hadir*100)/14;
                        cout << " Presentase kehadiran : " << mhs[i].presentase << "%" <<endl;
                        cout << endl;
                    }
                    if (absen == 'a' || absen == 'A'){
                        mhs[i].hadir += 0;
                        cout << " Mahasiswa tidak hadir tanpa keterangan" << endl;
                        mhs[i].presentase = (mhs[i].hadir*100)/14;
                        cout << " Presentase kehadiran : " << mhs[i].presentase << "%" <<endl;
                        cout << endl;
                    }
                    if (absen == 'i' || absen == 'I'){
                        mhs[i].hadir += 0;
                        cout << " Mahasiswa izin dengan alasan ";
                        cin.ignore();
                        cin.getline(alasan,100);
                        mhs[i].presentase = (mhs[i].hadir*100)/14;
                        cout << " Presentase kehadiran : " << mhs[i].presentase << "%" <<endl;
                        cout << endl;
                    }
                    if (absen == 's' || absen == 'S'){
                        mhs[i].hadir += 0;
                        cout << " Mahasiswa sakit " << endl;
                        mhs[i].presentase = (mhs[i].hadir*100)/14;
                        cout << " Presentase kehadiran : " << mhs[i].presentase << "%" <<endl;
                        cout << endl;
                    }
                }
                if(mhs[i].presentase < 60 ){
                    cout << " Siswa dengan NIM " << i << " tidak bisa mengikuti UAS mata kuliah Arsitektur dan Organisasi Komputer" << endl << endl << endl;;
                } else{
                    cout << " Siswa dengan NIM " << i << " bisa mengikuti UAS mata kuliah Arsitektur dan Organisasi Komputer" << endl << endl << endl;
                }
            }
            }else{
                cout << " Password anda salah !" << endl;
            }
            
        } else {
            cout << " Username anda salah !" << endl;
        }
    }
    if (nu == 3){
        strcpy(dosen.usernamed, "oni");
        strcpy(dosen.pwd, "oni123");
        cout << " Masukkan username anda : ";
        cin >> dosen.username;
        if(strcmp(dosen.username,dosen.usernamed) == 0){
            cout << " Masukkan password anda : ";
            cin >> dosen.pw;
            if(strcmp(dosen.pw,dosen.pwd) == 0){
                system("cls");
                cout << "== Rekap absensi kehadiran mahasiswa mata kuliah Bahasa Indonesia ==" << endl;
                for(int i = 100; i <= n; i++){
                cout << " Absensi mahasiswa " << endl;
                minggu = 14;
                for (int j = 1; j <= minggu; j++){
                    cout << " Absensi minggu ke " << j << endl;
                    cout << " Mahasiswa dengan NIM " << i << endl;
                    cout << " Nama \t: " << mhs[i].nama << endl; 
                    cout << " Kehadiran (h/a/i/s)\t: ";
                    cin >> absen;
                    if(absen == 'h' || absen == 'H'){
                        mhs[i].hadir += 1;
                        cout << " Mahasiswa hadir " << endl;
                        mhs[i].presentase = (mhs[i].hadir*100)/14;
                        cout << " Presentase kehadiran : " << mhs[i].presentase << "%" <<endl;
                        cout << endl;
                    }
                    if (absen == 'a' || absen == 'A'){
                        mhs[i].hadir += 0;
                        cout << " Mahasiswa tidak hadir tanpa keterangan" << endl;
                        mhs[i].presentase = (mhs[i].hadir*100)/14;
                        cout << " Presentase kehadiran : " << mhs[i].presentase << "%" <<endl;
                        cout << endl;
                    }
                    if (absen == 'i' || absen == 'I'){
                        mhs[i].hadir += 0;
                        cout << " Mahasiswa izin dengan alasan ";
                        cin.ignore();
                        cin.getline(alasan,100);
                        mhs[i].presentase = (mhs[i].hadir*100)/14;
                        cout << " Presentase kehadiran : " << mhs[i].presentase << "%" <<endl;
                        cout << endl;
                    }
                    if (absen == 's' || absen == 'S'){
                        mhs[i].hadir += 0;
                        cout << " Mahasiswa sakit " << endl;
                        mhs[i].presentase = (mhs[i].hadir*100)/14;
                        cout << " Presentase kehadiran : " << mhs[i].presentase << "%" <<endl;
                        cout << endl;
                    }
                }
                if(mhs[i].presentase < 60 ){
                    cout << " Siswa dengan NIM " << i << " tidak bisa mengikuti UAS mata kuliah Bahasa Indonesia" << endl << endl << endl;;
                } else{
                    cout << " Siswa dengan NIM " << i << " bisa mengikuti UAS mata kuliah Bahasa Indonesia" << endl << endl << endl;
                }
            }
            }else{
                cout << " Password anda salah !" << endl;
            }
            
        } else {
            cout << " Username anda salah !" << endl;
        }
    }
    if (nu == 4){
        strcpy(dosen.usernamed, "anita");
        strcpy(dosen.pwd, "anita123");
        cout << " Masukkan username anda : ";
        cin >> dosen.username;
        if(strcmp(dosen.username,dosen.usernamed) == 0){
            cout << " Masukkan password anda : ";
            cin >> dosen.pw;
            if(strcmp(dosen.pw,dosen.pwd) == 0){
                system("cls");
                cout << "== Rekap absensi kehadiran mahasiswa mata kuliah Pemrograman Dasar ==" << endl;
                for(int i = 100; i <= n; i++){
                cout << " Absensi mahasiswa " << endl;
                minggu = 14;
                for (int j = 1; j <= minggu; j++){
                    cout << " Absensi minggu ke " << j << endl;
                    cout << " Mahasiswa dengan NIM " << i << endl;
                    cout << " Nama \t: " << mhs[i].nama << endl; 
                    cout << " Kehadiran (h/a/i/s)\t: ";
                    cin >> absen;
                    if(absen == 'h' || absen == 'H'){
                        mhs[i].hadir += 1;
                        cout << " Mahasiswa hadir " << endl;
                        mhs[i].presentase = (mhs[i].hadir*100)/14;
                        cout << " Presentase kehadiran : " << mhs[i].presentase << "%" <<endl;
                        cout << endl;
                    }
                    if (absen == 'a' || absen == 'A'){
                        mhs[i].hadir += 0;
                        cout << " Mahasiswa tidak hadir tanpa keterangan" << endl;
                        mhs[i].presentase = (mhs[i].hadir*100)/14;
                        cout << " Presentase kehadiran : " << mhs[i].presentase << "%" <<endl;
                        cout << endl;
                    }
                    if (absen == 'i' || absen == 'I'){
                        mhs[i].hadir += 0;
                        cout << " Mahasiswa izin dengan alasan ";
                        cin.ignore();
                        cin.getline(alasan,100);
                        mhs[i].presentase = (mhs[i].hadir*100)/14;
                        cout << " Presentase kehadiran : " << mhs[i].presentase << "%" <<endl;
                        cout << endl;
                    }
                    if (absen == 's' || absen == 'S'){
                        mhs[i].hadir += 0;
                        cout << " Mahasiswa sakit " << endl;
                        mhs[i].presentase = (mhs[i].hadir*100)/14;
                        cout << " Presentase kehadiran : " << mhs[i].presentase << "%" <<endl;
                        cout << endl;
                    }
                }
                if(mhs[i].presentase < 60 ){
                    cout << " Siswa dengan NIM " << i << " tidak bisa mengikuti UAS mata kuliah Pemrograman Dasar" << endl << endl << endl;;
                } else{
                    cout << " Siswa dengan NIM " << i << " bisa mengikuti UAS mata kuliah Pemrograman Dasar" << endl << endl << endl;
                }
            }
            }else{
                cout << " Password anda salah !" << endl;
            }
            
        } else {
            cout << " Username anda salah !" << endl;
        }
    }
    if (nu == 5){
        strcpy(dosen.usernamed, "bawono");
        strcpy(dosen.pwd, "bawono123");
        cout << " Masukkan username anda : ";
        cin >> dosen.username;
        if(strcmp(dosen.username,dosen.usernamed) == 0){
            cout << " Masukkan password anda : ";
            cin >> dosen.pw;
            if(strcmp(dosen.pw,dosen.pwd) == 0){
                system("cls");
                cout << "== Rekap absensi kehadiran mahasiswa mata kuliah Olahraga ==" << endl;
                for(int i = 100; i <= n; i++){
                cout << " Absensi mahasiswa " << endl;
                minggu = 14;
                for (int j = 1; j <= minggu; j++){
                    cout << " Absensi minggu ke " << j << endl;
                    cout << " Mahasiswa dengan NIM " << i << endl;
                    cout << " Nama \t: " << mhs[i].nama << endl; 
                    cout << " Kehadiran (h/a/i/s)\t: ";
                    cin >> absen;
                    if(absen == 'h' || absen == 'H'){
                        mhs[i].hadir += 1;
                        cout << " Mahasiswa hadir " << endl;
                        mhs[i].presentase = (mhs[i].hadir*100)/14;
                        cout << " Presentase kehadiran : " << mhs[i].presentase << "%" <<endl;
                        cout << endl;
                    }
                    if (absen == 'a' || absen == 'A'){
                        mhs[i].hadir += 0;
                        cout << " Mahasiswa tidak hadir tanpa keterangan" << endl;
                        mhs[i].presentase = (mhs[i].hadir*100)/14;
                        cout << " Presentase kehadiran : " << mhs[i].presentase << "%" <<endl;
                        cout << endl;
                    }
                    if (absen == 'i' || absen == 'I'){
                        mhs[i].hadir += 0;
                        cout << " Mahasiswa izin dengan alasan ";
                        cin.ignore();
                        cin.getline(alasan,100);
                        mhs[i].presentase = (mhs[i].hadir*100)/14;
                        cout << " Presentase kehadiran : " << mhs[i].presentase << "%" <<endl;
                        cout << endl;
                    }
                    if (absen == 's' || absen == 'S'){
                        mhs[i].hadir += 0;
                        cout << " Mahasiswa sakit " << endl;
                        mhs[i].presentase = (mhs[i].hadir*100)/14;
                        cout << " Presentase kehadiran : " << mhs[i].presentase << "%" <<endl;
                        cout << endl;
                    }
                }
                if(mhs[i].presentase < 60 ){
                    cout << " Siswa dengan NIM " << i << " tidak bisa mengikuti UAS mata kuliah Olahraga" << endl << endl << endl;;
                } else{
                    cout << " Siswa dengan NIM " << i << " bisa mengikuti UAS mata kuliah Olahraga" << endl << endl << endl;
                }
            }
            }else{
                cout << " Password anda salah !" << endl;
            }
            
        } else {
            cout << " Username anda salah !" << endl;
        }
    }
    if (nu == 6){
        strcpy(dosen.usernamed, "nonik");
        strcpy(dosen.pwd, "nonik123");
        cout << " Masukkan username anda : ";
        cin >> dosen.username;
        if(strcmp(dosen.username,dosen.usernamed) == 0){
            cout << " Masukkan password anda : ";
            cin >> dosen.pw;
            if(strcmp(dosen.pw,dosen.pwd) == 0){
                system("cls");
                cout << "== Rekap absensi kehadiran mahasiswa mata kuliah Matematika ==" << endl;
                for(int i = 100; i <= n; i++){
                cout << " Absensi mahasiswa " << endl;
                minggu = 14;
                for (int j = 1; j <= minggu; j++){
                    cout << " Absensi minggu ke " << j << endl;
                    cout << " Mahasiswa dengan NIM " << i << endl;
                    cout << " Nama \t: " << mhs[i].nama << endl; 
                    cout << " Kehadiran (h/a/i/s)\t: ";
                    cin >> absen;
                    if(absen == 'h' || absen == 'H'){
                        mhs[i].hadir += 1;
                        cout << " Mahasiswa hadir " << endl;
                        mhs[i].presentase = (mhs[i].hadir*100)/14;
                        cout << " Presentase kehadiran : " << mhs[i].presentase << "%" <<endl;
                        cout << endl;
                    }
                    if (absen == 'a' || absen == 'A'){
                        mhs[i].hadir += 0;
                        cout << " Mahasiswa tidak hadir tanpa keterangan" << endl;
                        mhs[i].presentase = (mhs[i].hadir*100)/14;
                        cout << " Presentase kehadiran : " << mhs[i].presentase << "%" <<endl;
                        cout << endl;
                    }
                    if (absen == 'i' || absen == 'I'){
                        mhs[i].hadir += 0;
                        cout << " Mahasiswa izin dengan alasan ";
                        cin.ignore();
                        cin.getline(alasan,100);
                        mhs[i].presentase = (mhs[i].hadir*100)/14;
                        cout << " Presentase kehadiran : " << mhs[i].presentase << "%" <<endl;
                        cout << endl;
                    }
                    if (absen == 's' || absen == 'S'){
                        mhs[i].hadir += 0;
                        cout << " Mahasiswa sakit " << endl;
                        mhs[i].presentase = (mhs[i].hadir*100)/14;
                        cout << " Presentase kehadiran : " << mhs[i].presentase << "%" <<endl;
                        cout << endl;
                    }
                }
                if(mhs[i].presentase < 60 ){
                    cout << " Siswa dengan NIM " << i << " tidak bisa mengikuti UAS mata kuliah Matematika" << endl << endl << endl;;
                } else{
                    cout << " Siswa dengan NIM " << i << " bisa mengikuti UAS mata kuliah Matematika" << endl << endl << endl;
                }
            }
            }else{
                cout << " Password anda salah !" << endl;
            }
            
        } else {
            cout << " Username anda salah !" << endl;
        }
    }
    if (nu == 7){
        strcpy(dosen.usernamed, "rojil");
        strcpy(dosen.pwd, "rojil123");
        cout << " Masukkan username anda : ";
        cin >> dosen.username;
        if(strcmp(dosen.username,dosen.usernamed) == 0){
            cout << " Masukkan password anda : ";
            cin >> dosen.pw;
            if(strcmp(dosen.pw,dosen.pwd) == 0){
                system("cls");
                cout << "== Rekap absensi kehadiran mahasiswa mata kuliah Pancasila ==" << endl;
                for(int i = 100; i <= n; i++){
                cout << " Absensi mahasiswa " << endl;
                minggu = 14;
                for (int j = 1; j <= minggu; j++){
                    cout << " Absensi minggu ke " << j << endl;
                    cout << " Mahasiswa dengan NIM " << i << endl;
                    cout << " Nama \t: " << mhs[i].nama << endl; 
                    cout << " Kehadiran (h/a/i/s)\t: ";
                    cin >> absen;
                    if(absen == 'h' || absen == 'H'){
                        mhs[i].hadir += 1;
                        cout << " Mahasiswa hadir " << endl;
                        mhs[i].presentase = (mhs[i].hadir*100)/14;
                        cout << " Presentase kehadiran : " << mhs[i].presentase << "%" <<endl;
                        cout << endl;
                    }
                    if (absen == 'a' || absen == 'A'){
                        mhs[i].hadir += 0;
                        cout << " Mahasiswa tidak hadir tanpa keterangan" << endl;
                        mhs[i].presentase = (mhs[i].hadir*100)/14;
                        cout << " Presentase kehadiran : " << mhs[i].presentase << "%" <<endl;
                        cout << endl;
                    }
                    if (absen == 'i' || absen == 'I'){
                        mhs[i].hadir += 0;
                        cout << " Mahasiswa izin dengan alasan ";
                        cin.ignore();
                        cin.getline(alasan,100);
                        mhs[i].presentase = (mhs[i].hadir*100)/14;
                        cout << " Presentase kehadiran : " << mhs[i].presentase << "%" <<endl;
                        cout << endl;
                    }
                    if (absen == 's' || absen == 'S'){
                        mhs[i].hadir += 0;
                        cout << " Mahasiswa sakit " << endl;
                        mhs[i].presentase = (mhs[i].hadir*100)/14;
                        cout << " Presentase kehadiran : " << mhs[i].presentase << "%" <<endl;
                        cout << endl;
                    }
                }
                if(mhs[i].presentase < 60 ){
                    cout << " Siswa dengan NIM " << i << " tidak bisa mengikuti UAS mata kuliah Pancasila" << endl << endl << endl;;
                } else{
                    cout << " Siswa dengan NIM " << i << " bisa mengikuti UAS mata kuliah Pancasila" << endl << endl << endl;
                }
            }
            }else{
                cout << " Password anda salah !" << endl;
            }
            
        } else {
            cout << " Username anda salah !" << endl;
        }
    }
    if(nu > 7){
        cout << " Sopo dosen e cyak???" << endl;
    }
}