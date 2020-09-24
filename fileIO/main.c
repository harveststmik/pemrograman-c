#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char line[200];
char inputString(char *msg);

int main(int argc, char **argv)
{
	FILE *fp;
	char *file_name = "c:\\data\\tmp\\mahasiswa.txt";
	if(!(fp = fopen(file_name,"a"))) {
		printf("File tidak ditemukan atau tidak dapat dibuat");
		return -1;
	}
	char name[22];
	inputString("Nama : ");
	fgets(name,line);
	
	printf("Nama : %s",name);
	fputs(name,fp);
	fclose(fp);
	return 0;
}

char inputString(char *msg) {
	printf("%s",msg);
	fflush(stdin);
	fgets(line,sizeof(line),stdin);
	printf("%d",(int)strlen(line));
}
