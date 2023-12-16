#include <bits/stdc++.h>
#include <conio.h>
//conio.h hanya digunakan untuk string back _getch();
using namespace std;

string inA = "Masukan dimensi matriks A (n x m): ";
string inB = "Masukan dimensi matriks B (n x m): ";
string in2 = "Masukan dimensi matriks A dan B (n x m): ";
string inEli = "Masukan dimensi matriks A (n x m): ";
string inMa = "Masukan matriks A :\n";
string inMb = "Masukan matriks B :\n";
string outAdd = "Hasil dari perjumlahan matriks A + B:\n";
string outSub = "Hasil dari pengurangan matriks A - B:\n";
string outMul = "Hasil dari perkalian matriks A * B :\n";
string outTpose = "Tranpose dari matriks A:\n";
string outInvers = "Invers dari matriks A:\n";
string outDet = "Determinan dari matriks A = ";
string outRank = "Rank dari matriks A = ";
string back = "Tekan tombol apa saja untuk kembali...";

//input matrix
float **inMatrix(int n, int m) {
    float** a = new float*[n];
    for(int i = 0; i < n; i++) {
        a[i] = new float[m];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    return a;
}

//output matrix
void outMatrix(int n, int m, float **a) {
    bool koma = false;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] != floorf(a[i][j])) {
                koma = true;
                break;
            }
        }
        if(koma) {
            break;
        }
    }
    if(koma) {
        cout << fixed << setprecision(2);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
} 

//determinan
float det(int n, float **a) {
    if(n == 2) {
        return a[0][0] * a[1][1] - a[1][0] * a[0][1];
    }
    else {

        float pembagi = pow(a[0][0], n - 2);

        int nbaru = n - 1;

        float **b = new float*[nbaru];
        for(int i = 0; i < nbaru; i++) {
            b[i] = new float[nbaru];
        }

        for(int i = 0; i < nbaru; i++) {
            for(int j = 0; j < nbaru; j++) {
                b[i][j] = a[0][0] * a[i + 1][j + 1] - a[i + 1][0] * a[0][j + 1];
            }
        }
        return det(nbaru, b) / pembagi;
    }
}

//tambah dan kurang
float **addsub(int n, int m, float **a, float **b, int opsi) {
    float **c = new float*[n];
    for(int i = 0; i < n; i++) {
        c[i] = new float[m];
    }

    if(opsi == 1) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                c[i][j] = a[i][j] + b[i][j];
            }
        }
    }
    else {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                c[i][j] = a[i][j] - b[i][j];
            }
        }
    }
    return c;
    
}

//perkalian
float **multiple(int n, int m, int p, float **a, float **b) {
    float **c = new float*[n];
    for(int i = 0; i < n; i++) {
        c[i] = new float[m];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < p; j++) {
            for(int k = 0; k < m; k++) {
                if(k == 0) {
                    c[i][j] = 0;
                }
                c[i][j] = c[i][j] + (a[i][k] * b[k][j]);
            }
        }
    }
    return c;
}

//tranpose
float **tranpose(int n, int m, float **a) {

    float **temp = new float*[m];
    for(int i = 0; i < m; i++) {
        temp[i] = new float[n];
    }
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            temp[i][j] = a[j][i];
        }
    }

    return temp;
}

//invers
float **inverse(int n, float **a) {
    if(n == 2) {
        float **temp = new float*[n];
        for(int i = 0; i < n; i++) {
            temp[i] = new float[n];
        }
        temp[0][0] = a[1][1];
        temp[1][1] = a[0][0];
        temp[1][0] = -a[1][0];
        temp[0][1] = -a[0][1];

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                temp[i][j] /= det(n, a);
            }
        }
        return temp;
    }
    else {
        float **kof = new float*[n];
        for(int i = 0; i < n; i++) {
            kof[i] = new float[n];
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                
                float **minor = new float*[n];
                for(int t = 0; t < n; t++) {
                    minor[t] = new float[n];
                }
                int mbar = 0;
                int mkol = 0;

                for(int k = 0; k < n; k++) {
                    if(k != i) {
                        mkol = 0;
                        for(int l = 0; l < n; l++) {
                            if(l != j) {
                                minor[mbar][mkol] = a[k][l];
                                mkol++;
                            }
                        }
                        mbar++;
                    }
                }
                kof[i][j] = ((i + j) % 2 == 0 ? 1 : -1) * det(n - 1, minor);
            }
        }

        float **adj = tranpose(n, n, kof);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                adj[i][j] /= det(n, a);
            }
        }
        return adj;
    }
}

