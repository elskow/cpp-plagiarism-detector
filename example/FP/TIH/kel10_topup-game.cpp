#include <iostream>
#include <string>
using namespace std;

// Struct 
struct topup {
    int id;
    int server;
    int game;
    int bayar;
    int nominal_ml, nominal_pm, nominal_ff, nominal_gi, nominal_hsr;
    int norek, notelp;
    char username[20];
};

int main(){
    topup topup;
    string ulang;
    do{
    cout << "================================================================" << endl;
    cout << "=============== SELAMAT DATANG DI HYRAXSTORE.ID ================" << endl;
    cout << "================================================================" << endl;
    cout << "Mau topup game apa?" << endl;

    // Pilihan game
    cout << "1. Mobile Legends: Bang Bang" << endl;
    cout << "2. Playerunknown's Battleground Mobile" << endl;
    cout << "3. Free Fire" << endl;
    cout << "4. Genshin Impact" << endl;
    cout << "5. Honkai: Star Rail" << endl;
    cout << "Pilih game: "; cin >> topup.game;
    cout << "================================================================" << endl;

    // Switch case untuk setiap game
    switch (topup.game){
        case 1 : 
        cout << "TOP UP DIAMOND MOBILE LEGENDS: BANG BANG" << endl;
        cout << "================================================================" << endl;
        cout << "Pricelist: " << endl;
        cout << "1. 110 Diamond ................ Rp30.000,00" << endl;
        cout << "2. 150 Diamond ................ Rp40.000,00" << endl;
        cout << "3. 257 Diamond ................ Rp70.000,00" << endl;
        cout << "4. 550 Diamond ................ Rp150.000,00" << endl;
        cout << "5. 1200 Diamond ............... Rp300.000,00" << endl;
        cout << "6. 2000 Diamond ............... Rp500.000,00" << endl;
        cout << "7. 4000 Diamond ............... Rp1.000.000,00" << endl;;
        cout << "Pilihan Anda: ";
        cin >> topup.nominal_ml;
        cout << "================================================================" << endl;
        cout << "Detail pesanan: ";
        if (topup.nominal_ml == 1){
            cout << "110 = (100 + 10) ML Diamond => Rp30.000,00" << endl;
         } else if (topup.nominal_ml == 2){
            cout << "150 = (135 + 15) ML Diamond => Rp40.000,00" << endl;
         } else if (topup.nominal_ml == 3){
            cout << "257 = (200 + 57) ML Diamond => Rp70.000,00" << endl;
         } else if (topup.nominal_ml == 4){
            cout << "550 = (480 + 70) ML Diamond => Rp150.000,00" << endl;
         } else if (topup.nominal_ml == 5){
            cout << "1200 = (915 + 285) ML Diamond => Rp300.000,00" << endl;
         } else if (topup.nominal_ml == 6){
            cout << "2000 = (1700 + 300) ML Diamond => Rp500.000,00" << endl;
         } else if (topup.nominal_ml == 7){
            cout << "4000 = (3500 + 500) ML Diamond => Rp1.000.000,00" << endl;
         } else {
            cout << "TIDAK VALID !" << endl;
         }
         cout << "================================================================" << endl;
         cout << "Masukkan Data Player" << endl;
         cout << "ID: "; cin >> topup.id;
         cout << "Server: "; cin >> topup.server;
         cout << "Username: ";
         cin.ignore();
         cin.getline (topup.username, sizeof(topup.username));
         break;

         case 2 : 
         cout << "TOP UP UC PUBG MOBILE" << endl;
         cout << "================================================================" << endl;
         cout << "Pricelist: " << endl;
         cout << "1. 325 UC ..................... Rp65.000,00" << endl;
         cout << "2. 660 UC ..................... Rp125.000,00" << endl;
         cout << "3. 1000 UC .................... Rp190.000,00" << endl;
         cout << "4. 2500 UC .................... Rp500.000,00" << endl;
         cout << "5. 5000 UC .................... Rp1.000.000,00" << endl;
         cout << "Pilihan Anda: ";
         cin >> topup.nominal_pm;
         cout << "================================================================" << endl;
         cout << "Detail pesanan: ";
         if (topup.nominal_pm == 1){
            cout << "325 PUBG Mobile Unknown Cash => Rp65.000,00" << endl;
         } else if (topup.nominal_pm == 2){
            cout << "600 PUBG Mobile Unknown Cash => Rp125.000,00" << endl;
         } else if (topup.nominal_pm == 3){
            cout << "1000 PUBG Mobile Unknown Cash => Rp190.000,00" << endl;
         } else if (topup.nominal_pm == 4){
            cout << "2500 PUBG Mobile Unknown Cash => Rp500.000,00" << endl;
         } else if (topup.nominal_pm == 5){
            cout << "5000 PUBG Mobile Unknown Cash => Rp1.000.000,00" << endl;
         } else {
            cout << "TIDAK VALID !" << endl;
         }
         cout << "================================================================" << endl;
         cout << "Masukkan Data Player" << endl;
         cout << "ID: "; cin >> topup.id;
         cout << "Username: ";
         cin.ignore();
         cin.getline (topup.username, sizeof(topup.username));
         break;

         case 3 : 
         cout << "TOP UP DIAMONDS FREE FIRE" << endl;
         cout << "================================================================" << endl;
         cout << "Pricelist: " << endl;
         cout << "1. 500 Diamond ................ Rp65.000,00" << endl;
         cout << "2. 860 Diamond ................ Rp100.000,00" << endl;
         cout << "3. 1700 DIamond ............... Rp200.000,00" << endl;
         cout << "4. 3500 Diamond ............... Rp450.000,00" << endl;
         cout << "5. 7000 Diamond ............... Rp800.000,00" << endl;
         cout << "6. 15000 Diamond .............. Rp1.500.000,00" << endl;
         cout << "Pilihan Anda: ";
         cin >> topup.nominal_ff;
         cout << "================================================================" << endl;
         cout << "Detail pesanan: ";
         if (topup.nominal_ff == 1){
            cout << "500 FF Diamond => Rp65.000,00" << endl;
         } else if (topup.nominal_ff == 2){
            cout << "860 FF DIamond => Rp100.000,00" << endl;
         } else if (topup.nominal_ff == 3){
            cout << "1700 FF Diamond => Rp200.000,00" << endl;
         } else if (topup.nominal_ff == 4){
            cout << "3500 FF Diamond => Rp450.000,00" << endl;
         } else if (topup.nominal_ff == 5){
            cout << "7000 FF Diamond => Rp800.000,00" << endl;
         } else if (topup.nominal_ff == 6){
            cout << "15000 FF Diamond => Rp1.500.000,00" << endl;
         } else {
            cout << "TIDAK VALID !" << endl;
         }
         cout << "================================================================" << endl;
         cout << "Masukkan Data Player" << endl;
         cout << "ID: "; cin >> topup.id;
         cout << "Username: ";
         cin.ignore();
         cin.getline (topup.username, sizeof(topup.username));
         break;

         case 4 :
         cout << "TOP UP UC GAME GENSHIN IMPACT" << endl;
         cout << "================================================================" << endl;
         cout << "Pricelist: " << endl;
         cout << "1. 350 GC ..................... Rp60.000,00" << endl;
         cout << "2. 670 GC ..................... Rp100.000,00" << endl;
         cout << "3. 1500 GC .................... Rp215.000,00" << endl;
         cout << "4. 3300 GC .................... Rp400.000,00" << endl;
         cout << "5. 6700 GC .................... Rp800.000,00" << endl;
         cout << "6. 15000 GC ................... Rp1.600.000,00" << endl;
         cout << "Pilihan Anda: ";
         cin >> topup.nominal_gi;
         cout << "================================================================" << endl;
         cout << "Detail pesanan: ";
         if (topup.nominal_gi == 1){
            cout << "350 GI Genesis Crystal => Rp60.000,00" << endl;
         } else if (topup.nominal_gi == 2){
            cout << "670 GI Genesis Crystal => Rp100.000,00" << endl;
         } else if (topup.nominal_gi == 3){
            cout << "1500 GI Genesis Crystal => Rp215.000,00" << endl;
         } else if (topup.nominal_gi == 4){
            cout << "3300 GI Genesis Crystal => Rp400.000,00" << endl;
         } else if (topup.nominal_gi == 5){
            cout << "6700 GI Genesis Crystal => Rp800.000,00" << endl;
         } else if (topup.nominal_gi == 6){
            cout << "15000 GI Genesis Crystal => Rp1.600.000,00" << endl;
         } else {
            cout << "TIDAK VALID !" << endl;
         }
         cout << "================================================================" << endl;
         cout << "Masukkan Data Player" << endl;
         cout << "UID: "; cin >> topup.id;
         cout << "Username: ";
         cin.ignore();
         cin.getline (topup.username, sizeof(topup.username));
         break;

         case 5 :
         cout << "TOP UP UC GAME HONKAI:STAR RAIL" << endl;
         cout << "================================================================" << endl;
         cout << "Pricelist: " << endl;
         cout << "1. 350 OS ..................... Rp60.000,00" << endl;
         cout << "2. 670 OS ..................... Rp100.000,00" << endl;
         cout << "3. 1500 OS .................... Rp215.000,00" << endl;
         cout << "4. 3300 OS .................... Rp400.000,00" << endl;
         cout << "5. 6700 OS .................... Rp800.000,00" << endl;
         cout << "6. 15000 OS ................... Rp1.600.000,00" << endl;
         cout << "Pilihan Anda: ";
         cin >> topup.nominal_hsr;
         cout << "================================================================" << endl;
         cout << "Detail pesanan: ";
         if (topup.nominal_hsr == 1){
            cout << "350 HSR Oneric Shard => Rp60.000,00" << endl;
         } else if (topup.nominal_hsr == 2){
            cout << "670 HSR Oneric Shard => Rp100.000,00" << endl;
         } else if (topup.nominal_hsr == 3){
            cout << "1500 HSR Oneric Shard => Rp215.000,00" << endl;
         } else if (topup.nominal_hsr == 4){
            cout << "3300 HSR Oneric Shard => Rp400.000,00" << endl;
         } else if (topup.nominal_hsr == 5){
            cout << "6700 HSR Oneric Shard => Rp800.000,00" << endl;
         } else if (topup.nominal_hsr == 6){
            cout << "15000 HSR Oneric Shard => Rp1.600.000,00" << endl;
         } else {
            cout << "TIDAK VALID !" << endl;
            return 0;
         }
         cout << "================================================================" << endl;
         cout << "Masukkan Data Player" << endl;
         cout << "UID: "; cin >> topup.id;
         cout << "Username: ";
         cin.ignore();
         cin.getline (topup.username, sizeof(topup.username));
         break;

        default : cout << "Pilihan Anda Tidak Tersedia!" << endl;
        return 0;
        break;
    } 
    cout << "================================================================" << endl;

    // Metode pembayaran
    cout << "METODE PEMBAYARAN" << endl;
    cout << "1. QRIS - OVO" << endl;
    cout << "2. QRIS - Go-Pay" << endl;
    cout << "3. QRIS - DANA" << endl;
    cout << "4. Telkomsel" << endl;
    cout << "5. IM3 / Indosat" << endl;
    cout << "6. Transfer Bank" << endl;
    cout << "Metode Anda: "; cin >> topup.bayar;
    for (int i = 1; i <= 5; i++)
    {
        if (topup.bayar == i){
            cout << "Masukkan no. telepon Anda" << endl;
            cout << "No. Telp: "; cin >> topup.notelp;
        }
    } if (topup.bayar == 6){
        cout << "Masukkan no. rekening Anda" << endl;
        cout << "No. Rekening: "; cin >> topup.norek;
    } else if (topup.bayar < 1){
        cout << "Metode pembayaran tidak valid, ";
        cout << "Harap mengulangi proses pembelian!" << endl;
        return 0;
    } else if (topup.bayar > 6){
        cout << "Metode pembayaran tidak valid, ";
        cout << "Harap mengulangi proses pembelian!" << endl;
        return 0;
    }
    cin.ignore();

    // Cetak bukti pembelian
    cout << "================================================================" << endl;
    cout << "MEMPROSES PEMBELIAN ANDA" << endl;
    if (topup.game == 1){
        cout << "Item yang Anda beli: ";
        if (topup.nominal_ml == 1){
            cout << "110 = (100 + 10) ML Diamond => Rp30.000,00" << endl;
         } else if (topup.nominal_ml == 2){
            cout << "150 = (135 + 15) ML Diamond => Rp40.000,00" << endl;
         } else if (topup.nominal_ml == 3){
            cout << "257 = (200 + 57) ML Diamond => Rp70.000,00" << endl;
         } else if (topup.nominal_ml == 4){
            cout << "550 = (480 + 70) ML Diamond => Rp150.000,00" << endl;
         } else if (topup.nominal_ml == 5){
            cout << "1200 = (915 + 285) ML Diamond => Rp300.000,00" << endl;
         } else if (topup.nominal_ml == 6){
            cout << "2000 = (1700 + 300) ML Diamond => Rp500.000,00" << endl;
         } else if (topup.nominal_ml == 7){
            cout << "4000 = (3500 + 500) ML Diamond => Rp1.000.000,00" << endl;
         }
        cout << "ID: " << topup.id << " " << topup.server << endl;
        cout << "Username: " << topup.username << endl;
        cout << "Metode pembayaran: ";
    } else if (topup.game == 2){
        cout << "Item yang Anda beli: ";
        if (topup.nominal_pm == 1){
            cout << "325 PUBG Mobile Unknown Cash => Rp65.000,00" << endl;
         } else if (topup.nominal_pm == 2){
            cout << "600 PUBG Mobile Unknown Cash => Rp125.000,00" << endl;
         } else if (topup.nominal_pm == 3){
            cout << "1000 PUBG Mobile Unknown Cash => Rp190.000,00" << endl;
         } else if (topup.nominal_pm == 4){
            cout << "2500 PUBG Mobile Unknown Cash => Rp500.000,00" << endl;
         } else if (topup.nominal_pm == 5){
            cout << "5000 PUBG Mobile Unknown Cash => Rp1.000.000,00" << endl;
         } else {
            cout << "TIDAK VALID !" << endl;
         }
        cout << "ID: " << topup.id << " " << endl;
        cout << "Username: " << topup.username << endl;
        cout << "Metode pembayaran: ";
    } else if (topup.game == 3){
        cout << "Item yang Anda beli: ";
        if (topup.nominal_ff == 1){
            cout << "500 FF Diamond => Rp65.000,00" << endl;
         } else if (topup.nominal_ff == 2){
            cout << "860 FF DIamond => Rp100.000,00" << endl;
         } else if (topup.nominal_ff == 3){
            cout << "1700 FF Diamond => Rp200.000,00" << endl;
         } else if (topup.nominal_ff == 4){
            cout << "3500 FF Diamond => Rp450.000,00" << endl;
         } else if (topup.nominal_ff == 5){
            cout << "7000 FF Diamond => Rp800.000,00" << endl;
         } else if (topup.nominal_ff == 6){
            cout << "15000 FF Diamond => Rp1.500.000,00" << endl;
         } else {
            cout << "TIDAK VALID !" << endl;
         }
        cout << "ID: " << topup.id << " " << endl;
        cout << "Username: " << topup.username << endl;
        cout << "Metode pembayaran: ";
    } else if (topup.game == 4){
        cout << "Item yang Anda beli: ";
        if (topup.nominal_gi == 1){
            cout << "350 GI Genesis Crystal => Rp60.000,00" << endl;
         } else if (topup.nominal_gi == 2){
            cout << "670 GI Genesis Crystal => Rp100.000,00" << endl;
         } else if (topup.nominal_gi == 3){
            cout << "1500 GI Genesis Crystal => Rp215.000,00" << endl;
         } else if (topup.nominal_gi == 4){
            cout << "3300 GI Genesis Crystal => Rp400.000,00" << endl;
         } else if (topup.nominal_gi == 5){
            cout << "6700 GI Genesis Crystal => Rp800.000,00" << endl;
         } else if (topup.nominal_gi == 6){
            cout << "15000 GI Genesis Crystal => Rp1.600.000,00" << endl;
         } else {
            cout << "TIDAK VALID !" << endl;
         }
        cout << "ID: " << topup.id << " " << endl;
        cout << "Username: " << topup.username << endl;
        cout << "Metode pembayaran: ";
    } else if (topup.game == 5){
        cout << "Item yang Anda beli: ";
        if (topup.nominal_hsr == 1){
            cout << "350 HSR Oneric Shard => Rp60.000,00" << endl;
         } else if (topup.nominal_hsr == 2){
            cout << "670 HSR Oneric Shard => Rp100.000,00" << endl;
         } else if (topup.nominal_hsr == 3){
            cout << "1500 HSR Oneric Shard => Rp215.000,00" << endl;
         } else if (topup.nominal_hsr == 4){
            cout << "3300 HSR Oneric Shard => Rp400.000,00" << endl;
         } else if (topup.nominal_hsr == 5){
            cout << "6700 HSR Oneric Shard => Rp800.000,00" << endl;
         } else if (topup.nominal_hsr == 6){
            cout << "15000 HSR Oneric Shard => Rp1.600.000,00" << endl;
         } else {
            cout << "TIDAK VALID !" << endl;
            return 0;
         }
        cout << "ID: " << topup.id << " " << endl;
        cout << "Username: " << topup.username << endl;
        cout << "Metode pembayaran: ";
    }
     // If untuk metode pembayaran
     if (topup.bayar == 1){
      cout << "QRIS -OVO" << endl;
     } else if (topup.bayar == 2){
      cout << "QRIS - Go-pay" << endl;
     } else if (topup.bayar == 3){
      cout << "QRIS - DANA" << endl;
     } else if (topup.bayar == 4){
      cout << "Telkomsel" << endl;
     } else if (topup.bayar == 5){
      cout << "IM3 / Indosat" << endl;
     } else if (topup.bayar == 6){
      cout << "Transfer Bank" << endl;
     }
     // If untuk Norek / Notelp yang diinput
     for (int i = 1; i <= 5; i++)
     {
        if (topup.bayar == i){
        cout << "Nomor Telepon: " << topup.notelp << endl;
        }
    } if (topup.bayar == 6){
      cout << "Nomor Rekening: " << topup.norek << endl;
    } 
    cout << "================================================================" << endl;
    cout << "Pembayaran sedang di proses" << endl;
    cout << "Silakan login game setelah 5 menit" << endl;
    cout << "================================================================" << endl;

// Konfirmasi topup lagi / tidak
cout << "Apakah Anda ingin topup lagi? <y/n>: " << endl;
cin >> ulang;
} while (ulang == "y");

cout << "================================================================" << endl;
cout << "============ TERIMAKASIH TELAH TOPUP DI HYRAXSTORE =============" << endl;
cout << "================================================================" << endl;

return 0;
}