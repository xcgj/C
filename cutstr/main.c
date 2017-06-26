#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(void)
{
    char a[100] = "   sdf sd   ";
    char *p = a;
    char *q = a + strlen(a) - 1;
    while (isspace (*p++));
    while (isspace (*q--));
    p = p - 1;
    p[(q + 1) - p + 1] = '\0';
    printf("%s", p);
    return 0;
}
