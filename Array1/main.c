/*
 * Array 1 dimensi
 * Tujuan : 
 * Program ini menunjukan cara mendeklarasikan,
 * menginisialisasi, dan menampilkan array dimensi 1
 */

#include <stdio.h>
#include <string.h>

int main() {
	// deklarasi variabel A sebagai integer dengan 2 elemen
	// yang disebut index. Ibaratnya A adalah sebuah tempat
	// dengan 2 kotak (index 0 - 1) , yang masing-masing kotak
	// dapat diisi bilangan bertipe integer 
	int A[2]; 
	
	//isi kotak 0 dengan angka 10;
	A[0] = 10;
	//isi kotak 1 dengan angka 20;
	A[1] = 20;
	
	//cetak isi variabel A[]
	printf("Nilai dari array A adalah: \n");
	printf("Elemen A[0] : %d\n",A[0]);
	printf("Elemen A[1] : %d\n",A[1]);
	
	// deklarasi array dan inisialisasi
	int B[] = { 20,30,40,50,60 };
	
	// jika kita menghitung secara manual jumlah elemen B
	// maka kita ketahui bahwa elemennya adalah 5 (0 - 4)
	// kita dapat menghitung jumlah elemen dengan cara
	// menggunakan fungsi sizeof(). Karena array adalah bertipe int
	// maka total size B / size dari integer akan sama dengan jumlah elemen
	int jumlahElemenB = sizeof(B) / sizeof(int);
	// menampilkan isi B[] dengan perulangan
	printf("\nNilai dari array B adalah:\n");
	for(int i = 0; i<jumlahElemenB; i++)
		printf("Elemen B[%d] : %d\n",i,B[i]);
		
}
	