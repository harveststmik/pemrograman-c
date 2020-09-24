/*
 * Pointer in Action
 * Kasus 1: Menukar nilai 
 * Program berikut merupakan contoh bagaimana pointer
 * digunakan untuk saling menukarkan nilai dengan menggunakan
 * referensi alamat dari variabel tersebut.
 * Program ini juga memberi contoh eksekusi fungsi dengan referensi
 * atau call by reference
 */

#include <stdio.h>

int tukar(int*,int*);

int main()
{
	int a,b;
	printf("Input nilai a : "); scanf("%d",&a);
	printf("Input nilai b : "); scanf("%d",&b);
	printf("\nNilai sebelum ditukar : a=%d, b=%d",a,b);
	tukar(&a,&b);
	printf("\nNilai setelah ditukar : a=%d, b=%d",a,b);
	
	int i[] = {2,3,5,7};
	int *p = &i[0];
	int *k = {7,8,9,10};
	
	printf("\n%d",*(p+3)); 
	// printf("\n%d",p[3])); 
	return 0;
}

int tukar(int* c, int* d) {
	*c = *c + *d;
	*d = *c - *d;
	*c = *c - *d;
}
