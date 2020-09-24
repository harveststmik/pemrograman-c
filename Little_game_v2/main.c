#include <stdio.h>
#include <time.h>

#define TRUE 1;
#define FALSE 0;

int nyawaPemain, nyawaLawan;
int lawan;
int aksiLawanTerakhir,aksiPemainTerakhir;

const char daftarLawan[][30] = { 
	"Jaka Tingkir", 
	"Jaka Sembung", 
	"Damarwulan"
};

int ambilAksiAcak() {
	int aksi = rand() % 2 + 1;
	return aksi;
}

void cetakKarakter(char kode, int jumlah) {
	int i;
	printf("\n");
	for(i=0;i<jumlah;i++) printf("%c",kode);
}

int ambilAksiPemain() {
	int aksi;
	cetakKarakter('\xB0',41);
	printf("\n\xb0 (1) Pukul    (2) Tendang (3) Bertahan \xb0");
	printf("\n\xb0 (4) Menyerah (5) Auto                 \xb0");
	cetakKarakter('\xB0',41);
	do {
		printf("\nPilihanmu (1 - 4): ");
		scanf("%d",&aksi);
	} while (aksi<1 || aksi>5);
	return aksi;
}


int  pukul(p) {
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
}

void bertahan(int p) {
	// belum di implementasikan
}

void serang(int aksi,int p) {
	switch(aksi) {
		case 1: pukul(p);break;
		case 2: tendang(p);break;
		case 3: bertahan(p);break;	
	}	
}

void lakukanAksi(int aksiLawan,int aksiPemain) {
	int giliranSerang = rand() % 2 + 1;
	if (giliranSerang == 1) {
		serang(aksiLawan,1);
		if(nyawaPemain>0) {
			serang(aksiPemain,2);
		}
	}
	else {
		serang(aksiPemain,2);
		if(nyawaLawan>0) {
			serang(aksiLawan,1);
		}
	}
}

void akhirPermainan(int aksiTerkahir) {
	if(aksiTerkahir == 4) {
		printf("\n\nKamu melarikan diri");
		printf("\nKamu kalah");
	} else {
		printf("\n\nPertandingan berlangsung seru");
		if(nyawaPemain>0) {
			printf("\nSelamat, kamu menang!");
		}
		else {
			printf("\nSayang sekali, kamu kalah!");
		}
	}
}

int pilihLawan() {
	int i;
	printf("\nDaftar Lawan");
	for (i=0;i<3;i++) {
		printf("\n%d. %s",i,daftarLawan[i]);
	}
}

void mulaiPermainan() {
	cetakJudul();
	lawan = pilihLawan();
	nyawaLawan = 100;
	nyawaPemain = 100;
	infoPermainan();
}

void infoPermainan() {
	cetakKarakter('\xb0',41);
	printf("\nNyawa Lawan : %d",nyawaLawan);
	printf("\nNyawamu     : %d",nyawaPemain);
	cetakKarakter('\xb0',41);
	cetakKarakter('\n',1);
}


void cetakJudul() {
	printf("*******************************\n");
	printf("*     CONSOLE FIGHTER V1.1    *\n");
	printf("*******************************\n");
	printf("*Copyright(2016) STMIK Harvest*\n");
	printf("*******************************\n");
}

int main()
{
	int aksiPemain, aksiLawan;
	int permainanSelesai;
	int autoBattle = FALSE;
	mulaiPermainan();
	aksiPemain = 0;
	srand(time(NULL));
	do { 
		aksiLawan = ambilAksiAcak();
		if(aksiPemain == 5) autoBattle = TRUE;
		if(autoBattle) aksiPemain = ambilAksiAcak();
		else aksiPemain = ambilAksiPemain();
		lakukanAksi(aksiLawan,aksiPemain);
		infoPermainan();
		permainanSelesai = nyawaLawan<1 || nyawaPemain<1;
	} while(!permainanSelesai && aksiPemain != 4);
	akhirPermainan(aksiPemain);
	return 0;
}
