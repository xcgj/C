/*
 * 函数原型 int *getSpace(int n);
 *  分配n个用以存储n个随机数的堆空间  并且通过函数返回值返回。
 * 函数原型 int createNumber(int n,int *p); //产生n个的随机数 (1<= x <=n)
 *  即需要控制随机数范围在1到n之间存到p指向的空间
 * 函数原型 int writeFile(int n,const char *p);
 *  即将p指向内存的n个不重复的数写入到test.txt文件中
 * 函数原型 int readFile(int n,const char **p1);
 *  即将test.txt文件中的n个数（n由读取第一行获得）写入*p1指向内存空间
 * 函数原型 int deleteSame(int n,const int *p);
 *  对p指向的n个空间中的数字进行删除重复的操作 函数返回n个数在删除重复的之后剩余数字的个数
 * 函数原型 int freeSpace(int **p);
 *  将getSpace申请的空间释放 并且防止产生迷途指针
 * 函数原型 int printfSpace(int *p,int n);
 *  将p指向的空间的n个整数打印出来
    1 首先输入数字n（n代表我们需要产生多少个随机数用于后面的操作）
    2 调用函数 p=getSpace(n) 根据数字n分配能够容纳n个整数的堆空间用p接收首地址
    3 调用函数createNumber(n,p)用于产生n个不重复的随机数并且存储在p指向的内存中
    3 调用函数 writeFile(n,p);将p指向内存的n个不重复的数写入到test.txt文件中,在写入文件的时候 第一行写入n的数值
    4 调用函数 freeSpace释放掉p指向的空间
    5 调用函数 readFile(n,&p1);时先读取第一行 获取到n值 然后调用getSpace(n)获取内存空间之后并且存储首地址到p1中
    6 调用函数int m= deleteSame(n,p1);删除p1指向的内存中n个数相同的数字
    7 调用函数printfSpace(m,p1);打印出p1指向的内存中剩余的m个整数
    8 释放p1指向的内存 freeSpace(&p1);
    */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int printfSpace(int m, int *p1);
int deleteSame(int n, int **p1);
int freeSpace(int **p);
int *getSpace(int n);
int createNumber(int n, int *p);
int writeFile(int n, int *p);
int readFile(int n, int **p1);

int main(void)
{
    int n = 0;
    while (n < 1)
    {
        printf("please input a number(n > 0):\n");
        scanf("%d", &n);
    }

    int *p = getSpace(n);
    createNumber(n, p);
    int i = 0;
    for (i = 0; i < n ; i++)
        printf("%d\n", p[i]);
    writeFile(n, p);
    freeSpace(&p);

    int *p1 = NULL;
    readFile(n, &p1);

    int m = deleteSame(n, &p1);
    printfSpace(m, p1);
    freeSpace(&p1);

    return 0;
}

int *getSpace(int n)//分配n个用以存储n个随机数的堆空间  并且通过函数返回值返回。
{
    int *num = (int*)calloc(n, sizeof(int));
    if (num == NULL)
        fprintf(stderr, "p_temp is a NULL pointer\n");
    return num;
}

int createNumber(int n,int *p)
//产生n个的随机数 (1<= x <=n) 即需要控制随机数范围在1到n之间存到p指向的空间
{
    int ret = 0;
    if (n < 1 || p == NULL)
    {
        ret = -1;
        fprintf(stderr, "n < 1 or p is a NULL pointer\n");
        return ret;
    }
    srand((unsigned int)time(NULL));
    int i, j;
    for (i = 0; i < n; i++)
    {
        p[i] = rand() % n + 1;
        for (j = 0; j < i; j++)
        {
            if (p[j] == p[i])
            {
                i--;
                break;
            }
        }
    }
    return ret;
}

int writeFile(int n, int *p)
//即将p指向内存的n个不重复的数写入到test.txt文件中,在写入文件的时候 第一行写入n的数值
{
    int res = 0;
    if (p == NULL)
    {
        res = -1;
        fprintf(stderr, "writeFile err");
        return res;
    }
    FILE *pf = fopen("test.txt", "w");
    if (pf == NULL)
    {
        res = -1;
        fprintf(stderr, "fopen err");
        return res;
    }
    fprintf(pf, "%d\n", n);
    int i = 0;
    for (i = 0; i < n; i++)
        fprintf(pf, "%d\n", p[i]);
    fclose(pf);
    return res;
}

int freeSpace(int **p)//将getSpace申请的空间释放 并且防止产生迷途指针
{
    int ret = 0;
    if(p == NULL)
    {
        ret = -1;
        fprintf(stderr, "freeSpace err");
        return ret;
    }
    if(*p)
    {
        free(*p);
        *p = NULL;
    }
    return ret;
}

int readFile(int n, int **p1)//将test.txt文件中的n个数（n由读取第一行获得）写入*p1指向内存空间
//先读取第一行 获取到n值 然后调用getSpace(n)获取内存空间之后并且存储首地址到p1中
{
    int res = 0;
    if (p1 == NULL)
    {
        res = -1;
        fprintf(stderr, "readFile err");
        return res;
    }
    FILE *pf = fopen("test.txt", "r");
    if (pf == NULL)
    {
        res = -1;
        fprintf(stderr, "fopen err");
        return res;
    }
    char c[10] = { 0 };
    fgets(c, 10, pf);
    n = atoi(c);
    //printf("%d\n", n);
    *p1 = getSpace(n);
    return res;
}

int deleteSame(int n, int **p1)
//对p指向的n个空间中的数字进行删除重复的操作 函数返回n个数在删除重复的之后剩余数字的个数
//删除p1指向的内存中n个数相同的数字
{
    int res = 0;
    if (p1 == NULL || *p1 == NULL)
    {
        res = -1;
        fprintf(stderr, "deleteSame err");
        return res;
    }
    int i, j, k, flag = 0;
    int *temp = (int*)calloc(n, sizeof(int));
    for (i = 0, k = 0; i < n; i++)//统计不相同的个数
    {
        for (j = 0; j < i; j++)
        {
            if ((*p1)[i] == (*p1)[j])
            {
                flag = 1;
                break;
            }
        }
        if (flag)
            continue;
        temp[k] = (*p1)[i];
        k++;
    }
    *p1 = (int*)realloc(*p1, k + 1);//缩减p1的堆空间
    for (i = 0; i <= k; i++)//数组拷贝
        (*p1)[i] = temp[i];
    free(temp);
    return k + 1;
}


int printfSpace(int m, int *p1)
{
    int res = 0;
    if (p1 == NULL)
    {
        res = -1;
        fprintf(stderr, "printfSpace err");
        return res;
    }
    int i = 0;
    for (i = 0; i < m; i++)
        printf("%d\n", p1[i]);
    return res;
}
