//有n个整数，编程序将前面的各个数依次向后移动k个位置，最后k个数移到最前边的k个位置（见下图，其中n=8，k=3）。
//思考: 如果程序中不引入其它数组该如何设计思路。
//1 k之前的数逆置
//5 4 3 2 1 | 6 7 8
//2 整个数组逆置
//8 7 6 | 1 2 3 4 5
//3 前k个数逆置
//6 7 8 | 1 2 3 4 5

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)//交换
{
    if (a == NULL || b == NULL)
    {
        int res = -1;
        printf("func swap error:%d,(a == NULL || b == NULL),invalid pointer\n", res);
        exit(-1);
    }
    else
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
}

void bufset(int *s, int n)//逆置
{
    if (s == NULL)
    {
        int res = -2;
        printf("func bufset error:%d,(s == NULL),invalid pointer\n", res);
        exit(-1);
    }
    else
    {
        int i = 0;
        for (; i < n / 2; i++)
            swap(&s[i], &s[n - 1 - i]);
    }
}

void print(int *a, int n)//打印数组
{
    if (a == NULL)
    {
        int res = -3;
        printf("func print error:%d,(a == NULL),invalid pointer\n", res);
        exit(-1);
    }
    else
    {
        int i = 0;
        for (; i < n; i++)
            printf("%-2d", a[i]);
        printf("\n------------\n");
    }
}

int main(void)
{
    int arr[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    int k = 3;
    bufset(arr, 8 - k);//1
    print(arr, 8);

    bufset(arr, 8);//2
    print(arr, 8);

    bufset(arr, k);//3
    print(arr, 8);

    return 0;
}

