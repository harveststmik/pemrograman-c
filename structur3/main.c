/*
 * Aplikasi Struktur dengan pointer
 * 
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

char *inputString(char *msg);
Mahasiswa *createMahasiswa(char *nim, char *nama, char *jurusan);
char ambilAksi();
void tambahMahasiswa();
void editMahasiswa(char *s,char *replacement);
void hapusMahasiswa(char *s);
FILE *bukaFile(char *fn,char *mode);

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

char ambilAksi() {
	char *stringMenu[] = {"Tambah","Edit","Hapus","Lihat","Cari","Selesai"};
	int nmenu = (int) sizeof(stringMenu)/sizeof(stringMenu[0]);
	int c;
	char pilih;
	do {
		fflush(stdin);
		printf("\n\nMenu Utama\n");
		for(c=0;c<nmenu;c++) {
			printf("%d. %s\n",c+1,stringMenu[c]);
		}
		printf("Pilihanmu [1..%d]: ",nmenu);
		scanf("%d",&pilih);
	} while(pilih<0 || pilih>nmenu);
	return pilih;
}

void simpanMahasiswa(Mahasiswa *m) {
	FILE *fp = bukaFile("c:\\data\\tmp\\mahasiswa.txt","a");
	if(!fp) return;
	char separator = '|';
	fputs(m->nim,fp);
	putc(separator,fp);
	fputs(m->nama,fp);
	putc(separator,fp);
	fputs(m->jurusan,fp);
	putc('\n',fp);
	fclose(fp);
}

void tambahMahasiswa() {
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
		char *nim = inputString("Nim : ");
		char *nama = inputString("Nama : ");
		char *jurusan = inputString("Jurusan : ");
		
		mahasiswa = createMahasiswa(nim,nama,jurusan);
		listMahasiswa[n] = mahasiswa;
	}
	for(n=0;n<jumlahMahasiswa;n++) {
		simpanMahasiswa(listMahasiswa[n]);
		free(listMahasiswa[n]);
	}
	free(listMahasiswa);
}

void cariMahasiswa(char *s) {
	FILE *fp = bukaFile("c:\\data\\tmp\\mahasiswa.txt","r");
	if(!fp) return;
	char line[200];
	char data[3][100];
	int found = 0,baris = 0;
	while((fgets(line,200,fp)) != NULL)  {
		int i=0,c=0,y=0;
		while((data[i][c] = line[y]) != '\n') {
			if(data[i][c] == '|') {
				data[i][c] = '\0';
				i++;
				c = -1;
			}
			y++;
			c++;
		}
		data[i][c] = '\0';
		baris++;
		if(strcmp(data[1],s) == 0) {
			found = 1;
			printf("\n%d baris data telah dipindai...",baris);
			printf("\n\nData yang anda cari adalah:");
			printf("\nNim     : %s",data[0]); //nim
			printf("\nNama    : %s",data[1]); //nama
			printf("\nJurusan : %s",data[2]); //jurusan
			printf("\n\nTekan sembarang tombol untuk melanjutkan");
			getch();
			break;
		}
	}
	if(!found) {
		printf("\n%d baris data telah dipindai...",baris);
		printf("\n\nData tidak ditemukan");
		printf("\n\nTekan sembarang tombol untuk melanjutkan");
		getch();
	}
}

void hapusMahasiswa(char *s) {
	FILE *fp = bukaFile("c:\\data\\tmp\\mahasiswa.txt","r");
	if(!fp) return;
	char buffer[200][200];
	char line[200];
	char data[3][100];
	int found = 0,baris = 0;
	while((fgets(line,200,fp)) != NULL)  {
		int i=0,c=0,y=0;
		while((data[i][c] = line[y]) != '\n') {
			if(data[i][c] == '|') {
				data[i][c] = '\0';
				i++;
				c = -1;
			}
			y++;
			c++;
		}
		data[i][c] = '\0';
		baris++;
		if(strcmp(data[1],s) == 0) {
			found = 1;
		} else {
			strcpy(buffer[baris-1],line);
		}
	}
	fclose(fp);
	if(found) {
		FILE *fp = bukaFile("c:\\data\\tmp\\mahasiswa.txt","w");
		if(!fp) return;
		int count;
		for(count = 0;count<baris;count++) {
			fputs(buffer[count],fp);
		}
		fclose(fp);
		printf("\n\nData sudah dihapus");
		printf("\n\nTekan sembarang tombol untuk melanjutkan");
	} else  {
		printf("\n%d baris data telah dipindai...",baris);
		printf("\n\nData tidak ditemukan");
		printf("\n\nTekan sembarang tombol untuk melanjutkan");
		getch();
	}
}

void editMahasiswa(char *s,char *replacement) {
	FILE *fp = bukaFile("c:\\data\\tmp\\mahasiswa.txt","r");
	if(!fp) return;
	char buffer[200][200];
	char line[200];
	char data[3][100];
	int found = 0,baris = 0;
	while((fgets(line,200,fp)) != NULL)  {
		int i=0,c=0,y=0;
		while((data[i][c] = line[y]) != '\n') {
			if(data[i][c] == '|') {
				data[i][c] = '\0';
				i++;
				c = -1;
			}
			y++;
			c++;
		}
		data[i][c] = '\0';
		baris++;
		if(strcmp(data[1],s) == 0) {
			strcat(data[0],"|");
			strcat(data[0],replacement);
			strcat(data[0],"|");
			strcat(data[0],data[2]);
			strcat(data[0],"\n");
			strcpy(buffer[baris-1],data[0]);
			found = 1;
		} else {
			strcpy(buffer[baris-1],line);
		}
	}
	fclose(fp);
	if(found) {
		FILE *fp = bukaFile("c:\\data\\tmp\\mahasiswa.txt","w");
		if(!fp) return;
		int count;
		for(count = 0;count<baris;count++) {
			fputs(buffer[count],fp);
		}
		fclose(fp);
		printf("\n\nData sudah diganti");
		printf("\n\nTekan sembarang tombol untuk melanjutkan");
	} else  {
		printf("\n%d baris data telah dipindai...",baris);
		printf("\n\nData tidak ditemukan");
		printf("\n\nTekan sembarang tombol untuk melanjutkan");
		getch();
	}
}

FILE *bukaFile(char *fn,char *mode) {
	FILE *fp;
	if(!(fp = fopen(fn,mode))) {
		printf("\nFile tidak ditemukan atau tidak dapat dibuat");
		printf("\n\nTekan sembarang tombol...");
		getch();
		return NULL;
	}
	return fp;
}

void lihatMahasiswa() {
	FILE *fp = bukaFile("c:\\data\\tmp\\mahasiswa.txt","r");
	if(!fp) return;
	char line[200];
	printf("\nData Mahasiswa\n");
	printf("===============\n");
	while((fgets(line,200,fp)) != NULL)  {
		printf("%s",line);
	}
	printf("\n\nTekan sembarang tombol untuk melanjutkan");
	fflush(stdin); getch();
}

int main()
{
	char pilih;
	char *nama;
	char *replacement;
	do {
		pilih = ambilAksi();
		switch(pilih) {
			case 1:
				tambahMahasiswa(); 
				break;
			case 2:
				nama = inputString("Nama yang akan diedit : ");
				replacement = inputString("Nama yang seharusnya: ");
				editMahasiswa(nama,replacement);
				break;
			case 3:
				nama = inputString("Nama : ");
				hapusMahasiswa(nama);
				break;
			case 4:
				lihatMahasiswa();
				break;
			case 5:
				nama = inputString("Nama : ");
				cariMahasiswa(nama);
				break;
		}
	} while(pilih != 6);
	return 0;
}