//函数功能:
//获取str指针指向的字符串中ch字符出现的次数，通过pcount指针将数据传出到主调函数。

#include <stdio.h>
#include <string.h>
int getCountOfChar(const char *str,int ch,int *pcount)
{
    if (str == NULL || pcount == NULL)
        return -1;
    const char *temp_str = str;
    char temp_ch = (int)ch;
    while (*temp_str)
    {
        if (*temp_str == temp_ch)
            (*pcount)++;
        temp_str++;
    }
    return 0;
}

int main(void)
{
    char str[] = "aaassddffgg";
    int c = (int)'d';
    int count = 0;
    getCountOfChar(str, c, &count);
    printf("%d\n", count);
    return 0;
}

