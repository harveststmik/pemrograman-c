#include <stdio.h>

int main(int argc, char **argv)
{
    char *p_heroes[] = { "Oracle", "Medusa", "Doom" };
    char a_heroes[][10] = { "Oracle", "Medusa", "Doom" };
    
	printf("%s\n", a_heroes[1]);
    printf("%s\n",*(a_heroes+1));
    
    printf("%s\n", p_heroes[2]);
    printf("%s\n",*(p_heroes+2));
	return 0;
}
