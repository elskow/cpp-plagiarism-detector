#include <iostream>
#include <string>

using namespace std;

int getPilihan(){
    int input;
    system("cls");

    cout << "\nPenghitung Berat Badan Ideal" <<endl;
    cout << "===============================" <<endl;
    cout << "1. Kalkulator BMI" <<endl;
    cout << "2. Rumus Broca" <<endl;
    cout << "3. Selesai "<<endl;
    cout << "===============================" <<endl;
    cout << "Pilih [1-3] ";
    cin >> input;
    return input;


}

int main(){

int pilihan = getPilihan();
char is_gender,is_lanjut;
float tinggi,berat,beratideal,konversitinggi,tinggi2;
enum pilihan{Kalkulator = 1, Rumus, kelar};

while (pilihan !=kelar){
 switch (pilihan){
    case Kalkulator:
    cout << "Kalkulator BMI" <<endl;
    cout << "=====================" <<endl;
   cout << "Masukkan Tinggi Badan (CM) :" ;
    cin >> tinggi;
    cout << "Masukkan Berat Badan (KG) :" ;
    cin >> berat;
konversitinggi = tinggi/100;
tinggi2 = konversitinggi*konversitinggi;
beratideal = berat/tinggi2;
cout << "=====================" <<endl;
if (beratideal >= 0 && beratideal <= 18.4){
    cout << beratideal << " Berat badan kurang" << endl;
}else if (beratideal >= 18.5 && beratideal <=24.9){
    cout <<beratideal << " Berat badan ideal" <<endl;
}else if (beratideal >= 25 && beratideal <29.9){
    cout <<beratideal << " Berat badan berlebih" <<endl;
}else{
    cout << beratideal << " obesitas" <<endl;
}
cout << "=====================" <<endl;
    break;

    case Rumus:
     cout << "==================" <<endl;
    cout << "Rumus Broca" <<endl;
    cout << "Masukkan jenis kelamin anda" <<endl;
    cout << "Perempuan (F)" <<endl;
    cout << "Laki-laki (M)" << endl;
    cout << "==================" <<endl;
    cout << "Jenis kelamin anda adalah : ";
    cin >> is_gender;
    if ((is_gender == 'f')| (is_gender == 'F')){
        cout << ""<<endl;
        cout << "Masukkan Tinggi Badan (CM) : " ;
    cin >> tinggi;
        tinggi2= tinggi - 100;
        konversitinggi = tinggi2*15/100;
        beratideal = tinggi2 - konversitinggi;
        cout << "berat ideal anda adalah :" << beratideal <<endl;

    }else if ((is_gender == 'm')| (is_gender == 'M')){
                cout << ""<<endl;
         cout << "Masukkan Tinggi Badan (CM) : " ;
    cin >> tinggi;
         tinggi2= tinggi - 100;
        konversitinggi = tinggi2*10/100;
        beratideal = tinggi2 - konversitinggi;
        cout << "berat ideal anda adalah " << beratideal <<endl;
    }

    break;
    default :
    cout << "mohon pilih salah satu" <<endl;
    break;
 }
label_continue:

cout  << "Menghitung lagi ?(y/n) : ";
cin >> is_lanjut;
if ((is_lanjut == 'y')| (is_lanjut == 'Y')){
    pilihan = getPilihan();
}else if ((is_lanjut == 'n')| (is_lanjut == 'N')){
 break;
}else {
    goto label_continue;
}
}
cout <<"===========================================" <<endl;
cout << "terima kasih telah menggunakan program" <<endl;

return 0;
}
