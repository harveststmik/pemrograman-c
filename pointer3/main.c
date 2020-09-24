/*
 * Alokasi Memory dengan calloc()
 */
 
#include <stdio.h>

int main()
{
	// create p as pointer to integer
	int *p;
	// allocate memory for p using calloc()
	p = (int*) calloc(4,sizeof(int));
	//p = (int*) malloc(sizeof(int)*4);
	// print address, value using dereference and array format
	int i;
	printf("Alamat\t\t\tNilai\tNilai\n");
	for(i=0;i<4;i++) {
		printf("%p\t%d\t\%d\n",p+i,*(p+i),p[i]);
	}
	// assign value to p
	for(i=0;i<4;i++) *(p+i) = i;
	// print address, value using dereference and array format
	printf("Alamat\t\t\tNilai\tNilai\n");
	for(i=0;i<4;i++) {
		printf("%p\t%d\t\%d\n",p+i,*(p+i),p[i]);
	}	
	free(p);
	return 0;
}
