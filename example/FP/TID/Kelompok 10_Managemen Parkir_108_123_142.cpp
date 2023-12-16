#include <iostream>
#include<windows.h>
#include <bits/stdc++.h> 
#include <ctime>
using namespace std;

const int MAX = 26;

string printRandomString(int n) 
{ 
    char alphabet[MAX] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 
                          'h', 'i', 'j', 'k', 'l', 'm', 'n',  
                          'o', 'p', 'q', 'r', 's', 't', 'u', 
                          'v', 'w', 'x', 'y', 'z' }; 
  
    string res = ""; 
    for (int i = 0; i < n; i++)  
        res = res + alphabet[rand() % MAX]; 
      
    return res; 
} 
int main (){
    time_t curr_time;
	curr_time = time(NULL);

	tm *tm_local = localtime(&curr_time);
    int lan = 2,stor = 3,bag = 4;
    //ini jmlh bisa di fix
    cout << "\n\nmasukan banyak lantai : ";
    cin >> lan;

    cout << "\n\nmasukan banyak bagian : ";
    cin >> stor;

    cout << "\n\nmasukan banyak tempat parkir per bagian : ";
    cin >> bag;

    int parktotal;
    int i = 0, j = 0, k = 0, x = 1, y = 1, pilihan, parkin, z = 0;
    parktotal = lan * stor * bag;
    string *ptr;
    string r[lan][stor][bag];//  = { 
    //                  { {"a", "a", "a", "a"}, {"a", "a", "a", "a"}, {"a", "a", "a", "a"} },
    //                  { {"a", "a", "a", "a"}, {"a", "a", "a", "a"}, {"a", "a", "a", "a"} }
    //          };
    while (i < lan)
    {                 
        while (j < stor)
        {
            while (k < bag)
            {
                r [i][j][k] = "a";
                k++;
                y++;
            }
            k=0;
            j++;
        }
        x++;
        j=0;
        i++;
    }    
    ptr = &r[0][0][0];
    
    cout << "\n\n\n                        Halo selamat datang di tempat parkir gedung UNESA \n"; Sleep(1000);
    cout << "                          silahkan di cek tempat parkir yang tersedia\n"; Sleep(1000);
    cout << "*a* Menandakan tempat parkir kosong atau Available *o* Menandakan tempat pakir telah digunakan atau Occupied \n\n"; Sleep(1000);

    i = 0, j = 0, k = 0, x = 1, y = 1;
    int n = 3, count = 0; 
    string Parcod[parktotal], codeinput,timer[parktotal];

    while (i < lan)
    {
        cout << "lantai " << x << " :\n";
        while (j < stor)
        {
            while (k < bag)
            {
                cout << "| " << y << "   " << r[i][j][k] << " |";
                k++;
                y++;
            }
            if (k == bag)
                {
                    cout << "   ";
                }
            k=0;
            j++;
        }
        if (j == stor)
        {
            cout << "\n\n";Sleep(1000);
        }
        x++;
        j=0;
        i++;
    }
    
    while (z == 0)
    {
        i = 0, j = 0, k = 0, x = 1, y = 1, count = 0;
        while (i < lan)
            {                    
                while (j < stor)
                {
                    while (k < bag)
                    {
                        if (r[i][j][k] == "a")
                        {
                            count++;
                        }
                         
                        k++;
                        y++;
                    }
                    k=0;
                    j++;
                }
            x++;
            j=0;
            i++;
            }
            if (count > 0)
            {
                while (z == 0)
                {
                    cout << "Silah kan ketik angka tempat parkir yang Available : ";
                    cin >> parkin;Sleep(1000);
                    cout << "\n";
                    parkin = parkin - 1;
                    if (*(ptr + parkin) == "o")
                    {
                        cout << "\n           Tempat parkir sudah di isi \n              mohon pilih yang lain \n\n";Sleep(1000);
                        break;
                    } 
                    else if (*(ptr + parkin) == "a") {

                    if (parkin == 0)
                    {
                        *ptr = "o";
                    } 
            
                    else if (parkin != 0 && parkin < lan * stor * bag) {
                        *(ptr + parkin) = "o";

                    }
            
            Parcod[parkin] = printRandomString(n) + to_string(tm_local->tm_min) + to_string(tm_local->tm_sec) + printRandomString(n);
            timer[parkin] = to_string(tm_local->tm_hour) +":"+ to_string(tm_local->tm_min);
            //cout << Parcod[parkin] << "\n\n";

            cout << "**************************************\n"<< "Tiket Parkir UNESA " << parkin + 1 << 
            "\nBiaya parkir\n Rp.5000\nkode parkir : " << Parcod[parkin] << "\n**************************************\n\n"; Sleep(3000);
            break;
                     } else if (parkin >= lan * stor * bag)
                    {
                        cout << "\n           maaf tempat ini tidak tersedia \n              mohon pilih yang lain \n\n";Sleep(1000);
                        break;
                    }
        
                }
            }else if (count == 0)
            {
                cout << "Tempat parkir penuh mohon tunggu yg keluar dari parkiran\n\n";
            }
            count = 0;
        
        while (z == 0)
        {
            cout << "*0* tutup program \n*1* parkir \n*2* keluar parkir \n*3* list tempat parkir kosong \n*4* jumblah mobil \n\n";
            cin >> pilihan;

            if (pilihan == 2)
            {   
                i = 0;

                cout << "Masukan kode parkir mu :\n";
                cin >> codeinput;
                cout << "\n";
                while (i < parktotal)
                {
                    if (codeinput == Parcod[i])
                    {
                        break;
                    }
                    i++;
                }
                if (i >= parktotal)
                {
                    cout << "kode yg anda masukan salah coba lagi\n"; Sleep(1000);
                } else if (i < parktotal)
                {
                    cout << "**************************************\n"<< "Tiket Parkir UNESA " << i + 1 << 
                    "\nBiaya parkir\n Rp.5000\nkode parkir : " << codeinput << "\n**************************************\n\n"; Sleep(1000);
                    cout << "oke terimakasih pembayaran tiket berhasil \n semoga kamu selalu selamat di jalan\n\n"; Sleep(2000);
                    //i--;
                    *(ptr + i) = "a";
                }else
                {
                     cout << "kode yg anda masukan salah coba lagi\n"; Sleep(1000);
                }
                
                
                
                

            }else if (pilihan == 3)
            {
                cout << "tempat parkir yg kosong adalah nomer :\n";
                i = 0, j = 0, k = 0, x = 1, y = 1;
                while (i < lan)
            {                    
                while (j < stor)
                {
                    while (k < bag)
                    {
                        if (r [i][j][k] == "a")
                        {
                            cout << y << "\n";
                        }
                        k++;
                        y++;
                    }
                    k=0;
                    j++;
                }
            x++;
            j=0;
            i++;
            }
                cout << "\n\n"; Sleep(2000);
            }
            else if (pilihan == 4)
            {
                cout << "mobil berada pada parkiran nomer :";
                i = 0, j = 0, k = 0, x = 1, y = 1, count = 0;
                while (i < lan)
                {
                    while (j < stor)
                    {
                        while (k < bag)
                        {
                            if (r[i][j][k] == "o")
                            {
                                cout << y;
                                count++;
                                Sleep(500);
                            }
                            
                            k++;
                            y++;
                        }
                        k=0;
                        j++;
                    }
                    x++;
                    j=0;
                    i++;
                }

                cout << "jumblah mobil yang ada di parkiran adalah : " << count; Sleep(1000);
            } else {
                break;
            }
            
            
        }
        
        if (pilihan == 1)
        {
            i = 0, j = 0, k = 0, x = 1, y = 1;
            while (i < lan)
            {
                cout << "lantai " << x << " :\n";
                while (j < stor)
                {
                    while (k < bag)
                    {
                        cout << "| " << y << "   " << r[i][j][k] << " |";
                        k++;
                        y++;
                    }
                    if (k == bag)
                    {
                        cout << "   ";
                    }
                    k=0;
                    j++;
                }
                if (j == stor)
                {
                    cout << "\n\n";Sleep(1000);
                }
                x++;
                j=0;
                i++;
            }
        }else if (pilihan == 0)
        {
            break;
        }
        
    }
    
}