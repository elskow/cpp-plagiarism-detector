#include <bits/stdc++.h>
using namespace std;

struct stock
{
    long long biner;
    char nama[20];
    int harga;
    int jumlah;
    int total;
};

struct stockbaru
{
    long long biner;
    char nama[20];
    int harga;
    int jumlah;
    int total;
};

struct laporan
{
    long long biner;
    char nama[20];
    int harga;
    int jumlah;
    int total;
};

struct struk
{
    long long biner;
    char nama[20];
    int harga;
    int jumlah;
    int total;
};

struct strukmock
{
    long long biner;
    char nama[20];
    int harga;
    int jumlah;
    int total;
};

int main()
{
    int pilihan;
    cout << R"(
     ######     ###     ######  ##     ## #### ######## ########     ########  ########   #######   ######   ########     ###    ##     ## 
    ##    ##   ## ##   ##    ## ##     ##  ##  ##       ##     ##    ##     ## ##     ## ##     ## ##    ##  ##     ##   ## ##   ###   ### 
    ##        ##   ##  ##       ##     ##  ##  ##       ##     ##    ##     ## ##     ## ##     ## ##        ##     ##  ##   ##  #### #### 
    ##       ##     ##  ######  #########  ##  ######   ########     ########  ########  ##     ## ##   #### ########  ##     ## ## ### ## 
    ##       #########       ## ##     ##  ##  ##       ##   ##      ##        ##   ##   ##     ## ##    ##  ##   ##   ######### ##     ## 
    ##    ## ##     ## ##    ## ##     ##  ##  ##       ##    ##     ##        ##    ##  ##     ## ##    ##  ##    ##  ##     ## ##     ## 
     ######  ##     ##  ######  ##     ## #### ######## ##     ##    ##        ##     ##  #######   ######   ##     ## ##     ## ##     ## 
    )" << endl;

    while (true)
    {
        cout << "1 Buat File Baru" << endl;
        cout << "2 Gunakan File Sebelumnya" << endl;
        cout << "3 Edit File Sebelumnya" << endl;
        cout << "4 Menambah Stock" << endl;
        cout << "5 Keluar" << endl;
        cout << "Pilih Operasi: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
        {
            ofstream input1("Biner_Harga.txt");
            if (input1.is_open())
            {
                ofstream input("Data_Stock.txt");
                if (input.is_open())
                {
                    int jenis;
                    cout << "Masukkan Banyak Jenis Barang: ";
                    cin >> jenis;

                    stock stock[jenis];

                    ofstream jumlah("Banyak_Data.txt");
                    if (jumlah.is_open())
                    {
                        jumlah << jenis;
                        jumlah.close();
                    }
                    else
                    {
                        break;
                    }

                    for (int i = 0; i < jenis; i++)
                    {
                        cout << "Barang Ke - " << i + 1 << endl;
                        cout << "Masukkan Biner: ";
                        cin >> stock[i].biner;
                        input << stock[i].biner << endl;

                        cout << "Masukkan Nama: ";
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cin.getline(stock[i].nama, 20);
                        input << stock[i].nama << endl;

                        cout << "Masukkan Harga: Rp.";
                        cin >> stock[i].harga;
                        input << stock[i].harga << endl;

                        cout << "Masukkan Jumlah: ";
                        cin >> stock[i].jumlah;
                        input << stock[i].jumlah << endl;

                        stock[i].total = stock[i].harga * stock[i].jumlah;
                        input << stock[i].total << endl;
                    }

                    cout << "Data_Stock.txt telah tersimpan" << endl;
                    input.close();
                }
                else
                {
                    cout << "File Tidak Ditemukan" << endl;
                }
            }
            else
            {
                cout << "File Tidak dapat dibuka" << endl;
                break;
            }
        }
        break;

        case 2:
        {
            int orang = 0, batas = 1, belanja = 0, batas1 = 1, uang, biner, pilihan2, jenis, banyak, total = 0, temp, count = 1, harga, totalbelanja;
            ifstream output1("Banyak_Data.txt");
            if (output1.is_open())
            {
                output1 >> jenis;
                output1.close();
            }

            else
            {
                cout << "Input Gagal" << endl;
            }

            stock stock[jenis];
            struk struk[jenis];
            strukmock mock[jenis];

            ifstream output2("Data_Stock.txt");
            {
                if (output2.is_open())
                {
                    for (int i = 0; i < jenis; i++)
                    {
                        output2 >> stock[i].biner;
                        output2.ignore(numeric_limits<streamsize>::max(), '\n');
                        output2.getline(stock[i].nama, sizeof(stock[i].nama));
                        output2 >> stock[i].harga;
                        output2 >> stock[i].jumlah;
                        output2 >> stock[i].total;
                    }
                    output2.close();
                }
            }

            for (int i = 0; i < jenis; i++)
            {
                mock[i].biner = stock[i].biner;
                strcpy(mock[i].nama, stock[i].nama);
                mock[i].harga = stock[i].harga;
                mock[i].jumlah = 0;
                mock[i].total = 0;
            }

            while (orang != batas)
            {
                total = 0;
                while (belanja != batas1)
                {
                    cout << "Masukkan Biner Produk: ";
                    cin >> biner;
                    for (int i = 0; i < jenis; i++)
                    {
                        if (stock[i].biner == biner)
                        {
                            cout << "Jumlah produk yang dibeli: ";
                            cin >> banyak;

                            if (stock[i].jumlah < banyak)
                            {
                                cout << "Stok tidak cukup" << endl;
                                cout << "Stok yang tersisa: " << stock[i].jumlah;
                                continue;
                            }

                            else
                            {
                                // Updating The Data_Stock.txt
                                stock[i].jumlah = stock[i].jumlah - banyak;
                                stock[i].total = stock[i].jumlah * stock[i].harga;
                                total += (stock[i].harga * banyak);

                                // Temp for Struk.txt
                                mock[i].jumlah = banyak;
                                mock[i].total = mock[i].harga * mock[i].jumlah;
                                totalbelanja = total;
                            }
                        }
                        else
                        {
                            continue;
                        }
                    }

                    cout << "Lanjut (1) | Selesai (0)" << endl;
                    cin >> pilihan2;
                    if (pilihan2 == 1)
                    {
                        continue;
                    }

                    else
                    {
                        cout << "Total Belanja: Rp." << total << endl;
                        cout << "Masukkan Uang: Rp.";
                        cin >> uang;
                        if (uang < total)
                        {
                            cout << "Uang tidak cukup" << endl;
                            ifstream temp("Belanja.txt");
                            if (temp.is_open())
                            {
                                temp >> biner;
                                temp >> banyak;
                                for (int i = 0; i < jenis; i++)
                                {
                                    if (stock[i].biner == biner)
                                    {
                                        stock[i].jumlah = stock[i].jumlah + banyak;
                                        stock[i].total = stock[i].jumlah * stock[i].harga;
                                        break;
                                    }
                                    else
                                    {
                                        continue;
                                    }
                                }
                                temp.close();
                            }
                            total = 0;
                            break;
                        }
                        else
                        {
                            cout << "Kembalian: Rp." << uang - total << endl;
                            ofstream input4("Data_Stock.txt");
                            if (input4.is_open())
                            {
                                for (int i = 0; i < jenis; i++)
                                {
                                    input4 << stock[i].biner << endl;
                                    input4 << stock[i].nama << endl;
                                    input4 << stock[i].harga << endl;
                                    input4 << stock[i].jumlah << endl;
                                    input4 << stock[i].total << endl;
                                }
                                input4.close();
                            }
                            ofstream input5("Struk_Belanja.txt");
                            if (input5.is_open())
                            {
                                for (int i = 0; i < jenis; i++)
                                {
                                    if (mock[i].jumlah != 0)
                                    {
                                        input5 << mock[i].nama << endl;
                                        input5 << "Harga : Rp." << mock[i].harga << endl;
                                        input5 << "Jumlah: " << mock[i].jumlah << endl;
                                        input5 << "Total : Rp." << mock[i].total << endl;
                                        input5 << endl;
                                    }
                                    else
                                    {
                                        continue;
                                    }
                                }
                                input5 << "Total Belanja: Rp." << totalbelanja << endl;
                                input5 << "Uang         : Rp." << uang << endl;
                                input5 << "Kembalian    : Rp." << uang - totalbelanja << endl;
                                input5.close();
                            }

                            else
                            {
                                break;
                            }
                            break;
                        }
                        belanja++;
                        break;
                    }
                }

                cout << endl
                     << "Pelanggan Selanjutnya" << endl;
                cout << "Lanjut (1) | Selesai (0)" << endl;
                cin >> pilihan2;
                if (pilihan2 == 1)
                {
                    continue;
                }

                else
                {
                    ofstream input1("Data_Stock.txt");
                    if (input1.is_open())
                    {
                        for (int i = 0; i < jenis; i++)
                        {
                            input1 << stock[i].biner << endl;
                            input1 << stock[i].nama << endl;
                            input1 << stock[i].harga << endl;
                            input1 << stock[i].jumlah << endl;
                            input1 << stock[i].total << endl;
                        }
                        input1.close();
                    }

                    ofstream laporan("Laporan_Perjualan_Harian.txt");
                    if (laporan.is_open())
                    {
                        for (int i = 0; i < jenis; i++)
                        {
                            laporan << stock[i].nama << "(" << stock[i].biner << ")" << endl;
                            laporan << "Harga     : " << stock[i].harga << endl;
                            laporan << "Stok Sisa : " << stock[i].jumlah << endl;
                            laporan << "Nilai Aset: Rp." << stock[i].total << endl;
                            laporan << endl;
                        }
                        laporan.close();
                    }
                    break;
                }
            }
        }
        break;

        case 3:
        {
            int jenis, binerlama, binerbaru, namabaru, hargabaru, tambahanstock, pilihan3;
            ifstream output1("Banyak_Data.txt");
            if (output1.is_open())
            {
                output1 >> jenis;
                output1.close();
            }

            else
            {
                cout << "Input Gagal" << endl;
            }

            stock stock[jenis];

            ifstream output2("Data_Stock.txt");
            {
                if (output2.is_open())
                {
                    for (int i = 0; i < jenis; i++)
                    {
                        output2 >> stock[i].biner;
                        output2.ignore(numeric_limits<streamsize>::max(), '\n');
                        output2.getline(stock[i].nama, sizeof(stock[i].nama));
                        output2 >> stock[i].harga;
                        output2 >> stock[i].jumlah;
                        output2 >> stock[i].total;
                    }
                    output2.close();
                }
                else
                {
                    cout << "File Tidak Ditemukan" << endl;
                }
            }

            cout << "Masukkan Biner Produk: ";
            cin >> binerlama;

            for (int i = 0; i < jenis; i++)
            {
                if (stock[i].biner == binerlama)
                {
                    cout << "1 Ganti Biner Produk" << endl;
                    cout << "2 Ganti Nama Produk" << endl;
                    cout << "3 Tambah Stock" << endl;
                    cout << "4 Ganti Harga" << endl;
                    cout << "Pilih Operasi:";
                    cin >> pilihan3;

                    switch (pilihan3)
                    {
                    case 1:
                    {
                        for (int i = 0; i < jenis; i++)
                        {
                            if (binerlama == stock[i].biner)
                            {
                                cout << "Masukkan Biner Baru: ";
                                cin >> stock[i].biner;
                                cout << "Perubahan Data Tersimpan" << endl;
                            }
                            else
                            {
                                continue;
                            }
                        }
                    }
                    break;

                    case 2:
                    {
                        for (int i = 0; i < jenis; i++)
                        {
                            if (binerlama == stock[i].biner)
                            {
                                cout << "Masukkan Nama Baru: ";
                                cin >> stock[i].nama;
                                cout << "Perubahan Data Tersimpan" << endl;
                            }
                            else
                            {
                                continue;
                            }
                        }
                    }
                    break;

                    case 3:
                    {
                        for (int i = 0; i < jenis; i++)
                        {
                            if (binerlama == stock[i].biner)
                            {
                                cout << "Masukkan Tambahan Stock: ";
                                cin >> tambahanstock;
                                stock[i].jumlah += tambahanstock;
                                cout << "Perubahan Data Tersimpan" << endl;
                                stock[i].total = stock[i].harga * stock[i].jumlah;
                            }
                            else
                            {
                                continue;
                            }
                        }
                    }
                    break;

                    case 4:
                    {
                        for (int i = 0; i < jenis; i++)
                        {
                            if (binerlama == stock[i].biner)
                            {
                                cout << "Masukkan Harga Baru: ";
                                cin >> hargabaru;
                                stock[i].harga = hargabaru;
                                cout << "Perubahan Data Tersimpan" << endl;
                                stock[i].total = stock[i].harga * stock[i].jumlah;
                            }
                            else
                            {
                                continue;
                            }
                        }
                    }
                    break;
                    }

                    ofstream input2("Data_Stock.txt");
                    if (input2.is_open())
                    {
                        for (int i = 0; i < jenis; i++)
                        {
                            input2 << stock[i].biner << endl;
                            input2 << stock[i].nama << endl;
                            input2 << stock[i].harga << endl;
                            input2 << stock[i].jumlah << endl;
                            input2 << stock[i].total << endl;
                        }
                        input2.close();
                    }
                    else
                    {
                        cout << "File Tidak Dapat Dibuka" << endl;
                    }
                }
            }
        }
        break;

        case 4:
        {
            int jenis, jenis2, pilihan4, banyak;
            ifstream output1("Banyak_Data.txt");
            if (output1.is_open())
            {
                output1 >> jenis;
                output1.close();
            }

            else
            {
                cout << "Input Gagal" << endl;
            }

            stock stock[jenis];

            ifstream output("Data_Stock.txt");
            {
                if (output.is_open())
                {
                    for (int i = 0; i < jenis; i++)
                    {
                        output >> stock[i].biner;
                        output.ignore(numeric_limits<streamsize>::max(), '\n');
                        output.getline(stock[i].nama, sizeof(stock[i].nama));
                        output >> stock[i].harga;
                        output >> stock[i].jumlah;
                        output >> stock[i].total;
                    }
                    output.close();
                }
                else
                {
                    cout << "File Tidak Ditemukan" << endl;
                }
            }

            cout << "Masukkan Banyak Jenis Produk Baru: ";
            cin >> jenis2;

            stockbaru stockbaru[jenis2];
            for (int i = 0; i < jenis2; i++)
            {
                cout << "Barang Baru Ke - " << i + 1 << endl;
                cout << "Masukkan Biner: ";
                cin >> stockbaru[i].biner;

                cout << "Masukkan Nama: ";
                cin.ignore();
                cin.getline(stockbaru[i].nama, 20);

                cout << "Masukkan Harga: Rp.";
                cin >> stockbaru[i].harga;

                cout << "Masukkan Jumlah: ";
                cin >> stockbaru[i].jumlah;

                stockbaru[i].total = stockbaru[i].harga * stockbaru[i].jumlah;
            }

            ofstream input1("Banyak_Data.txt");
            if (input1.is_open())
            {
                input1 << jenis + jenis2;
                input1.close();
            }

            ofstream input("Data_Stock.txt");
            if (input.is_open())
            {
                for (int i = 0; i < jenis; i++)
                {
                    input << stock[i].biner << endl;
                    input << stock[i].nama << endl;
                    input << stock[i].harga << endl;
                    input << stock[i].jumlah << endl;
                    input << stock[i].total << endl;
                }
                for (int i = 0; i < jenis2; i++)
                {
                    input << stockbaru[i].biner << endl;
                    input << stockbaru[i].nama << endl;
                    input << stockbaru[i].harga << endl;
                    input << stockbaru[i].jumlah << endl;
                    input << stockbaru[i].total << endl;
                }
                cout << "Data_Stock telah diperbaharui" << endl;
                input.close();
            }
            else
            {
                cout << "File Tidak Dapat Dibuka" << endl;
            }
        }
        break;

        case 5:
            cout << "Exiting program..." << endl;
            return 0;
        }
    }
}
