#include <stdio.h>

int main(void)
{
    int a[10] = { 9,8,7,6,5,4,3,2,1,0 };
    int *p = a;
    printf("%d\n", ++*p);
    printf("%d\n", *++p);
    return 0;
}

