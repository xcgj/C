#include<stdio.h>

void getheap2(int **p)//函数2的p指向了main函数的p的地址，（函数2的p = &(main函数的p)）
{
    printf("p2 = %x\n", p);//函数2的p指向的地址，肯定等于&p0
    *p = malloc(sizeof(int)*10);//从堆中申请了内存，给函数2的p指向的地址里面的内存赋值，这步相当于给main函数的p赋值了
    //*p = 3;//为何报错？？？？？？？？？？？？？？？？
}

int main()
{
    int *p;
    p = 0x2345;
    printf("main p0 = %x\n", p);//main函数的p变量指向的地址
    printf("main &p0 = %x\n", &p);//main函数的p变量自己有一个地址
    getheap2(&p);//这里把main函数p的自己的传递给函数2了，而不是p指向的地址的值 0x2345 （函数2的p=&(main函数的p)）
    //由于函数2的p指向的是main函数p自身的地址，函数2的p操作了main函数的p的内存值
    printf("main p0 = %x\n", p);//重新分配内存，值改变
    printf("main &p0 = %x\n", &p);//值不变
    p[0] = 1;
    p[1] = 1;
    p[2] = 2;
    printf("%d, %d, %d, %d\n", *p, p[0], &p[1],&p[2]);
    return 0;
}



void getheap1(int *p)//p=0x2345，p指向的地址变成0x2345
{
    printf("p1 = %x\n", p);//函数1的p变量指向的地址
    printf("&p1 = %x\n", &p);//函数1的p变量自己有一个地址
    //printf("*p1 = %d\n", *p);//指向的地址没有赋值，程序会报错
    p = malloc(sizeof(int)*10);//从堆中申请了内存给了p，p指向的地址改变
    //但是，函数1的p的地址和mian函数的p的地址依旧是不一样的（函数1的&p != main函数的&p）
    //因此main函数的p指向的地址不受影响，仍然 p = 0x2345;
    printf("p2 = %x\n", p);
    printf("&p2 = %x\n", &p);
}
