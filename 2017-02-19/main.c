#include <stdio.h>

int *pointer()
{
    int a = 100;
    return &a;
}//变量a作用域结束，内存地址被释放

int main()
{
    int *p = pointer();
    //得到一个临时栈的地址，这个地址在函数pointer调用完成后已经失效
    *p = 500;//这个操作是非法的，地址无效
    printf("%d\n", *p);
    return 0;
}

