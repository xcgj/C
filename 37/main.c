/*
 * 函数原型如下
int TranString(char *pstr)；
函数功能把pstr字符串中的小写字母改成大写字母。
*/

#include <stdio.h>
#include <stdlib.h>

void TranString(char *pstr)
{
    if (pstr == NULL)
    {
        printf("error, invalid pointer\n");
        exit(-1);
    }
    else
    {
        char *p = pstr;
        while (*p)
        {
            if (*p <= 'z' && *p >= 'a')
                *p -= ('a' - 'A');
            p++;
        }
    }
}

int main(void)
{
    char p[] = "ASdfghjKLpoYT";
    TranString (p);
    printf("%s\n", p);
    return 0;
}

