#include <iostream> 
#include <string> 

using namespace std;
//fungsi untuk mengubah nilai awal ke rupiah 
float backtoRupiah(float uang, int pilihan) {
    switch(pilihan) {
        case 1: //Rupiah
        return uang;
        
        case 2: //Dollar
        return uang * 15500;

        case 3: //Yen
        return uang * 105;

        case 4: //Pound Sterling
        return uang * 19500;

        case 5: //Euro
        return uang * 16700;

        default:
            cout << "Pilihan mata uang tidak valid" << endl;
            exit(EXIT_FAILURE); // Keluar dari program dengan status kesalahan
    }
}
//fungsi untuk mengubah nilai rupiah ke tujuan mata uang yang ingin dikonversi 
float convert(float uang, int pilihan) {
    switch(pilihan) {
        case 1: //Rupiah
        return uang;
        
        case 2: //Dollar
        return uang / 15500;

        case 3: //Yen
        return uang / 105;

        case 4: //Pound Sterling
        return uang / 19500;

        case 5: //Euro
        return uang / 16700;

        default:
            cout << "Pilihan mata uang tidak valid" << endl;
            exit(EXIT_FAILURE); // Keluar dari program dengan status kesalahan
    }
}
//fungsi untuk mencetak nama mata uang sesuai pilihan 
void out(int pilihan) {
    switch(pilihan) {
        case 1:
            cout << "Rupiah";
            break;

        case 2:
            cout << "Dollar";
            break;

        case 3:
            cout << "Yen";
            break;
        
        case 4:
            cout << "Pound Sterling";
            break;

        case 5: 
            cout << "Euro";
            break; 

        default:
            cout << "Pilihan mata uang tidak valid" << endl;
            exit(EXIT_FAILURE); // Keluar dari program dengan status kesalahan
    }
}

int main() {
    int pilihan1, pilihan2;
    float uang;
    string pilihan = "1. Rupiah\n2. Dollar\n3. Yen\n4. Pound Sterling\n5. Euro\n";
    
    cout << pilihan << "Pilih mata uang awal : ";
    cin >> pilihan1;
    cout << "Masukan nominal : ";
    cin >> uang;

    cout << pilihan << "Pilih mata uang yang ingin di konversi : ";
    cin >> pilihan2;
    
    float awal = uang;
    uang = backtoRupiah(uang, pilihan1);
    uang = convert(uang, pilihan2);

    cout << awal << " ";
    out(pilihan1);
    cout << " = " << uang << " ";
    out(pilihan2);
} 