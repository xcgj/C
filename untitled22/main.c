#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getmem(char ***p, int num)
{
    if (p == NULL)
        return;
    *p = (char **)malloc(num * sizeof(char));
    memset(p, 0, num * sizeof(char));
    if (*p == NULL)
        return;
}

void getalloc(char **p, int n)//分配空间
{
    if (p == NULL)
        return;
    int i = 0;
    for (; i < n; i++)
    {
        p[i]/**(p + 1)*/ = (char *)malloc(100 * sizeof(char));
        memset(p[i], 0, n * sizeof(char));
    }
}

void getvalue(char **p, int n)//赋值
{
    if (p == NULL)
        return;
    int i = 0;
    for (; i < n; i++)
        sprintf(p[i], "%d%d%d", i + 1, i + 1, i + 1);
}

void print(char **p, int n)//打印
{
    if (p == NULL)
        return;
    int i = 0;
    for (; i < n; i++)
        printf("%s \n", p[i]);
}

void sort(char **p, int n)//排序
{
    if (p == NULL)
        return;
    int i = 0;
    int j = 0;
    //char *temp = NULL;
    char temp2[100]; //= { 0 };
    for(i = 0; i < n - 1; i++)
        for (j = i; j < n; j++)
        {
            if (strcmp(p[i], p[j]) < 0)//大到小
            {
                /*temp = p[i];//地址交换
                p[i] = p[j];
                p[j] = temp;*/
                strcpy(temp2, p[i]);//代码块交换
                strcpy(p[i], p[j]);
                strcpy(p[j], temp2);
            }
        }
}

void freealloc(char **p, int num)//释放空间
{
    if (p == NULL)
        return;
    int i = 0;
    for (; i < num; i++)
    {
        if (p[i] == NULL)
            continue;
        free(p[i]/**(p + 1)*/);
        *(p + i) = NULL;
    }
    //free(p);
}

int main(void)//创建字符串二维数组，赋值排序并打印
{
    int			num = 5;
    char		**p = NULL;
    getmem		(&p, num);
    getalloc	(p, num);//分配空间
    getvalue	(p, num);//赋值
    print		(p, num);//打印
    sort		(p, num);//排序
    print		(p, num);//打印/
    freealloc	(p, num);//释放空间
    //printf("%s\n", a[0]);
    //if (p != NULL)
        //free(p);
    return 0;
}
