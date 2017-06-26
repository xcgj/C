#include <stdio.h>
#include <ctype.h>
int main(void)
{
    char p[30] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i = 0;
    for (; i < 28; i++)
        printf("%d\n", isupper(p[i]));
    return 0;
}

