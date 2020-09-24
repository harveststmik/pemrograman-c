#include <stdio.h>

char* getString(char *msg) {
	char c;
	int i = 0;
	char* s;
	s = (char*) malloc(100 * sizeof(char));
	fflush(stdin);
	printf("%s",msg);
	do {
		c = getchar();
		if(c != '\n') *(s+i) = c;
		i++;
	} while(c != '\n');
	s = (char*) realloc(s,strlen(s));
	return s;
}

int main()
{
	char **anggota;
	int c,i;
	printf("Jumlah anggota : ");
	scanf("%d",&c);
	i = 0;
	anggota = (char**) malloc(c * sizeof(char *));
	if(anggota != NULL)
	do {
		*(anggota+i) = getString("Nama anggota: ");
		i++;
	} while(i<c);
	for(int i=0;i<c;i++) {
		printf("\n%s",*(anggota+i));
		free(*(anggota+i));
	}
	free(anggota);
	return 0;
}
