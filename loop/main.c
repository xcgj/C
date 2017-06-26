#include <stdio.h>
int main(void)
{
    int i, j, k;
    while(1)    //设置死循环
    {
        printf("line:");
        scanf("%d", &k);
        if(k < 1)   //设置死循环终止
            break;
        for()




        for(i = 1; i <= k; i++)
        {
            for(j = 1; j < i; j++) //空格数递增
                printf(" ");
            for(j = 1; j <= (2*(k - i) + 1); j++)//*等于((行数-k)*2+1)
                printf("*");
            printf("\n");
        }
    }
    return 0;
}

