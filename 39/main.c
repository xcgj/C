/*
 * 写一个函数比较两个字符串,如果s1=s2，则返回值0；
如果s1>s2，则返回值1；如果s1<s2， 则返回-1。
函数原型 int mystrcmp(const char *p1,const char *p2);
    并且进行异常处理。模仿strcmp的用法。
    */
#include <stdio.h>
#include <stdlib.h>
int mystrcmp(const char *p1/*in*/,const char *p2/*in*/)
{
    if (p1 == NULL || p2 == NULL)
    {
        printf("error, invalid pointer\n");
        exit(-1);
    }
    else
    {
        const char *temp_p1 = p1;
        const char *temp_p2 = p2;
        int s1 = 0;
        int s2 = 0;
        while (*temp_p1++)
            s1++;
        while (*temp_p2++)
            s2++;
        if (s1 == s2)
            return 0;
        else if (s1 > s2)
            return 1;
        else
            return -1;
    }
}

int main(void)
{
    char *p1 = "sdgds";
    char *p2 = "NULLS";
    int res = mystrcmp(p1, p2);
    printf("%d\n", res);
    return 0;
}

