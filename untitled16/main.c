#include <stdio.h>

int main(void)
{
    FILE *p = fopen("E:\\C_project\\1.abcd", "rb");
    //设文件1.abcd里存的是一个数组，元素10个
    int read = 0;
    while (fread(&read, sizeof(int), 1, p) != 0)
    {
        printf("%d", read);
    }
    fclose(p);
    return 0;
}

