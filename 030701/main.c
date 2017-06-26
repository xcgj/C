/*
        8、 有代码如下:

        int num = 10;int *p1 = &num;
        请写代码输出num、p1 变量的地址和值.
*/

#include <stdio.h>

int main(void)
{
    int num = 10;
    int *p1 = &num;
    printf("num变量的地址 = %p, 值 = %d\n", p1, *p1);
    printf("p1指针变量的地址 = %p, 值 = %X\n", &p1, p1);
    return 0;
}

