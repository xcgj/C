#include <stdio.h>

int main(void)
{
    int c;
    while ((c = getchar()) != EOF)
    {
        printf("c = getchar() == %d \n", c = getchar());
        //printf("c = %d \n", c);
        printf("---\t");
        putchar(c);
        printf("\t---\n");
    }
    return 0;
}

