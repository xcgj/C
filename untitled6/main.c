#include <stdio.h>
#include <string.h>

void codes(char *s)
{
    while (*s)
    {
        (*s)++;
        s++;
    }
}

int main(void)
{
    char cpy[1024];
    FILE *p1 = fopen("E:\\C_project\\file.txt", "r");
    FILE *p2 = fopen("E:\\C_project\\code.txt", "w");
    while (!feof(p1))
    {
        //memset(cpy, 0, sizeof(cpy));
        fgets(cpy, sizeof(cpy), p1);
        codes(cpy);
         fputs(cpy, p2);
    }
    fclose(p1);
    fclose(p2);
    printf("Program complete!\n");
    return 0;
}

