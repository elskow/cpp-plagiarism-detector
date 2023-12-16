#include <iostream>
#include <string>
using namespace std;

const string NAMA = "doni";
const string NIM ="123";

struct Book{
    string judul;
    string penulis;
    int stok;
};

int main(){
    cout<<"SELAMAT DATANG DI PERPUSTAKAAN SEDERHANA KAMI!"<<endl;
    cout<<"**********************************************"<<endl;

    cout<<"Masukkan Nama : ";
    string nama;
    cin>>nama;

    cout<<"Masukkan NIM : ";
    string nim;
    cin>>nim;

    if (nama != NAMA || nim != NIM){
        cout<<"Username atau password yang Anda masukkan salah. Silahkan coba lagi."<<endl;
        return 0;
    }

    cout<<"Anda telah berhasil login!"<<endl;
    cout<<"=========================="<<endl;
    
    Book books[100];
    int bookCount = 0;

    while (true){
        cout<<"Daftar menu yang tersedia : "<<endl;
        cout<<"1. Input buku"<<endl;
        cout<<"2. Daftar buku"<<endl;
        cout<<"3. Peminjaman"<<endl;
        cout<<"4. Pengembalian"<<endl;
        cout<<"5. Laporan"<<endl;
        cout<<"6. Exit"<<endl;

        int menu;
        cout<<"Pilih menu yang Anda inginkan : ";
        cin>>menu;
        cout<<"================================"<<endl;

        if (menu == 1){
            //Input buku
            cout<<"Masukkan judul buku : ";
            string judul;
            cin.ignore();
            getline(cin,judul);

            cout<<"Masukkan nama penulis : ";
            string penulis;
            getline(cin,penulis);

            cout<<"Masukkan jumlah stok : ";
            int stok;
            cin>>stok;

            cout<<"======================="<<endl;

            books[bookCount].judul = judul;
            books[bookCount].penulis = penulis;
            books[bookCount].stok = stok;
            bookCount++;

        }
        else if (menu == 2){
            //Daftar buku
            cout<<"Daftar buku yang tersedia : "<<endl;
            
            for (int i = 0; i < bookCount; i++){
                cout<<i + 1<<". "<<books[i].judul<<" - "<<books[i].penulis<<" - "<<books[i].stok<<" stok"<<endl;
            }
            cout<<"======================="<<endl;
        }
        else if (menu == 3){
            //Peminjaman
            cout<<"Masukkan nomor buku yang ingin dipinjam : ";
            int bookNomor;
            cin>>bookNomor;

            if (bookNomor < 1 || bookNomor > bookCount){
                cout<<"Nomor yang Anda Masukkan salah. Silahkan coba lagi."<<endl;
                continue;
            }
            if (books[bookNomor - 1].stok == 0){
                cout<<"Maaf, stok buku tersebut saat ini kosong. Silahkan coba lagi nanti."<<endl;
                continue;
            }
            books[bookNomor - 1].stok--;
            cout<<"Buku berhasil dipinjam. Junlah stok saat ini : "<<books[bookNomor - 1].stok<<"."<<endl;
            cout<<"======================="<<endl;
        }
        else if (menu == 4){
            //Pengembalian
            cout<<"Masukkan nomor buku yang ingin dikembalikan : ";
            int bookNomor;
            cin>>bookNomor;

            if (bookNomor < 1 || bookNomor > bookCount){
                cout<<"Nomor buku yang Anda masukkan salah. Silahkan coba lagi."<<endl;
                continue;
            }
            books[bookNomor - 1].stok++;
            cout<<"Buku berhasil dikembalikan. Jumlah stok saat ini : "<<books[bookNomor - 1].stok<<"."<<endl;
            cout<<"======================="<<endl;
        }
        else if (menu == 5){
            //Laporan
            int totalStok = 0;

            for (int i = 0; i < bookCount; i++){
                    totalStok += books[i].stok;
            }
            cout<<"Total stok saat ini : "<<totalStok<<"."<<endl;
            cout<<"======================"<<endl;
        }
        else if (menu == 6){
            //exit
            break;
        }
        else {
            cout<<"Menu yang Anda Masukkan salah. Silahkan coba lagi."<<endl;
        }
    }
}
/* NAMA KELOMPOK
1. Cleo Alya Khairunnisa_23051204273
2. Devira Mutiara Widya Nugraha_23051204258
3. Hilmi Alwan_23051204259
*/
