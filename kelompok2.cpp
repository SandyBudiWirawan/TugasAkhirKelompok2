#include <iostream>
#include <stdio.h>
#include <string.h>
#include <ctime>
#define MAX 10
using namespace std;

// Tampilan Struct
struct queue{
	
	int data[10];
	int awal, akhir;
	string tambahan[3]= {"Vacuum", "Shampoo", "Semir"};
	int harga[3]={20000, 10000, 15000};

}antrian;

// Fungsi Untuk Mengkosongkan Antrian
void init(){
	antrian.awal=-1;
	antrian.akhir=-1;
}

// Fungsi Untuk Mengecek Antrian
bool full(){
	if(antrian.akhir == MAX -1){
		return true;
	}
	else{
		return false;
	}
}

// Fungsi Untuk Mengecek Antrian
bool empty(){
	if(antrian.akhir == -1){
		return true;
	}else{
		return false;
	}
}

// Fungsi Menambahkan Antrian
void inQueue(){
	int elemen, *elemenx;
	elemenx = &elemen;
	cout << " Data yang akan dimasukkan : ";
	cin >> elemen;
	if (empty()){
		antrian.awal = 0;
		antrian.akhir = 0;
		antrian.data[antrian.awal]= *elemenx;
	}else{
		if(!full()){
			antrian.akhir++;
			cout << " Data Berhasil Ditambahkan\n";
			antrian.data[antrian.akhir]= *elemenx;
		}else{
		cout << " Antrian Penuh \n";
	}
	getchar();
	}
}

// Fungsi Untuk Mengahapus Antrian
void deQueue(){
	string jenisM;
	time_t now = time(0); // Fungsi Tanggal
	tm *ltm = localtime(&now);

	if(!empty()){
		int i;
		if (antrian.data[antrian.awal]==1){
			cout << "===== Nota Carwash =====";
			cout << "\nPaket 1. Cuci Manual";
			cout << "\nTanggal : "<< ltm->tm_mday << " / "<< 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << " ";
			cout << "\nJenis Mobil : ";
			cin >> jenisM;
			cout << "Total Pembayaran : Rp. 50.000 ";
			for(int i=0; i < antrian.akhir; i++){
				antrian.data[i] = antrian.data[i+1];
			}
		} else if (antrian.data[antrian.awal]==2){
			cout << "===== Nota Carwash =====";
			cout << "\nPaket 2. Cuci Hidrolik";
			cout << "\nTanggal : "<< ltm->tm_mday << " / "<< 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << " ";
			cout << "\nJenis Mobil : ";
			cin >> jenisM;
			cout << "Total Pembayaran : Rp. 60.000 ";
			for(i=antrian.awal; i < antrian.akhir; i++){
				antrian.data[i] = antrian.data[i+1];
					}
		}else if (antrian.data[antrian.awal]==3){
			cout << "===== Nota Carwash =====";
			cout << "\nPaket 3. Cuci Otomatis";
			cout << "\nTanggal : "<< ltm->tm_mday << " / "<< 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << " ";
			cout << "\nJenis Mobil : ";
			cin >> jenisM;
			cout << "Total Pembayaran : Rp. 80.000 ";
			for(i=antrian.awal; i < antrian.akhir; i++){
				antrian.data[i] = antrian.data[i+1];
			}
		}else if (antrian.data[antrian.awal]==4){
			cout << "===== Nota Carwash =====";
			cout << "\nPaket 4. Cuci Sistem Robotik";
			cout << "\nTanggal : "<< ltm->tm_mday << " / "<< 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << " ";
			cout << "\nJenis Mobil : ";
			cin >> jenisM;
			cout << "Total Pembayaran : Rp. 125.000 ";
			for(i=antrian.awal; i < antrian.akhir; i++){
			antrian.data[i] = antrian.data[i+1];
		}
	}
	antrian.akhir--;
}else{
	cout << " Antrian Kosong ";
}
getchar();
}

// Fungsi Untu Menampilkan Data
void tampilData(){
	int i;
	for(i=antrian.awal; i <= antrian.akhir; i++){
		cout << antrian.data[i]<< "[" << i << "] | ";
	}	
	cout << "\n";
}

// Fungsi Menghapus semua Antrian
void clear(){
	antrian.awal = -1;
	antrian.akhir = -1;
}

// Fungsi info Paket
void infoPaket(){
	char nama [4][30];
	strcpy(nama[0], "Vacuum Mobil");
	strcpy(nama[1], "Shampoo Salju");
	strcpy(nama[2], "Semir Ban");

	for(int a=0; a<4; a++){
		int j,bd;
		j=a;
		for(int k=a+1; k<3; k++){
			bd = strcmp(nama[j],nama[k]);
			if(bd==1) j=k; 
			//ngka Merupakan Sorting urut Data secara
//asnding,Untuk Descending ganti dengan -1
}
	if(j!=a){
		char temp[1][30]; // Swapping
		strcpy(temp[0],nama[j]);
		strcpy(nama[j],nama[a]);
		strcpy(nama[a],temp[0]);
	}
}

for (int i=0; i<3; i++){ // Menampilkan hasil
puts(nama[i]);
}

string dtCari, tambahan_ketemu;
bool ketemu = false;

cout << " Produk yang dicari : ";
cin >> dtCari;

for(int i=0; i<3; i++){
	if(antrian.tambahan[i] == dtCari){
		ketemu = true;
		tambahan_ketemu = antrian.tambahan[i];
	}
}

if (ketemu = true){
	cout << " Jasa Tambahan ditemukan!\n\n";
	cout << " Hasil Pencarian Jasa Tambahan " << tambahan_ketemu << ":" <<
endl;
	if(tambahan_ketemu=="Semir")
	cout << antrian.harga[2];
	if(tambahan_ketemu=="Shampoo")
	cout << antrian.harga[1];
	if(tambahan_ketemu=="Vacuum")
	cout << antrian.harga[0];
	}else{
		cout << " Menu tidak ditemukan!" << endl;
	}
}


// Main Program

int main(){
	int pilihan, elemen;

	cout << "========== CAR WASH ==========" << endl;
	cout << "== Paket 1. Cuci Standar == \n Rp. 50.0000,00";
	cout << "\n== Paket 2. Cuci Hidrolik == \n Rp. 60.0000,00";
	cout << "\n== Paket 3. Cuci Otomatis == \n Rp. 80.0000,00";
	cout << "\n== Paket 4. Cuci Sistem Robotic == \n Rp. 125.0000,00";
	init();

	do {

		cout << "\n\n====== TEAM 2 =====\n";
		cout << "===================\n";
		cout << " Menu Utama\n";
		cout << "===================\n";
		cout << "[1] Masukan Antrian \n[2] Pembayaran \n[3] Melihat Antrian\n[4] Jasa Tambahan \n[5] Menghapus Antrian \n[0] Keluar\n";

		cout << "===================\n";
		cout << " Masukkan Pilihan : ";
		cin >> pilihan;
		cout << "===================\n";
		switch(pilihan){
			case 1 : inQueue();
			break;
			case 2 : deQueue();
			break;
			case 3 : tampilData();
			break;
			case 4 : infoPaket();
			break;
			case 5 : clear();
			break;
			}
	}
while(pilihan!=0);
return 0;
}