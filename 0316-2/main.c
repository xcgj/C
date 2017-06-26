#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
void searchnum(char *st, int *a)
{
    if (st == NULL || a == NULL)
    {
        printf("func searchnum error: NULL pointer\n");
        return;
    }
    int len = strlen(st);
    for (int i = 0; i < len; i++)//遍历字符串
    {
        if (isdigit (st[i]))//如果是数字字符
            a[st[i] - '0']++;//4  int isdigit ( int c )判断数字字符，减‘0’转换整型
    }//5  a[10]数组，接收数字0-9，出现一个数字，对应数字下标的元素的值加1
}

void listnum(int *a)
{
    if (a == NULL)
    {
        printf("func listnum error: NULL pointer\n");
        return;
    }
    for (int i = 0; i < 10; i++)//遍历数组
        printf("%d出现%d次\n", i, a[i]);
}

void getin(char **st)
{
    if (st == NULL)
    {
        printf("func getin error: NULL pointer\n");
        return;
    }
    char *s = (char *)malloc(1024 * sizeof(char));
    if (s == NULL)
    {
        printf("func getin error: memory allocate failed\n");
        return;
    }
    gets(s);
    *st = s;
}

int main(void)
{
    char *str = NULL;
    int arr[10] = { 0 };//2 安排一个a[10]数组
    getin(&str);//1 获得字符串

    searchnum(str, arr);//3 遍历数组

    listnum(arr);//6 遍历a[10]数组

    free(str);
    str = NULL;

    return 0;
}

