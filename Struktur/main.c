#include <stdio.h>
#include <string.h>


struct mahasiswa {
	char nim[10];
	char nama[50];
	char jurusan[20];
};
typedef struct mahasiswa Mahasiswa;

int main()
{
	Mahasiswa mhs;
	
	strcpy(mhs.nama,"Jacob");
	strcpy(mhs.jurusan,"Teknologi Informasi");
	strcpy(mhs.nim,"12345");
	
	printf("nama : %s\n",mhs.nim);	
	printf("nama : %s\n",mhs.nama);
	printf("nama : %s\n",mhs.jurusan);
	return 0;
}
