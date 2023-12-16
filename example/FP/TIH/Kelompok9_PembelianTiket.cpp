#include <iostream>				//Kelompok 9: 266_Rifky Afrizal Saputra, 275_Muhammad Ubaidillah, 284_James Natanael Aritonang
using namespace std;

int main(){
    int menu, hari, rute;
    string lanjut;
    string array[] = {" ","Senin","Selasa","Rabu","Kamis","Jumat","Sabtu","Minggu"};
    string rute1[] = {" ", "Mojokerto", "Sidoarjo", "Kediri", "Tulungagung", "Magetan"};
    string rute2[] = {" ", "Ciamis", "Jakarta", "Klaten", "Yogyakarta"};
    float lokal, antarKota, hasil, total, jumlah, diskon, uang;
    char name[30];
    string nik;
    
    do{
	    cout << "---------------------------------\n";
	    cout << " Selamat Datang Di GoTrain "<< endl;
	    cout << "---------------------------------\n";
	    
	    cout << "Hari Pemberangkatan: \n";
	    cout << " 1. Senin\n 2. Selasa\n 3. Rabu\n 4. Kamis\n 5. Jumat\n 6. Sabtu\n 7. Minggu\n";
	    puts("Input pilihan [1-7]");
	    cout << "Hari: ";
	    cin >> hari;
	    	if (hari>7){
	    		cout << "input anda salah"<<endl;
	    		break;
			}
	    cout << "\n";
	    
	    puts("Jenis Tiket");
	    puts("1. KA Lokal");
	    puts("2. KA Antar Kota");
	    puts("Input pilihan [1-2]");
	
	    cout << "Masukkan angka untuk memilih jenis tiket: ";
	    cin >> menu;
	    	if(menu>2){
	    		cout << "input anda salah"<<endl;
	    		break;
			}
	
	    cout << "\n";
	    switch(menu){
	
	        case 1:
	            puts ("Anda Memilih KA Lokal");
	            cout << "Silahkan Pilih Jadwal Pada Hari " << array[hari]<<endl;
	            puts("Asal - Tujuan: ");
	            puts("1. Surabaya - Mojokerto");
	            puts("2. Surabaya - Sidoarjo");
	            puts("3. Surabaya - Kediri");
	            puts("4. Surabaya - Tulungagung");
	            puts("5. Surabaya - Magetan");
	            puts("Input pilihan [1-5]");
	
	            cout << "Masukkan angka untuk memilih rute: ";
	            cin >> rute;
	            	if(rute>5){
	            		cout << "input anda salah"<<endl;
	    				break;
					}
	            cout << "\n";      
	            cout << "Anda memilih rute Surabaya - "<<rute1[rute]<<endl;
	            puts("Harga Tiket per Orang Rp. 15.000,-");
	            cout <<"Tiket yang anda pesan : ";
	            cin >> jumlah;
	            cout <<"\n";
				cout <<"Pengisian Data diri Penumpang \n";
		            for(int i = 0; i < jumlah; i++){
		                cout << "Nama: ";
		                fgets(name, 30, stdin);
                        cin.ignore();
                        
		                do{
                            cout << "NIK: ";
	                        cin>>nik;
                            if (nik.size() != 12){
                                cout << "NIK harus 12 digit" << endl;
	                        }
                        }while(nik.size() != 12);
						
						cout << "----------------------"<< endl;	 
					}
	
				        if(jumlah >= 5) {
				        	total = jumlah * 15000;
				        	diskon = total * 10/100;
				        	hasil = total - diskon;
                            cout<<"Nama : "<<name<<endl;
                            cout<<"NIK : "<<nik<<endl;
                            cout<<"Rute : "<<rute1[rute]<<endl;
                            cout<<"Jumlah Tiket : "<<jumlah<<endl;
				       		printf("Harga Tiket = Rp.15.000,-\n");
				        	printf("Total Harga Tiket = %.2f \n", hasil);
				        }
				        else {
				        	hasil = jumlah * 15000;
                            cout<<"Nama : "<<name<<endl;
                            cout<<"NIK : "<<nik<<endl;
                            cout<<"Rute : "<<rute1[rute]<<endl;
                            cout<<"Jumlah Tiket : "<<jumlah<<endl;
				        	printf("Maaf Anda Tidak Mendapatkan Diskon\n");
				        	printf("Total Harga Tiket = %.1f\n", hasil);
				        }
				        break;
				
	        case 2 :
			    puts("Anda Memilih KA Antar Kota");
	            cout << "Silahkan Pilih Jadwal Pada Hari " << array[hari]<<endl;
	            puts("Asal - Tujuan: ");
	            puts("1. Surabaya - Ciamis");
	            puts("2. Surabaya - Jakarta");
	            puts("3. Surabaya - Klaten");
	            puts("4. Surabaya - Yogyakarta");
	            puts("Input pilihan [1-4]");
	
	            cout << "Masukkan angka untuk memilih rute: ";
	            cin >> rute;
	            	if(rute>4){
	            		cout << "input anda salah"<<endl;
	    				break;
					}
	            cout << "\n";
	            cout << "Anda memilih rute Surabaya - "<<rute2[rute]<<endl;
	            puts("Harga Tiket per Orang Rp. 300.000,-");
	                cout << "Masukkan jumlah tiket yang Anda pesan : ";
	                cin >> jumlah;
		            printf("\n");
					puts( "Pengisian Data diri Penumpang");
			            for(int i = 0; i < jumlah;i++){
			                cout << "Nama: ";
		                	fgets(name, 30, stdin);
                            cin.ignore();
							cout << endl;
                            
                        do{
                            cout << "NIK: ";
	                        cin>>nik;
                            if (nik.size() != 12){
                                cout << "NIK harus 12 digit" << endl;
	                        }
                        }while(nik.size() != 12);
							cout << "----------------------"<< endl;
						
							
						}
					    if(jumlah >= 5) {
					    	total = jumlah * 300000;
					    	diskon = total * 5/100;
					    	hasil = total - diskon;
                            cout<<"Nama : "<<name<<endl;
                            cout<<"NIK : "<<nik<<endl;
                            cout<<"Rute : "<<rute2[rute]<<endl;
                            cout<<"Jumlah Tiket : "<<jumlah<<endl;
					    	printf("Harga Tiket = Rp.300.000,-\n ");
					    	printf("Total Harga Tiket = %.2f \n", hasil);
					    }
					    else {
					    	hasil = jumlah * 300000;
                            cout<<"Nama : "<<name<<endl;
                            cout<<"NIK : "<<nik<<endl;
                            cout<<"Rute : "<<rute2[rute]<<endl;
                            cout<<"Jumlah Tiket : "<<jumlah<<endl;
					    	printf("Maaf Anda Tidak Mendapatkan Diskon\n");
					    	printf("Total Harga Tiket = %.1f\n", hasil);
					    }
                        break;

			default:
				cout << "Inputan salah!!!"<<endl;
                break;
    }
    cout << endl;
    cout << "Silahkan lakukan pembayaran di stasiun yang anda tuju"<<endl;
	cout << "Apakah anda ingin melakukan transaksi lagi? (y/n)";
	cin >> lanjut;
	system("cls");
    }while(lanjut == "y");
	
}
