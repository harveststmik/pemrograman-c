#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct mahasiswa {
	char nim[10];
	char nama[50];
	char jurusan[20];
};
typedef struct mahasiswa Mahasiswa;

void inputString(char *msg,char *s) {
	fflush(stdin);
	printf("%s",msg);
	int n = 0;
	char c;
	do {
		c = getchar();
		if(c != '\n') *(s+n) = c;
		n++;
	} while(c != '\n');
}

int main()
{
	int jumlahMahasiswa;
	printf("Input jumlah mahasiswa: ");
	scanf("%d",&jumlahMahasiswa);
	
	if(jumlahMahasiswa>5) jumlahMahasiswa = 5;
	if(jumlahMahasiswa<1) jumlahMahasiswa = 1;
	
	Mahasiswa mhs[jumlahMahasiswa];
	
	int n;
	char *s;
	s = (char *) calloc(100,sizeof(char));
	for(n=0;n<jumlahMahasiswa;n++) {
		printf("Data mahasiwa ke : %d\n",n+1);
		inputString("Nim : ",s);
		strcpy(mhs[n].nim,s);
		inputString("Nama : ",s);
		strcpy(mhs[n].nama,s);
		inputString("Jurusan : ",s);
		strcpy(mhs[n].jurusan,s);
	}
	free(s);
	for(n=0;n<jumlahMahasiswa;n++) {
		printf("\nMahasiswa ke : %d\n",n+1);
		printf("Nim : %s\n",mhs[n].nim);	
		printf("nama : %s\n",mhs[n].nama);
		printf("Jurusan : %s\n",mhs[n].jurusan);
	}
	
	return 0;
}
