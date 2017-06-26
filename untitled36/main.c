#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int TransString(char **, char);

int main(void)
{
    char str[] = "AbCdefGHijLKdfkjf";
    int length = strlen(str);
    TransString(&str, length);
    printf("%s\n", str);
    return 0;
}

int TransString(char (*pstr)[], char len)
{
    int ret = 0;
    if (pstr == NULL || *pstr == NULL)
    {
        ret = -1;
        fprintf(stderr, "pstr is a NULL pointer\n");
        return ret;
    }
    char *p_temp = (char*)calloc(len, sizeof(char));
    if (p_temp == NULL)
    {
        ret = -2;
        fprintf(stderr, "p_temp is a NULL pointer\n");
        return ret;
    }
    int i;
    for (i = 0;i < len; i++)
    {
        if (islower((*pstr)[i]))
        {
            strncat(p_temp, *pstr + i, 1);
        }
    }
    for (i = 0; i < len; i++)
    {
        if (isupper((*pstr)[i]))
        {
            strncat(p_temp, *pstr + i, 1);
        }
    }
    *pstr = p_temp;
    return ret;
}
