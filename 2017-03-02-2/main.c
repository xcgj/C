#include <stdio.h>
#include <string.h>

void swap(int *, int *);
void paixu(int *, int);
void print(int *, int );

int main()
{
    //定义缓冲字符串数组
    char buffer[100] = { 0 };

    //变量len计算元素长度
    int len = 0;

    //打开文件1
    FILE *p = fopen("E:\\C_project\\file5.txt", "r");
    // !feof() fgets()将行数搞出来
    while (!feof(p))
    {
        memset(buffer, 0, sizeof buffer);
        fgets(buffer, sizeof buffer, p);//这步不能省略，否则死循环，why？？？？？
        len++;
    }
    //关闭文件1
    fclose(p);
    printf("%d\n", len);
    //定义换成整型数组
    int integer[len];
    //打开文件1
    p = fopen("E:\\C_project\\file5.txt", "r");
    int i = 0;
    // !feof() fgets() atoi将每一行抠出来给字符串，再转给整型数组
    while(!feof(p))
    {
        memset(buffer, 0, sizeof buffer);
        fgets(buffer, sizeof buffer, p);
        integer[i++] = atoi(buffer);
    }
    print(integer, len);
    //关闭文件1
    fclose(p);
    //整型数组排序
    paixu(integer, len);
    //打开文件2
    p = fopen("E:\\C_project\\file7.txt", "w");
    //for循环 sprintf() 依次把整型数组元素给字符串，再输出到文件
    for (i = 0; i < len; i++)
    {
        memset(buffer, 0, sizeof buffer);
        sprintf(buffer, "%d\n", integer[i]);
        fputs(buffer, p);
    }
    //关闭文件2
    fclose(p);
    return 0;
}



void swap(int *a, int *b)//互换
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void paixu(int *a, int line)//排序
{
    int i = 0;
    int j = 0;
    for (i = 0; i < line; i++)
        for (j = 1; j < line - i; j++)
            if (a[j] < a[j - 1])
                swap(&a[j], &a[j - 1]);
}

void print(int *a, int num)
{
    int i = 0;
    for (i = 0; i < num; i++)
        printf("a[%d] = %d\n", i, a[i]);
}
