#include <stdio.h>

struct C
{
    char a;
    int b;
};

int main()
{
    struct C a;
    char *p = &a;
    *p = 0;
    p[1] = 1;//利用浪费的内存
    p[2] = 2;//利用浪费的内存
    p[3] = 3;//利用浪费的内存
    p[4] = 4;
    printf("%-2d%-2d%-2d%-2d%-2d\n", p[0], p[1], p[2], p[3], a.b);
    return 0;
}















char getstr1()//函数正确
{
    char s = 'a';
    return s;
}

const char *getstr2()//函数正确
{
    return "xcgj";//返回一个常量的地址
    /*等效于
     * char s2[] = "xcgj";
     * return s2;
     */
    //常量的地址在程序运行期间一直存在
}

char *getstr3()//函数正确
{
    static char a[10] = "xcgj";
    //在静态区，地址在函数运行期间一直存在
    return a;
}

int main02()
{
    char s1 = getstr1();
    printf("s1 = %c\n", s1);

    char *s2 = getstr2();
    printf("s2 = %s\n", s2);

    char *s3 = getstr3();
    printf("s3 = %s\n", s3);
    return 0;
}

















int *getheap()//正确的写法
{
    return malloc(100);
    //从堆获得地址返回主函数
}

char *getstring()//错误的写法
{
    char string[10] = "xcgj";
    return string;
    //返回栈分配的地址
}//数组string的作用域结束，自动从栈中弹出，返回给主函数的地址无效了

int main01()
{
    int *p = NULL;
    p = getheap();
    //获得地址，p指向堆中的地址
    free(p);

    int *s = getstring();//获得无效的栈地址

    return 0;
}
