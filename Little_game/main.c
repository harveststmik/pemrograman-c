#include <stdio.h>
#include <stdlib.h>

int nyawaPemain, nyawaLawan;  

int ambilAksiLawan() {
	int aksi = rand() % 2 + 1;
	return aksi;
}

int ambilAksiPemain() {
	int aksi;
	printf("================\n");
	printf("Pilih Aksimu: \n");
	printf("================\n");
	printf("1. Pukul\n");
	printf("2. Tendang\n");
	printf("3. Bertahan\n");
	printf("4. Menyerah\n");
	printf("================\n");
	do {
		printf("Pilihanmu (1 - 4): ");
		scanf("%d",&aksi);
	} while (aksi<1 || aksi > 4);
	return aksi;
}


int  pukul(int p) {
	int kerusakan;
	kerusakan = rand() % 5 + 5;
	switch(p) {
		case 1: 
			nyawaPemain = nyawaPemain - kerusakan;
			break;
		case 2: 
			nyawaLawan = nyawaLawan - kerusakan;
			break;
	}
	return kerusakan;
}

int tendang(int p) {
	int kerusakan;
	kerusakan = rand() % 10 + 3;
	switch(p) {
		case 1: 
			nyawaPemain = nyawaPemain - kerusakan;
			break;
		case 2: 
			nyawaLawan = nyawaLawan - kerusakan;
			break;
	}
	return kerusakan;
}

void bertahan(int p) {
	// belum di implementasikan
}

void infoPermainan() {
	printf("Nyawa Lawan : %d\n",nyawaLawan);
	printf("Nyawamu     : %d\n",nyawaPemain);
}

void mulaiPermainan() {
	nyawaLawan = 100;
	nyawaPemain = 100;
}

void doBattle(int aksi,int p) {
	switch(aksi) {
		case 1: pukul(p);break;
		case 2: tendang(p);break;
		case 3: bertahan(p);break;
	}
}

void akhirPermainan(int aksiTerkahir) {
	if(aksiTerkahir == 4) {
		printf("Kamu melarikan diri\n");
		printf("Kamu kalah");
	} else {
		printf("Pertandingan berlangsung seru\n");
		if(nyawaPemain>0) {
			printf("Selamat, kamu menang!");
		}
		else {
			printf("Sayang sekali, kamu kalah!");
		}
	}
}

int main()
{
	int aksiPemain, aksiLawan;
	int permainanSelesai;
	
	mulaiPermainan();
	do { 
		srand(time(NULL));
		aksiLawan = ambilAksiLawan();
		aksiPemain = ambilAksiPemain();
		doBattle(aksiLawan,1);
		doBattle(aksiPemain,2);
		infoPermainan();
		permainanSelesai = nyawaLawan<1 || nyawaPemain<1;
	} while(!permainanSelesai && aksiPemain != 4);
	akhirPermainan(aksiPemain);
	return 0;
}
