#include <stdio.h>
#include <string.h>
int main(void)
{
    char a[100];
    FILE *p = fopen("E:\\C_project\\file5.txt", "w");
    while (1)
    {
        scan f("%s", a);
        if ((strcmp(a, "exit")) == 0)
            break;
        fputs(a, p);
    }
    printf("done\n");
    fclose(p);
    return 0;
}
