/*-------------------------------------------------
 * Pointer in Action
 * Kasus 2
 * Program ini mendemonstrasikan hubungan antara
 * pointer dan array
 * Bukti bahwa char *a == char a[]
 *------------------------------------------------*/

#include <stdio.h>

void printString(char *);
void printBackward(char *);

int main() {
	char nama[] = "Wage Rudolf Supratman";
	char* p1 = nama;
	char* p2 = &nama[0];
	char* p3 = nama + 5;
	char* p4 = &nama[5];
		
	printf("\np1 point to address %p",p1);
	printf("\np2 point to address %p",p2);
	printf("\np3 point to address %p",p3);
	printf("\np4 point to address %p",p4);
	
	printf("\n\nChar in p1 address is : %c",*p1);
	printString(p1);
	printf("\n%s",nama);
	printBackward(p2);

	printf("\n\nChar in p4 address is : %c",*p4);
	printf("\nChar in p1[5] index : %c",p1[5]);
	printString(p4);
	printf("\n%s",p4);
	printBackward(p4);
	char c = getchar();
	return 0;
}

void printString(char *s) {
	int c;
	printf("\nPrinting All character by its address\n");
	printf("starting from address : %p\n",s);
	for(c = 0; c < strlen(s); c++)
		printf("%c",*(s+c));
}

void printBackward(char *s) {
	int i;
	printf("\n");
	for(i=strlen(s)-1; i>=0 ; i--) {
		printf("%c",*(s+i));
	}
}