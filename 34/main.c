#include <stdio.h>
#include <string.h>

sss(char *s ,char *t)
{
    while((*s)&&(*t));//比较字符串
    {
        if (*t++ == *s++)
            break;
    }
    return(*--s - *--t);
}



void main()
{  char *s1="ABCDEF", *s2="aB";
    s1++; s2++;
    printf("%d\n", strcmp( s2,s1));
}