//input cramer
float *inCramer(int n) {
    float *cr = new float[n];
    for(int i = 0; i < n; i++) {
        cin >> cr[i];
    }
    return cr;
}

//eliminasi cramer
float cramer(int n, float **a, float *cr, int kolom) {
    float **temp = new float*[n];
    for(int i = 0; i < n; i++) {
        temp[i] = new float[n];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            temp[i][j] = a[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        temp[i][kolom] = cr[i];
    }
    
    return det(n, temp) / det(n, a);
}

//gauss
float **gauss(int n, int m, float **a) {
    for(int i = 0; i < n; i++) {
        float bagi = a[i][i];
        //agar diagonal matriks 1
        for(int j = 0; j < m; j++) {
            a[i][j] /= bagi;
        }

        for(int k = i + 1; k < n; k++) {
            float kali = a[k][i];
            for(int j = 0; j < m; j++) {
                a[k][j] -= kali * a[i][j];
            }
        }
    }
    return a;
}

//rank
int ranks(int n, int m, float **a) {
    int r = n;
    
    for(int i = 0; i < n; i++) {
        bool check = true;
        for(int j = 0; j < m; j++) {
            if(a[i][j] != 0) {
                check = false;
            }
        }
        if(check) {
            r--;
        }
    }

    return r;

}


int main() {
    cout << R"(  _  __     _ _          _       _               __  __       _        _ _        
 | |/ /    | | |        | |     | |             |  \/  |     | |      (_) |       
 | ' / __ _| | | ___   _| | __ _| |_ ___  _ __  | \  / | __ _| |_ _ __ _| | _____ 
 |  < / _` | | |/ / | | | |/ _` | __/ _ \| '__| | |\/| |/ _` | __| '__| | |/ / __|
 | . \ (_| | |   <| |_| | | (_| | || (_) | |    | |  | | (_| | |_| |  | |   <\__ \
 |_|\_\__,_|_|_|\_\\__,_|_|\__,_|\__\___/|_|    |_|  |_|\__,_|\__|_|  |_|_|\_\___/
  Kelompok 7 TID23: Eksa_115; Dimas_129; Bisma_135.)"<< '\n';
    while(true) {
        int n, m, p, q, hasil;
        float **a, **b;
        float *cr; //untuk cramer

        cout << R"(
1. Penjumlahan 2 Matriks
2. Pengurangan 2 Matriks
3. Perkalian Matriks
4. Tranpose Matriks
5. Invers Matriks
6. Determinant Matriks
7. Matriks Rank
8. Matriks Eliminasi Cramer
9. Credits
0. Keluar
Note: Saat input dimensi cukup masukan angkanya saja.
Pilih operasi matriks: )";
        int select;
        cin >> select;
        switch(select) {
            case 0: return 0;

            case 1: //case 1 masuk ke case 2
            case 2:
            cout << in2;
            cin >> n >> m;
            cout << inMa; a = inMatrix(n, m);
            cout << inMb; b = inMatrix(n, m);
            if(select == 1) {
                //perjumlahan
                cout << outAdd; outMatrix(n, m, addsub(n, m, a, b, select));
            }
            else {
                //pengurangan
                cout << outSub; outMatrix(n, m, addsub(n, m, a, b, select));
            }
            cout << back; _getch();
            break;

                case 3:
                do {
                    cout << inA; cin >> n >> m;
                    cout << inB; cin >> p >> q;
                    if(m != p) {
                        cout << "Perkalian matriks harus memiliki kolom A dan baris B yang sama!\n";
                    }
                }while(m != p);
                cout << inMa; a = inMatrix(n, m);
                cout << inMb; b = inMatrix(p, q);

                //multiple
                hasil = 3;
                cout << outMul; outMatrix(n, q, multiple(n, m, q, a, b));
                cout << back; _getch();
                break;

            case 4:
            cout << inA; cin >> n >> m;
            cout << inMa; a = inMatrix(n, m);

            //transpose
            cout << outTpose; outMatrix(m, n, tranpose(n, m, a));
            cout << back; _getch();
            break;

                case 5:
                cout << inA;
                do {
                    cin >> n >> m;
                    if(n != m) cout << "Baris dan kolom matriks harus sama! Coba lagi: ";
                }while(n != m);
                cout << inMa; a = inMatrix(n, m);
                if(det(n, a) == 0) {
                    cout << "Invers tidak bisa dicari karena memiliki determinan 0!\n" << back; _getch();
                    break;
                }

                //invers
                cout << outInvers; outMatrix(n, n, inverse(n, a));
                cout << back; _getch();
                break;

            case 6:
            cout << inA;
            do {
                cin >> n >> m;
                if(n != m) cout << "Baris dan kolom matriks harus sama! Coba lagi: ";
            }while(n != m);
            cout << inMa; a = inMatrix(n, m);

            //det
            cout << fixed << setprecision(2);
            cout << outDet << det(n, a) << endl;
            cout << back; _getch();
            break;

                case 7:
                cout << inA; cin >> n >> m;
                cout << inMa; a = inMatrix(n, m);

                //rank
                cout << outRank << ranks(n, m, gauss(n, m, a)) << endl;
                cout << back; _getch();
                break;

            case 8:
            cout << inEli;
            do {
                cin >> n >> m;
                if(n != m) cout << "Baris dan kolom matriks harus sama! Coba lagi: ";
            }while(n != m);
            cout << inMa; a = inMatrix(n, m);
            if(det(n, a) == 0) {
                    cout << "Invers tidak bisa dicari karena memiliki determinan 0!\n" << back; _getch();
                    break;
            }
            cout << "Masukan "<< n <<" konstanta :\n"; cr = inCramer(n);

            //eliminasi
            cout << "Masing-masing x dalam matriks:\n";
            for(int i = 0; i < n; i++) {
                cout << "x" << i + 1 << " = " << cramer(n, a, cr, i) << endl;
            }
            cout << back; _getch();
            break;
            
            case 9:
            cout << R"(
  _  __     _ _          _       _               __  __       _        _ _        
 | |/ /    | | |        | |     | |             |  \/  |     | |      (_) |       
 | ' / __ _| | | ___   _| | __ _| |_ ___  _ __  | \  / | __ _| |_ _ __ _| | _____ 
 |  < / _` | | |/ / | | | |/ _` | __/ _ \| '__| | |\/| |/ _` | __| '__| | |/ / __|
 | . \ (_| | |   <| |_| | | (_| | || (_) | |    | |  | | (_| | |_| |  | |   <\__ \
 |_|\_\__,_|_|_|\_\\__,_|_|\__,_|\__\___/|_|    |_|  |_|\__,_|\__|_|  |_|_|\_\___/
 
 void tugas(int *project, string Pemograman_Dasar) {
    struct kamiDari {
           int kelompok = 7;
        string jurusan  = "Teknik Informatika";
           int semester = 1;
          char kelas    = 'D';
    };
    string anggota[3] = {
        "Mohammad Eksa Hardian - 23051204115",
        "Bisma Adhiaksa - 23051204135"'
        "Dhimas Ananda Ruswanto - 23051204129"
    };
            
 cout <<
 "Kami yakin dengan hasil karya kami (eksa) ini akan sangat membantu para mahasiswa\n"
                                                                       <<  "- Dhimas";
            )";
            
            cout << back; _getch();
            break;
            default:
            cout << "Pilih angka sesuai dengan yang di list!";
            break;
            
            
        }
    }
}