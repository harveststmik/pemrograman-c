#include <stdio.h>

void printBackward(char *);

int main() {
	printf("%d\n",sizeof(char **));
	printf("%d\n",sizeof(char *));
	
	char *s;
	size_t size;
	int n = 30;
	size = sizeof(char) * n;
	s = (char *) malloc(size);
	printf("\nMemory size : %d",size);

	//*(s+size) = '\0';
	s = strcpy(s,"Hello there");
	//s = (char *) realloc(s,)
	
	
	printf("\nStarting address: %p",s);
	printf("\nChar in address : %c",*(s+1));
	printBackward(s);
	free(s);
	
	
	/*
	char *s = "Hello There";
	char *p = "Joni";
	char **s1;
	s1 = (char **) malloc(2*sizeof(char *));
	*s1 = s;
	*(s1+1)=p; 
	//*(s1+1) = &p; 
	1
	printf("%p\n",s);
	printf("%p\n",*s1);
	printf("%s\n",*s1);
	printf("%s\n",*(s1+1));
	
	printf("%p\n",s1);
	printf("%p\n",s1+1);
	printf("%s",s1);
	free(s1);
	return 0;*/
}

void printBackward(char *s) {
	int i;
	printf("\n");
	for(i=strlen(s)-1; i>=0 ; i--) {
		printf("%c",*(s+i));
	}
}