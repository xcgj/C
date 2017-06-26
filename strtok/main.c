#include <stdio.h>
#include <string.h>
int main(void)
{
    FILE *q = fopen("E:\\Yesterday Once More.txt", "r");
    char buffer[1000] = { 0 };
    int count = 0;
    while (!feof(q))
    {
        memset(buffer, 0, sizeof(buffer));
        fgets(buffer, sizeof(buffer), q);
        char *w = strtok(buffer, "- ,.'[]:0123456789)(");
        count++;
        while (w)
        {
            printf("%s\n", w);
            w = strtok(NULL, "- ,.'[]:0123456789)(");
            count++;
        }
    }
    printf("count = %d\n", count);
//    char s[] = "when i was young i'd listen to the radio waiting for my favorite songs when they played i'd sing along, it make me smile.";
//    char *p = NULL;
//    p = strtok(s, " ,.'");
//    while (p)
//    {
//        printf("%s\n", p);
//        p = strtok(NULL, " ,.'");
//    }
    return 0;
}

