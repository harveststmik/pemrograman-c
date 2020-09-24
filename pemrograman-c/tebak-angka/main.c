#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define true 1
#define false 0

int ambilBilanganAcak() {
	srand(time(NULL));
	return rand() % 100 + 1;
}

int ambilTebakan() {
	int bilangan = 0;
	do {
		printf("\nMasukan sebuah bilangan (1-100)");
		scanf("%d",&bilangan);
	} while (bilangan < 0 || bilangan > 100);
	return bilangan;
}

void beriPetunjuk(int selisih) {
	selisih = selisih < 0 ? selisih * -1 : selisih;
	char msg[100];
	if(selisih > 20) strcpy(msg,"Tebakanmu terlalu jauh");
	else if(selisih > 15) strcpy(msg,"Mmmm... masih agak jauh");
	else if(selisih > 10) strcpy(msg,"Bagus... agak dekat");
	else if(selisih > 5) strcpy(msg,"Oppsss... hampir...");
	else if(selisih > 1) strcpy(msg,"Yeah..... dikiiiitt lagi");
	else if(selisih == 0) 
		strcpy(msg,"\n##################\nGotcha! ... kamu berhasil\n#################\n");
	printf("\n%s\n",msg);
}

int main(int argc, char **argv)
{
	int debug = 1;
	int maxTebak = 10;
	char cobaLagi = 'Y';
	int jumlahTebak = 0;
	while(cobaLagi == 'Y')
	{
		int angkaMisteri = ambilBilanganAcak();
		int angkaTebak = 0;
		int selisih = 0;
		int gameBerakhir = false;
		while(!gameBerakhir) {
			jumlahTebak++;
			angkaTebak = ambilTebakan();
			selisih = angkaMisteri - angkaTebak;
			
			if(debug) {
				printf("\nselisih: %d - angka misteri: %d",selisih,angkaMisteri);
			}
			
			beriPetunjuk(selisih);
			
			if(jumlahTebak>maxTebak || selisih == 0) {
				if(jumlahTebak>maxTebak) 
					printf("\n########Game Over!########\n");
				gameBerakhir = true;
			}
		}
		char ulangi;
		fflush(stdin);
		printf("\n\nUlangi (y/t) ?");
		scanf("%c",&ulangi);
		if(ulangi == 'y') {
			cobaLagi = 'Y';
		}
		else {
			cobaLagi = 'T';
		}
	}
}

