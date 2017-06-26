#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void getnum(int *a)
{
    srand((unsigned int)time(NULL));
    *a = (rand() % 1000 + 1);
}

void guess(int *n, int *c)
{
    int b = 0;
    printf("请输入一个数：");
    scanf("%d", &b);
    (*c)++;
    while (b != *n)
    {
        if (b > *n)
        {
            printf("猜大了，请重新输入：");
            scanf("%d", &b);
        }
        else if (b < *n)
        {
            printf("猜小了，请重新输入：");
            scanf("%d", &b);

        }
        (*c)++;
    }
}

int main(void)
{
    int a = 0;
    int count = 0;
    getnum(&a);//获得随机数
    guess(&a, &count);//比较
    printf("%d done!\n", count);
    return 0;
}
