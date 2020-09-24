#include <stdio.h>
#include <stdlib.h>

char *InputString(char *msg,int size) {
	char *s;
	s = calloc(size,sizeof(char));
	printf("%s",msg);
	fgets(s,size,stdin);
	return s;
}

int main() {
	
	...
	
	free(nama);
	free(alamat);
}
