#include<iostream>
#include<limits>
using namespace std;
int x=0;

void header()
{	
	cout<<"=========================================================================="<<endl;
	cout<<"=                              QUIZ GAME                                 = "<<endl;
	cout<<"=========================================================================="<<endl;
}

void clearBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void waitForEnter() {
    std::cout << "Tekan Enter untuk memulai kuis...";
    clearBuffer();
}

void footer(){		
	cout<<"========================================================================="<<endl;
	cout<<"=                              RESULTS                                  ="<<endl;
	cout<<"========================================================================="<<endl;
}

void user(){
	char ch1[100];
	cout<<"\t\t ================================"<<endl;
	cout<<"\t\t Masukan Nama Anda: ";
	cin.getline(ch1,100);
	cout<<"\t\t ================================"<<endl;
	cout<<"\t\t Selamat Datang  "<<ch1<<endl;
}

void results(){
	if(x==100)
	cout<<" \t Jangan curang...... Anda juga telah melakukan ini sebelumnya ;)."<<endl;
	if(x==90)
	cout<<" \t Anda sangat cerdas. Skor Anda 90"<<endl;
	if(x==80)
	cout<<" \t Anda cerdas. Skor Anda 80"<<endl;
	if(50==x||x==70||x==60)
	cout<<" \t skor rata rata anda adalah "<< x <<" coba lagi"<<endl;
	else if(x<=40)
	cout<<" \t skor anda di bawah rata rata..mungkin anda kurang beruntung;)"<<endl;	
	cout<<"\t Total skor anda adalah\t:"<<x<<endl;
	}

// program utama

