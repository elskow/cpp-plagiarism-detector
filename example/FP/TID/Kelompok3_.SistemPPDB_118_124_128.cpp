#include<bits/stdc++.h>

using namespace std;


//prestasi scaling 1, 5, 7, 10?

struct Prestasi{
    int kabupaten;
    int provinsi;
    int nasional;
    int internasional;
    int point = 0;
};

struct Siswa{
    string nama;
    float nilai;
    Prestasi prestasi;
};



int quota = 10;


void swapFloat(float *a, float *b){
    float temp = *a;
    *a = *b;
    *b = temp;
}   

void swapString(string *a, string *b){
    string temp = *a;
    *a = *b;
    *b = temp;
}

void swapInt(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//print for loop but rekursion
void printList(Siswa siswa[], int n, int limit){
    if(n == limit){
        return;
    }
    else{
        cout << siswa[n].nama << endl;
        n++;
        return printList(siswa, n, limit);
    }
}



int main(){
    ifstream myFile("data.txt");
    string temp;

    int count = 0;


    //Menghitung jumlah data(baris yang ada pada data)
    while(getline(myFile, temp)){
        count++;
    }    

    Siswa siswa[count];
    

    //Kembali ke awal file
    myFile.clear();
    myFile.seekg(0, ios::beg);     


    //Ambil data
    for(int i = 0; i < count; i++){
        getline(myFile, temp);

        //ambil data nilai
        string tempNilai = temp.substr(temp.find("Nilai: ") + 7);
        tempNilai = tempNilai.substr(0, tempNilai.find(','));
        siswa[i].nilai = stof(tempNilai);

        //data prestasi
        string tempPrestasiKabupaten = temp.substr(temp.find("Kabupaten: ") + 11);
        tempPrestasiKabupaten = tempPrestasiKabupaten.substr(0, tempPrestasiKabupaten.find(','));
        siswa[i].prestasi.kabupaten = stoi(tempPrestasiKabupaten);
        siswa[i].prestasi.point += siswa[i].prestasi.kabupaten * 2;

        string tempPrestasiProvinsi = temp.substr(temp.find("Provinsi: ") + 10);
        tempPrestasiProvinsi = tempPrestasiProvinsi.substr(0, tempPrestasiProvinsi.find(','));
        siswa[i].prestasi.provinsi = stoi(tempPrestasiProvinsi);
        siswa[i].prestasi.point += siswa[i].prestasi.provinsi * 5;


        string tempPrestasiNasional = temp.substr(temp.find("Nasional: ") + 10);
        tempPrestasiNasional = tempPrestasiNasional.substr(0, tempPrestasiNasional.find(','));
        siswa[i].prestasi.nasional = stoi(tempPrestasiNasional);
        siswa[i].prestasi.point += siswa[i].prestasi.nasional * 7;

        string tempPrestasiInternasional = temp.substr(temp.find("Internasional: ") + 15);
        siswa[i].prestasi.internasional = stoi(tempPrestasiInternasional);
        siswa[i].prestasi.point += siswa[i].prestasi.internasional * 10;



        siswa[i].nama = temp.substr(6, temp.find(',') - 6);
    }


    while(true){
        
        cout << R"(Pilih yang ingin anda lakukan: 
1. Sort siswa berdasarkan nilai 
2. Sort siswa berdasarkan prestasi
3. Tampilkan siswa yang mempunyai nilai paling tinggi
4. Tampilkan siswa yang paling berprestasi
5. Lihat data salah satu anak
6. Keluar)"
<< endl;
        cout << endl;
        
        int pilihan;
        cin >> pilihan;
        cin.ignore();
    

        switch(pilihan){

            case 1:{
                //sort berdasarkan nilai
                for(int i = count; i > 1; i--){
                    for(int j = count - 1; j > 0; j--){
                        if(siswa[j].nilai > siswa[j - 1].nilai){
                            swapFloat(&siswa[j].nilai, &siswa[j - 1].nilai);
                            swapString(&siswa[j].nama, &siswa[j - 1].nama);
                            swapInt(&siswa[j].prestasi.point, &siswa[j - 1].prestasi.point);
                            swapInt(&siswa[j].prestasi.kabupaten, &siswa[j - 1].prestasi.kabupaten);
                            swapInt(&siswa[j].prestasi.provinsi, &siswa[j - 1].prestasi.provinsi);
                            swapInt(&siswa[j].prestasi.nasional, &siswa[j - 1].prestasi.nasional);
                            swapInt(&siswa[j].prestasi.internasional, &siswa[j - 1].prestasi.internasional);

                        }
                    }
                }

                cout << "Siswa yang diterima adalah: " << endl;
                printList(siswa, 0, count - quota);
                cout << endl;

                break;
            }

            case 2:{
                //sort berdasarkan prestasi
                for(int i = count; i > 1; i--){
                    for(int j = count - 1; j > 0; j--){
                        if(siswa[j].prestasi.point > siswa[j - 1].prestasi.point){
                            swapFloat(&siswa[j].nilai, &siswa[j - 1].nilai);
                            swapString(&siswa[j].nama, &siswa[j - 1].nama);
                            swapInt(&siswa[j].prestasi.point, &siswa[j - 1].prestasi.point);
                            swapInt(&siswa[j].prestasi.kabupaten, &siswa[j - 1].prestasi.kabupaten);
                            swapInt(&siswa[j].prestasi.provinsi, &siswa[j - 1].prestasi.provinsi);
                            swapInt(&siswa[j].prestasi.nasional, &siswa[j - 1].prestasi.nasional);
                            swapInt(&siswa[j].prestasi.internasional, &siswa[j - 1].prestasi.internasional);
                        }
                    }
                }

                cout << "Siswa yang diterima adalah: " << endl;
                printList(siswa, 0, count-quota);
                cout << endl;

                break;

            }
            case 3:{
                for(int i = count; i > 1; i--){
                    for(int j = count - 1; j > 0; j--){
                        if(siswa[j].nilai > siswa[j - 1].nilai){
                            swapFloat(&siswa[j].nilai, &siswa[j - 1].nilai);
                            swapString(&siswa[j].nama, &siswa[j - 1].nama);
                            swapInt(&siswa[j].prestasi.point, &siswa[j - 1].prestasi.point);
                            swapInt(&siswa[j].prestasi.kabupaten, &siswa[j - 1].prestasi.kabupaten);
                            swapInt(&siswa[j].prestasi.provinsi, &siswa[j - 1].prestasi.provinsi);
                            swapInt(&siswa[j].prestasi.nasional, &siswa[j - 1].prestasi.nasional);
                            swapInt(&siswa[j].prestasi.internasional, &siswa[j - 1].prestasi.internasional);

                        }
                    }
                }

                cout << "Siswa yang memiliki nilai tertinggi adalah " << siswa[0].nama << " dengan nilai " << siswa[0].nilai << endl;
                break;
            }
            case 4:{
                for(int i = count; i > 1; i--){
                    for(int j = count - 1; j > 0; j--){
                        if(siswa[j].prestasi.point > siswa[j - 1].prestasi.point){
                            swapFloat(&siswa[j].nilai, &siswa[j - 1].nilai);
                            swapString(&siswa[j].nama, &siswa[j - 1].nama);
                            swapInt(&siswa[j].prestasi.point, &siswa[j - 1].prestasi.point);
                            swapInt(&siswa[j].prestasi.kabupaten, &siswa[j - 1].prestasi.kabupaten);
                            swapInt(&siswa[j].prestasi.provinsi, &siswa[j - 1].prestasi.provinsi);
                            swapInt(&siswa[j].prestasi.nasional, &siswa[j - 1].prestasi.nasional);
                            swapInt(&siswa[j].prestasi.internasional, &siswa[j - 1].prestasi.internasional);
                        }
                    }
                }

                cout << "Siswa yang paling berprestasi adalah: " << siswa[0].nama << " dengan poin prestasi " << siswa[0].prestasi.point << endl;
                break;
            }

            case 5:{
                bool found = false;
                while(!found){
                    cout << "Input nama yang ingin dicari " << endl;
                    string search;
                    getline(cin, search);
                    cout << endl;
                    for(int i = 0; i < count; i++){
                        if(siswa[i].nama == search){
                            found = true;
                            cout << "Nilai " << siswa[i].nama << endl;
                            cout << siswa[i].nilai << endl;
                            cout << endl;
                            cout << "Prestasi " << siswa[i].nama << endl;
                            cout << "Poin prestasi: ";
                            cout << siswa[i].prestasi.point << endl;
                            cout << "Tingkat Kabupaten: ";
                            cout << siswa[i].prestasi.kabupaten << endl;
                            cout << "Tingkat Provinsi: ";
                            cout << siswa[i].prestasi.provinsi << endl;
                            cout << "Tingkat Nasional: ";
                            cout << siswa[i].prestasi.nasional << endl;
                            cout << "Tingkat Internasional: ";
                            cout << siswa[i].prestasi.internasional << endl;
                            cout << endl;
                        }
                    }
                    
                    if(found){
                        break;
                    }
                    else{
                        cout << "Nama siswa tidak bisa ditemukan" << endl;
                    }
                }
                break;
            }

            case 6:{
                //apabila pilih 6 code akan langsung selesai
                return 0;
            }


            default:{
                cout << "Silahkan input angka yang sudah disediakan" << endl;
                break;
            }
        }
    }
}