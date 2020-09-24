/*
 * Aplikasi Struktur dengan pointer
 * ==================================*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct mahasiswa {
	char *nim;
	char *nama;
	char *jurusan;
};
typedef struct mahasiswa Mahasiswa;

char *inputString(char *msg) {
	fflush(stdin);
	printf("%s",msg);
	int n = 0;
	char c;
	char *s =  (char *)calloc(100,sizeof(char));
	do {
		c = getchar();
		if(c != '\n') *(s+n) = c;
		n++;
	} while(c != '\n');
	return s;
}

Mahasiswa *createMahasiswa(char *nim, char *nama, char *jurusan) {
	Mahasiswa *m = (Mahasiswa*)calloc(1,sizeof(Mahasiswa));
	m->nim = strdup(nim);
	m->nama = strdup(nama);
	m->jurusan = strdup(jurusan);
	return m;
}

int main()
{
	Mahasiswa *mahasiswa;
	Mahasiswa **listMahasiswa;
	
	int jumlahMahasiswa;
	printf("Input jumlah mahasiswa: ");
	scanf("%d",&jumlahMahasiswa);
	
	if(jumlahMahasiswa>5) jumlahMahasiswa = 5;
	if(jumlahMahasiswa<1) jumlahMahasiswa = 1;
	
	listMahasiswa = calloc(jumlahMahasiswa,(sizeof(Mahasiswa *)));
	
	int n;
	for(n=0;n<jumlahMahasiswa;n++) {
		printf("Data mahasiwa ke : %d\n",n+1);
		char *nama = inputString("Nama : ");
		char *nim = inputString("Nim : ");
		char *jurusan = inputString("Jurusan : ");
		
		mahasiswa = createMahasiswa(nim,nama,jurusan);
		listMahasiswa[n] = mahasiswa;
	}
	
	printf("\nCetak Data:");
	printf("\n=========================================");
	for(n=0;n<jumlahMahasiswa;n++) {
		printf("\n\nData mahasiswa ke : %d\n",(n+1));
		printf("Nim : %s\n",listMahasiswa[n]->nim);
		printf("nama : %s\n",listMahasiswa[n]->nama);
		printf("Jurusan : %s\n",listMahasiswa[n]->jurusan);
		free(listMahasiswa[n]);	
	}
	free(listMahasiswa);
	return 0;
}
