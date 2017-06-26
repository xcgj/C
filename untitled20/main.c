#include <stdio.h>
#include <ctype.h>

void swap(char *a, char *b)
{
    char *p = a;
    char *q = b;
    while (p < q)
    {
        char temp = *p;
        *p = *q;
        *q = temp;
        p++;
        q--;
    }
}

void reverse(char *s)
{
    char *p = s;
    char *q = NULL;
    char *r = NULL;
    while (*p && !isspace(*p))
    {
        //if (!isspace(*p))
        //{
            q = p;
            r = p;
            p++;
            while (!isspace(*p) && *p)
            {
                r = q;
                r++;
                q++;
            }
            r = (r == q) ? r : r - 1;
            swap(q, r);//p，r字符串交换
            //strcat
        //}
        q = NULL;
        r = NULL;
    }
}



int main(void)
{
    char s[100] = "Hello World!\n";
    reverse(s);
    printf("%s\n", s);
    return 0;
}

