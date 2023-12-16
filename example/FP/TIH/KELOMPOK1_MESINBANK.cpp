#include <iostream>
using namespace std;

int main(){
    // NAMA KELOMPOK :
    // STANIS BENEDICT NDUN (23051204268)
    // BAGAS YUDHO NUGROHO (23051204283)
    // RAH ADI DEWA HAKSAMA (23051204263)
    cout << "NAMA KELOMPOK : " << endl;
    cout << "STANIS BENEDICT NDUN (23051204268)" << endl;
    cout << "BAGAS YUDHO NUGROHO (23051204283)" << endl;
    cout << "RAH ADI DEWA HAKSAMA (23051204263)" << endl;

    // Start Progres 
    cout << "Program Mesin ATM\n";

    // Tipe Data
    string username, pin, pin_awal;
    int saldo ;

    cout << "masukkan saldo :";
    cin >> saldo;

    cout << "masukkan pin :";
    cin >> pin_awal;
    
    // Home
    char home = 'y';
    while (home == 'y')
    {
        // Login
        cout << "\n";
        cout << "=== Login ===\n";
        cout << "\n";
        cout << "Masukkan Username : ";
        cin >> username ;
        cout << "Masukkan Pin : ";
        cin >> pin ;

        // Verifikasi username dan password
        if (username, pin == pin_awal)
        {
            //intruksi
            char repeat_instructions = 'y';
            int opsi;
            while (repeat_instructions == 'y')
            {
                // Main Menu
                cout << "\n";
                cout << "====== Selamat Datang di Bank Gembox ====="<< endl;
                cout << "1. Periksa Saldo\n";
                cout <<"2. Tarik Saldo\n";
                cout <<"3. Isi Saldo\n";
                cout <<"4. Ganti Pin\n";
                cout <<"5. Transfer\n";
                cout <<"6. Keluar\n";
                cout <<"Silahkan Memilih Intruksi (1-5) : ";
                cin >> opsi;

                // Instruksi
                switch (opsi)
                {

                case 1:
                {
                    //Periksa Saldo
                    cout <<"Saldo anda sebesar " << saldo << " $" << endl;

                    //kembali ke instruksi
                    cout << "Apakah anda ingin mengulangi instruksi (y/n) :";
                    cin >> repeat_instructions;
                    cout <<"=================\n";

                    if (repeat_instructions != 'y')
                    {
                        // kembali ke home
                        cout << "\n";
                        cout << "Apakah anda ingin Mengulangi program (y/n) :";
                        cin >> home;
                    }
                }   break;
                case 2:
                {
                    // Tarik saldo
                    cout << "=======================================================\n";
                    int minus;
                    cout << "Masukkan nominal : ";
                    cin >> minus;
                    if (minus < saldo)
                    {
                        saldo -= minus;
                        cout << "Tarik saldo berhasil\n";
                        cout << "Saldo anda tersisa : " << saldo << " $" << endl;
                    }
                    else
                    {
                        cout << "Saldo tidak cukup. sisa saldo anda " << saldo << "$" << endl;
                    }

                    //Kembali ke intruksi
                    cout << "Apakah anda ingin mengulangi intruksi (y/n) :";
                    cin >> repeat_instructions;
                    cout << "======================================================\n";

                    if (repeat_instructions != 'y')
                    {
                        // Kembali ke Home
                        cout <<"\n";
                        cout <<"Apakah ingin mengulangi program (y/n) :";
                        cin >> home;
                    }
                    break;
                }
                case 3:
                {
                    // isi saldo
                    cout << "================================================================\n";
                    int plus;
                    cout << "Masukkan nominal : ";
                    if (cin >> plus)
                    {
                        saldo += plus;
                        cout << "isi saldo berhasil\n";
                        cout << "saldo anda tersisa : " << saldo << " $" << endl;
                    }
                    else {
                        cout << "Input tidak valid. Harap masukan angka";
                    }
                    //Kembali ke intruksi
                    cout << "Apakah anda ingin mengulangi intruksi (y/n) :";
                    cin >> repeat_instructions;
                    cout << "======================================================\n";

                    if (repeat_instructions != 'y')
                    {
                        // Kembali ke Home
                        cout <<"\n";
                        cout <<"Apakah ingin mengulangi program (y/n) :";
                        cin >> home;
                    }
                    break;

                }
                case 4:
                {
                    //ganti pin
                    cout << "======================================================\n";
                    string pin_confirm, new_pin;
                    cout << "Masukan Pin Lama: ";
                    cin >> pin_confirm;

                    //konfirmaasi pin
                    if (pin_confirm == pin)
                    {
                        cout << "Masukan Pin Baru :";
                        cin >> new_pin ;
                        cout << "pin berhasil diganti\n";
                        pin_awal = new_pin ;
                        cout << "======================================================\n";
                        repeat_instructions = 'n' ; //menghentikan intruksi
                        home = 'y' ;                //mengulangi prograam home
                    }
                    else
                    {
                        //pin invalit
                        cout << "pin invalit. Pastikan pin anda benar\n";
                        cout << "======================================================\n";
                        repeat_instructions = 'y';
                    }
                    break;
                }
                case 5:
               {
                int no_bank, u_transfer;
                cout << "Masukan Nomor Rekening yang anda Tuju ";
                cin >> no_bank;
                cout << "masukan nominal uang ";
                cin >> u_transfer;
                if(u_transfer < saldo)
                {
                    saldo -= u_transfer;
                    cout << "transfer berhasil";
                    cout << "Saldo anda tersisa : " << saldo << " $" << endl;
                }
                 else
                {
                    cout << "Saldo tidak cukup. sisa saldo anda " << saldo << "$" << endl;
                }
                //Kembali ke intruksi
                    cout << "Apakah anda ingin mengulangi intruksi (y/n) :";
                    cin >> repeat_instructions;
                    cout << "======================================================\n";

                    if (repeat_instructions != 'y')
                    {
                        // Kembali ke Home
                        cout <<"\n";
                        cout <<"Apakah ingin mengulangi program (y/n) :";
                        cin >> home;
                    }
                    break;
               }
               case 6:
               {
                //keluar
                repeat_instructions = 'n'; // menggntikan instruksi 
                // kembali ke home 
                cout << "\n";
                cout << "Apakah anda ingin mengulangi program? (y/n) :";
                cin >> home;
                break;
               }
               default:
               {
                // intruksi invalid
                cout << "instruksi tidak valid silahkan pilih 1-6" << endl;
               }
                
                }
            }
            cout << "=============================================\n";
        }
        else
        {
            // login gagal
            cout << "Login gagal, pastikan username dan pasword benar!" << endl;
        }
    }
    return 0;
}