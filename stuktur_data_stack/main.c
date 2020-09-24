#include <stdio.h>
#include <stdlib.h>

int *stack;
int maks = 4;
int puncak = -1;

int statusPenuh() {
	return puncak == maks;
}

int statusKosong() {
	return puncak == -1;
}

void push(int nilai) {
	// periksa apakah stack penuh
	// menggunakan fungsi yang telah dibuat di atas
	if(statusPenuh()) printf("Tumpukan penuh, operasi dibatalkan!\n");
	else {
		puncak++;
		stack[puncak] = nilai;
	}
}

int pop() {
	int nilai = -1;
	if(statusKosong()) printf("Tumpukan kosong, operasi dibatalkan!\n");
	else {
		nilai = stack[puncak];
		puncak--;
	}
	return nilai;
}


int peek() {
	if(statusKosong()) {
		printf("Tumpukan kosong, operasi dibatalkan!\n");
		return -1;
	}
	return stack[puncak];
}

void clear() {
	puncak = -1;
}

int main(int argc, char **argv)
{
    // inisialisasi stack
    int stack_size = 4;
    maks = stack_size - 1;
    stack = (int*) malloc(stack_size * sizeof(int));
    // operasi stack
    push(5);
    push(4);
    push(7);
    push(10);
    push(9);
    printf("%d\n",peek());
    pop();
    printf("%d\n",peek());
    pop();
    pop();
    pop();
    pop();
    push(8);
    push(9);
    printf("%d\n",pop());
    clear();
    pop();
	free(stack);
	return 0;
}

