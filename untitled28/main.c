#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct info //定义结构体
{
    char *name;
    char *addr;
    int age;
}info;

int print(info *d, int *m)  //打印
{
    if (d == NULL)  //检查空指针
    {
        printf("error:-3, func print has NULL pointer\n");
        return -3;
    }
    int i = 0;
    for (; i < *m; i++)
        printf("%s\t%d\t%s\n", (d + i)->name, (d + i)->age, (d + i)->addr);
    return 0;
}

int freeall(info *d, int *m)    //释放内存
{
    if (d == NULL)  //检查空指针
    {
        printf("error:-6, func print has NULL pointer\n");
        return -6;
    }
    int i = 0;
    for (; i < *m; i++)
    {
        free(d[i].name);
        free((d + i)->addr);
        (d + i)->name = d[i].addr = NULL;
    }
    free(d);
    return 0;
}

int getinfo(info *b)
{
    b = (info *)malloc(sizeof(info));
    if (b == NULL)  //检查空指针
    {
        printf("error, NULL pointer\n");
        return -1;
    }
    info *c = NULL;
    int count = 0;
    char cmd[20] = { 0 };
    int result = 0;

    while (1)
    {
        printf("请输入命令：");
        memset(cmd, 0, sizeof(char) * 20);  //重置命令缓存
        scanf("%s", cmd);                   //获得命令
        if (strcmp(cmd, "exit") == 0)
            break;


        else if (strcmp(cmd, "print") == 0)
        {
            if (count == 0)					//第一次就打印，提示错误
            {
                printf("error:-2, no information input\n");
                free(b);
                b = NULL;
                return -2;
            }
            result = print(b, &count);
        }


        else if (strcmp(cmd, "add") == 0)
        {
            c = (info *)realloc(b, sizeof(info) * (count + 1));//加内存空间
            if (c == NULL)	//判断内存是否分配
            {
                printf("error:-4, NULL pointer, memory allocate fail\n");
                free(b);
                b = NULL;
                return -4;
            }
            b = c;
            b[count].name = (char *)malloc(100 * sizeof(char));//给名字分配堆空间
            b[count].addr = (char *)malloc(100 * sizeof(char));//给地址分配堆空间
            if (b[count].name == NULL || b[count].addr == NULL)//判断内存是否分配
            {
                printf("error:-5, NULL pointer, MEMBERS allocate fail\n");
                freeall(b, &count);
                return -5;
            }
            printf("请输入3个信息：");
            scanf("%s %d %s", b[count].name, &b[count].age, b[count].addr);
            count++;		//记录下标
        }


        else
        {
            printf("error:-7, invalid cmd\n");
            freeall(b, &count);
            return -7;
        }
    }
    printf("程序退出\n");
    freeall(b, &count);
    return result;
}

int main(void)
{
    info *s = { 0 };
    int res = 0;
    res = getinfo(s);
    if (res == 0)
        printf("complete\n");
    else
        printf("program dumped\n");
    return 0;
}
