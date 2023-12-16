#include <iostream>
#include <string>
using namespace std;


double konversi (double x, char x1, char y1){
    
    switch(x1){
        case 'C':
            if (y1 == 'F'){
                x = (x * 9.0 / 5.0) + 32.0;
            }
            if (y1 == 'K'){
                x += 273.15;
            }
            if (y1 == 'R'){
                x = x * 4/5;
            }
            else{
                x = x;
            }
        break;

        case 'R':
            if (y1 == 'C'){
                x = x * 5/4;
            }
            if (y1 == 'F'){
                x = (x * 9/4) + 32; 
            }
            if (y1 == 'K'){
                x = (x * 5/4) + 273.15;
            }
            else {
                x = x;
            }
        break;

        case 'F':
            if (y1 == 'C'){
                x = (x - 32) * 5/9;
            }
            if (y1 == 'R'){
                x = (x - 32) * 4/9;
            }
            if (y1 == 'K'){
                x = (x - 32) * 5/9 + 273.15;
            }
            else {
                x = x;
            }
        break;

        case 'K':
            if (y1 == 'C'){
                x = x - 273.15;
            }
            if (y1 == 'F'){
                x = (x - 273.15) * 9/5 + 32;
            }
            if (y1 == 'R'){
                x = (x - 273.15) * 4/5;
            }
            else {
                x = x;
            }
        break;

        default:
        break;
    }

    return x;
}


int main (){
    double a, b;
    char a1, b1, l;

    do{
        system("cls");
        do{
            cout << "Pilih tipe suhu (C / R / F / K)\n";
            cin >> a1;
            a1 = toupper(a1);

            if (a1 != 'C' && a1 != 'R' && a1 != 'F' && a1 != 'K'){
                system("cls");
                cout << "Salah pilihan\n";
                }
            }while(a1 != 'C' && a1 != 'R' && a1 != 'F' && a1 != 'K');
            cout << "Masukan suhu dalam " << a1 << endl;
            cin >> a;

        do{
            cout << "Pilih suhu konversi (C / R / F / K)\n";
            cin >> b1;
            b1 = toupper(b1);

            if (b1 != 'C' && b1 != 'R' && b1 != 'F' && b1 != 'K'){
            cout << "Salah pilihan\n";
                }
            }while(b1 != 'C' && b1 != 'R' && b1 != 'F' && b1 != 'K');

        b = konversi(a, a1, b1);
        cout << a <<" "<< a1 << " sama dengan " << b <<" "<< b1 << endl;

        cout << "Lanjut Konversi? (Y/N)\n";
        cin >> l;
        l = toupper(l);
        }while(l == 'Y');    
            system("cls");
}