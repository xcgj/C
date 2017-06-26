#include <stdio.h>
int main()
{
    goto end;   //无条件调到标号语句执行
    printf("1");
    end:    //标号
    printf("2");
    return 0;
}
