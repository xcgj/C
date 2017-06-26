#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#define MAX 1024 * 64
int main(void)
{
    FILE *p1 = fopen("E:/sort.txt", "rb");
    FILE *p2 = fopen("E:/sort2.txt", "wb");
    struct stat st = { 0 };
    stat("E:/sort.txt", &st);
    int size = st.st_size;
    if(size > MAX)
        size = MAX;
    int *buf = malloc(size);
    int res = 0;
    while(res = fread(buf, 1, sizeof buf, p1))
    {
        memset(buf, 0, size);
        fwrite(buf, 1, res, p2);
    }
    fclose(p1);
    fclose(p2);
    free(buf);
    printf("Hello World!\n");
    return 0;
}

