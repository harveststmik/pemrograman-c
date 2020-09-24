#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define TRUE 1

void separator() {
    printf("==================================\n");
}

void msg(char* msg) {
    printf("%s\n",msg);
    for(int i=0;i<strlen(msg);i++) {
        printf("%c\n", *(msg+i));
    }
}

void kopi(char* v1, char* v2) {
    while(*v1++=*v2++);
}

int main() {

   char v2 = "Joko";
   char *v1;
   
   kopi(v1,v2);
    
    
//    
// nt jumlah_mangga = 30;
//    int harga_apel = 100;
//    int harga_mangga = 175;;
//    int apel_terjual = 11;
//    int mangga_terjual = 13;
//    
//    int jumlah_buah = jumlah_apel + jumlah_mangga;
//    
//    // cetak persediaan awal
//    printf("Persediaan awal buah\n");
//    printf("Jumlah apel       : %d buah\n", jumlah_apel);
//    printf("Jumlah mangga     : %d buah\n", jumlah_mangga);
//    separator();
//    printf("Jumlah total buah : %d buah\n", jumlah_buah);
//    
//    // cetak harga
//    printf("\nHarga buah\n");
//    printf("Harga apel   : %d/buah\n", harga_apel);
//    printf("Harga mangga : %d/buah\n", harga_mangga);
//    
//    // cetak transaksi
//    printf("\nTransaksi\n");
//    printf("Apel terjual     : %d x %d = %d\n", apel_terjual, harga_apel, apel_terjual * harga_apel);
//    printf("Mangga terjual   : %d x %d = %d\n", mangga_terjual, harga_mangga, mangga_terjual * harga_mangga);
//    separator();
//    printf("Total transaksi            = %d\n", apel_terjual * harga_apel + mangga_terjual * harga_mangga);
//    
//    // cetak persediaan akhir
//    printf("\nPersediaan akhir\n");
//    printf("Sisa apel       : %d buah\n", jumlah_apel - apel_terjual);
//    printf("Sisa mangga     : %d buah\n", jumlah_mangga - mangga_terjual);
//    separator();
//    printf("Jumlah sisa buah: %d buah\n", jumlah_apel - apel_terjual + jumlah_mangga - mangga_terjual);
//    
//    float persentase_apel =  (float)apel_terjual / (float)jumlah_apel * 100; 
//    float persentase_mangga = (float)mangga_terjual / (float)jumlah_mangga * 100;
//    
//    printf("\nPersentase penjualan apel   : %.2f", persentase_apel);
//    printf("\nPersentase penjualan mangga : %.2f\n", persentase_mangga);
    
    return 0;
}