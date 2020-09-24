#include <stdio.h>

int main(int argc, char **argv)
{
d	int nilai;
	char grade;
	printf("Masukan sebuah nilai : ");
	scanf("%d",&nilai);
	if(nilai<56) {
		grade = 'D';		
	}
	else if(nilai<70) {
		grade = 'C';
	}
	else if(nilai<80) {
		grade = 'B';
	}
	else {
		grade = 'A';
	}
	printf("Nilai : %d, Grade : %c",nilai,grade);

	return 0;
}
