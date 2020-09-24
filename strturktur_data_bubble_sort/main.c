/*
 * Promram 1.2
 */
#include <stdio.h>
 
void cetak(int*, int);

int main() {
    int angka[] = { 4, 3, 7, 2, 6, 8, 5, 1 };
    int elemen = sizeof(angka)/sizeof(angka[0]);
    cetak(angka,elemen);
    for(int i=0; i<elemen-1; i++) {
        for(int k=0; k<elemen-i-1; k++) {
            if(angka[k]>angka[k+1]) {
                angka[k] = angka[k] + angka[k+1];
                angka[k+1] = angka[k] - angka[k+1];
                angka[k] = angka[k] - angka[k+1];
            }
        }
        cetak(angka,elemen);
    }
    
}

void cetak(int *angka, int elemen) {
    static int loop=0;
    printf("Loop %d: ", loop); loop++;
    for(int c=0;c<elemen;c++) printf("%d\t",angka[c]);
    printf("\n");
}
 
//#include <stdio.h>
//
//void urutkan(int *angka, int jumlah_elemen, int fase) {
//    int puncak = jumlah_elemen - fase; 
//    int indeks = 0;
//    do {
//        if(angka[indeks]>angka[indeks+1]) {
//            //tukar nilai
//            angka[indeks] = angka[indeks] + angka[indeks+1];
//            angka[indeks+1] = angka[indeks] - angka[indeks+1];
//            angka[indeks] = angka[indeks] - angka[indeks+1];
//        }
//        indeks++;
//    } while(indeks<puncak);
//}
//
//int main() {
//        
//    int angka[] = { 3, 5, 2, 4, 6, 1 };
//    int jumlah_elemen = sizeof(angka)/sizeof(int); // jumlah_elemen = 6;
//    int jumlah_fase = jumlah_elemen - 1; // fase = 5
//    int fase = 1;
//    do {
//        urutkan(angka,jumlah_elemen,fase);
//        printf("Urutan fase %d : ",fase);
//        for(int i=0; i<jumlah_elemen; i++) printf("%d\t", angka[i]);
//        printf("\n");    
//        fase++;
//    } 
//    while(fase<=jumlah_fase);    
//}


//int main() {
//	int jumlah_elemen = 6;
//	int angka[] = { 3, 5, 2, 4, 6, 1 };
//    
//    printf("Sebelum disortir: ");
//    for (int i=0; i<jumlah_elemen; i++) printf("%d\t",angka[i]); 
//    printf("\n");
//    
//	for(int i=0; i<jumlah_elemen - 1; i++) { // ulangi selama i < 5
//		if(angka[i] > angka[i+1]) {
//			// tukar jika angka[i] > angka[i+1]
//			angka[i] = angka[i]+angka[i+1];
//			angka[i+1] = angka[i] - angka[i+1];
//			angka[i] = angka[i] - angka[i+1];
//		} 
//	}
//    printf("Sesudah disortir: ");
//    for (int i=0; i<jumlah_elemen; i++) printf("%d\t",angka[i]); 
//    printf("\n");
//}

//void cetak(int*, int);
//
//int main() {
//    int angka[] = { 4, 3, 7, 2, 6, 8, 5, 1 };
//    int elemen = sizeof(angka)/sizeof(angka[0]);
//    cetak(angka,elemen);
//    for(int i=0; i<elemen-1; i++) {
//        for(int k=0; k<elemen-i-1; k++) {
//            if(angka[k]>angka[k+1]) {
//                angka[k] = angka[k] + angka[k+1];
//                angka[k+1] = angka[k] - angka[k+1];
//                angka[k] = angka[k] - angka[k+1];
//            }
//        }
//        cetak(angka,elemen);
//    }
//    
//}
//
//void cetak(int *angka, int elemen) {
//    static int loop=0;
//    printf("Loop %d: ", loop); loop++;
//    for(int c=0;c<elemen;c++) printf("%d\t",angka[c]);
//    printf("\n");
//}


//void tukar(int *a, int *b) {
//    *a = *a + *b;
//    *b = *a - *b;
//    *a = *a - *b;
//}
//
//void cetak(int *angka, int elemen) {
//    static int loop=0;
//    printf("Loop %d: ", loop); loop++;
//    for(int c=0;c<elemen;c++) printf("%d\t",angka[c]);
//    printf("\n");
//}
//
//
//void bubbleSort(int *angka, int elemen) {
//    cetak(angka,elemen);
//    for(int i=0; i<elemen-1; i++) {
//        for(int k=0; k<elemen-i-1; k++) {
//            if(angka[k]>angka[k+1]) tukar(angka+k,angka+k+1);
//        }
//        cetak(angka,elemen);
//    }
//}
//
//int main()
//{
//    int angka[] = { 4, 3, 7, 2, 6, 8, 5, 1 };
//    int elemen = sizeof(angka)/sizeof(angka[0]);
//    bubbleSort(angka,elemen);
//    return 0;
//}
