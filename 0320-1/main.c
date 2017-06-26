//获取到数组中质数的个数
//函数原型：int getCountOfPrimer(int arr[],int len,unsigned int *p_count);
//函数功能：获取到数组arr中质数的个数
//函数参数:	arr是需要被扫描的数组
//	p_count是一个传出的指针参数,将获取到的质数个数传出
//函数返回值：
//	成功返回0；
//	如果有错误返回-1

//质数：除了1和数本身之外没有其他的约数。
//约数：又称因数。整数a除以整数b(b≠0) 除得的商正好是整数而没有余数，我们就说a能被b整除，或b能整除a。

//质数2除了1和本身2能够整除2之外，没有第三个数能够整除2，所以2是质数。
//质数5除了1和本身5能够整除5之外，没有第三个数能够整除5，所以5是质数。

//题解：
// 遍历数组
// 遇到质数计数器+1
// 定义质数函数，将&(flag = 1), 数组元素作形参传入，
// 将这个数从2—n-1开始模，模等于0跳出循环，flag = 0，不是素数，否则flag = 1

#include <stdio.h>
#include <stdlib.h>

int IsPrime(int a)//判断是不是质数
{
    if (a == 0)
        return 0;
    int i = 2;
    for(; i < a; i++)
        if (!(a % i))
            return 0;
    return 1;
}

int getCountOfPrimer(int *arr/*in*/,int len,unsigned int *p_count/*out*/)
{
    if (arr == NULL || p_count == NULL)
        return -1;
    int i = 0;
    for (; i < len; i++)
        *p_count += IsPrime(arr[i]);
    return 0;
}

int main(void)
{
    int i = 0;
    int length = 0;
    unsigned int count = 0;

    printf("请输入数组长度: ");
    scanf("%d", &length);

    int *array = (int*)calloc(length, sizeof(int));
    printf("请输入%d个元素: \n", length);
    for (; i < length; i++)
        scanf("%d", &array[i]);

    getCountOfPrimer(array, length, &count);
    printf("该数组质数个数为 %u 个\n", count);
    return 0;
}

