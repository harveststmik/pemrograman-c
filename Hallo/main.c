
#include <stdio.h>
#include <stdlib.h>
void tukar(int* a, int* b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void strcopy(char *s, char *t) {
    while(*s++ = *t++)
        ;
}

int main() {
    int a = 5;
    int b = 10;
    tukar(&a, &b);
    printf("%d - %d\n", a, b);
    
    char* s = (void *) malloc(6) ;
    strcopy(s, "hello");
    printf("%s\n",s);
    free(s);
}