int main()
{
	char jwb2;
	user();
	header();
	waitForEnter();
	

	cout<<"\t 1. Berapa jumlah 2+2 ?";
	cout<<" \n\t a.4 \n\t b.5 \n\t c.-2 "<<endl;
	cout<<"jawaban anda: ";
	cin>>jwb2;
	if(jwb2=='a'){
		x=x+10;
		cout<<" \t bagus! score kamu adalah: "<<x<<endl;
	}
	else if (jwb2 == 'b' || jwb2 == 'c') {
        cout << "\t Maaf Jawaban anda salah." << endl;
    }
	else {
        cout << "\t Maaf Jawaban anda tidak ada di opsi" << endl;
    }

	cout<<"\t 2. Pengguna Komputer,operator Komputer,Programmer ? ";
	cout<<"\t\n\t a.Hardwere \n\t b.Softwere \n\t c.Brainwere "<<endl;
	cout<<"jawaban anda: ";
	cin>>jwb2;
	if(jwb2=='c'){
		x=x+10;
		cout<<" \t hebat! score kamu adalah: "<<x;
	}
	else if (jwb2 == 'b' || jwb2 == 'a') {
        cout << "\t Maaf Jawaban anda salah." << endl;
    }
	else {
        cout << "\t Maaf Jawaban anda tidak ada di opsi" << endl;
    }
 cout<<endl;

	cout<<"\t 3. Media Penyimpanan Data?"; 
	cout<<"\n\t a.Scanner \n\t b.Hardisk \n\t c.Printer"<<endl;
	cout<<"jawaban anda: ";
	cin>>jwb2;
	if(jwb2=='b'){
		x=x+10;
		cout<<" \t luar biasa! score kamu adalah: "<<x;
	}
	else if (jwb2 == 'c' || jwb2 == 'a') {
        cout << "\t Maaf Jawaban anda salah." << endl;
    }
	else {
        cout << "\t Maaf Jawaban anda tidak ada di opsi" << endl;
    }
cout<<endl;

	cout<<"\t 4. Setiap perintah dalam projek C++ selalu diakhiri dengan?";
	cout<<" \n\t a.{} \n\t b.; \n\t c.! "<<endl;
	cout<<"jawaban anda: ";
	cin>>jwb2;
	if(jwb2=='b')
	{
		x=x+10;
		cout<<" \t menakjubkan! score kamu adalah: "<<x;	
	}
	else if (jwb2 == 'c' || jwb2 == 'a') {
        cout << "\t Maaf Jawaban anda salah." << endl;
    }
	else {
        cout << "\t Maaf Jawaban anda tidak ada di opsi" << endl;
    }
	cout<<endl;

	cout<<"\t 5. Data yang harus diberikan pada komputer disebut?";
	cout<<" \n\t a.Input \n\t b.Output \n\t c.Start"<<endl;
	cout<<"jawaban anda: ";
	cin>>jwb2;
	if(jwb2=='a'){
		x=x+10;
		cout<<" \t menakjubkan! score kamu adalah: "<<x;
	}
	else if (jwb2 == 'c' || jwb2 == 'b') {
        cout << "\t Maaf Jawaban anda salah." << endl;
    }
	else {
        cout << "\t Maaf Jawaban anda tidak ada di opsi" << endl;
    }
	cout<<endl;

	cout<<"\t 6. Pseudocode yang dipakai dalam penulisan algoritma adalah?";
	cout<<" \n\t a.Bahasa Pemrograman \n\t b.Bahasa Latin \n\t c.Bahasa Arab"<<endl;
	cout<<"jawaban anda: ";
	cin>>jwb2;
	if(jwb2=='a'){
		x=x+10;
		cout<<" \t menakjubkan! score kamu adalah: "<<x;
	}
	else if (jwb2 == 'c' || jwb2 == 'b') {
        cout << "\t Maaf Jawaban anda salah." << endl;
    }
	else {
        cout << "\t Maaf Jawaban anda tidak ada di opsi" << endl;
    }
	cout<<endl;

	cout<<" \t 7. Menggambarkan program secara logika merupakan fungsi dari?";
	cout<<" \n\t a.Sistem Operasi \n\t b.Begin \n\t c.Flowchart"<<endl;
	cout<<"jawaban anda:";
	cin>>jwb2;
	if(jwb2=='c')
	{
		x=x+10;
		cout<<" \t menakjubkan! score kamu adalah: "<<x;
	}
	else if (jwb2 == 'a' || jwb2 == 'b') {
        cout << "\t Maaf Jawaban anda salah." << endl;
    }
	else {
        cout << "\t Maaf Jawaban anda tidak ada di opsi" << endl;
    }
	cout<<endl;

	cout<<"\t 8. Berikut ini yang bukan termasuk bahasa pemrogaman adalah?";
	cout<<" \n\t a.C++ \n\t b.Notepad \n\t c.Java"<<endl;
	cout<<"jawaban anda:";
	cin>>jwb2;
	if(jwb2=='b')
	{
		x=x+10;
		cout<<" \t menakjubkan! score kamu adalah: "<<x;
	}
	else if (jwb2 == 'c' || jwb2 == 'a') {
        cout << "\t Maaf Jawaban anda salah." << endl;
    }
	else {
        cout << "\t Maaf Jawaban anda tidak ada di opsi" << endl;
    }
	cout<<endl;

	cout<<"\t 9. Cin dalam program C++ untuk? ";
	cout<<"\n\t a.Menginput Data \n\t b.Membuat Program \n\t c.Menghasilakan Output "<<endl;
	cout<<"jawaban anda:";
	cin>>jwb2;
	if(jwb2=='a')
	{
		x=x+10;
		cout<<" \t menakjubkan! score kamu adalah: "<<x;
	}
	else if (jwb2 == 'c' || jwb2 == 'b') {
        cout << "\t Maaf Jawaban anda salah." << endl;
    }
	else {
        cout << "\t Maaf Jawaban anda tidak ada di opsi" << endl;
    }
	cout<<endl;

	cout<<"\t 10. Untuk menampilkan hasil yang sudah di input pada program c++ disebut?";
	cout<<" \n\t a.Input \n\t b.Proses \n\t c.Output"<<endl;
	cout<<"jawaban anda:";
	cin>>jwb2;
	if(jwb2=='c')
	{
		x=x+10;
		cout<<" \t menakjubkan! score kamu adalah: "<<x<<endl;
	}
	else if (jwb2 == 'b' || jwb2 == 'a') {
        cout << "\t Maaf Jawaban anda salah." << endl;
    }
	else {
        cout << "\t Maaf Jawaban anda tidak ada di opsi" << endl;
    }

	footer();
	results();
    return 0;
}