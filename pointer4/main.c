#include <stdio.h>

void getString(char *msg,char *s) {
	char c;
	int i = 0;
	fflush(stdin);
	fflush(stdout);
	printf("%s",msg);
	do {
		c = getchar();
		if(c != '\n') *(s+i) = c;
		i++;
	} while(c != '\n');
}

int main()
{
	char *s;
	s = (char *) malloc(100*sizeof(char));
	printf("\nLength of s : %d",strlen(s));
	getString("\nNama : ",s);
	printf("\nLength of s : %d",strlen(s));
	s = realloc(s,strlen(s));
	printf("\n%s",s);
	free(s);
	return 0;
}
