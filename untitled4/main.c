#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct A
{
    int a;
    char *b;
};

int main(void)
{
    struct A d;
    d.b = malloc(10);
    strcpy(d.b, "xcgj");
    struct A e;
    e.b = d.b;//赋值，指向同一个地址
    free(d.b);
    printf("%s\n", e.b);
    printf("%p,%p\n", d.b, e.b);
    //%s对应的数据项是地址
    return 0;
}

