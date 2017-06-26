
#if 0

01 请说出程序结果:
   int& myFunc()
   {
        static int a = 0;
        return a;
   }

   int ret = myFunc();//0
   ret = 100;
   int &ref = myFunc();//a
   cout << "ref : " << ref << endl;

 ref : 0


02 编写程序，实现两个字符串变量的交换(使用引用和指针两种方式实现).
    char *p1 = "hello C!";
    char *p2 = "hello C++!";

#include <iostream>

using namespace std;

void test_c(char ** p1, char ** p2)
{
    if (NULL == p1 || NULL == p2)
    {
        return;
    }

    char * tmp = NULL;
    tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

void test_cpp(char * & q1, char * & q2)
{
    char * tmp = NULL;
    tmp = q1;
    q1 = q2;
    q2 = tmp;
}

int main()
{
    char *p1 = (char *)"hello C!";
    char *p2 = (char *)"hello C++!";

    test_c (&p1, &p2);
    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;

    test_cpp (p1, p2);
    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;

    return 0;
}


03 请编码实现建立对下面数组的引用。并通过数组引用对给数组赋值。(至少2种方式)
   int arr[10];


#include <iostream>

using namespace std;

//03 请编码实现建立对下面数组的引用。并通过数组引用对给数组赋值。(至少2种方式)
void test(int (&b)[10])
{
    for (int i = 0; i < 10; ++i)
    {
        b[i] = 3 * i + 5;
    }
}

void print(int (&n)[10])
{
    for (int i = 0; i < 10; ++i)
    {
        cout << "arr[" << i << "] = " << n[i] << endl;
    }
}

int main(void)
{
    int arr[10];

    //=========1==========
    int (&a)[10] = arr;
    for (int i = 0; i < 10; ++i)
    {
        a[i] = 2 * i + 5;
    }

    print(arr);

    //==========2==========
    test(arr);

    print(arr);

    return 0;
}



04 请描述C和C++中const的区别？

全局const都存放在常量区，局部const都存放再栈区，局部const都能用指针间接修改const的值
C:全局connst是extern的，全局和局部const都会分配内存空间
C++：全局const默认是static的，全局和局部const在遇到取地址或者extern声明或者复杂数据类型时才会分配空间，如果const没有分配空间，编译器在编译时可能会发生值折叠（用volatile和赋值变量时除外）

05 请描述内联函数的作用?以及内联函数和宏函数的区别？
内联函数作用：减少函数压栈出栈返回的操作，牺牲内存换效率
宏函数没有参数、返回值类型检查；没有作用域限制不能成为类的成员函数；预处理直接文本替换可能会使程序发生逻辑错误，得不到想要的结果

06 请说出以下代码是否会发生编译错误，如果发生是哪一行代码会发生？并说明原因
    int add(int a,int b)
    {
        return a + b;
    }

    double add(double a,double b)
    {
        return a + b;
    }

    void test()
    {
        int a = 10;
        int b = 20;
        double c = 7.5;
        double d = 9.2;

        cout << add(a, b) << endl;
        cout << add(c, d) << endl;
        cout << add(a, c) << endl;//出错，找不到参数类型匹配的重载函数add(int, double)
    }


07 编写MySwap函数，要求MySwap函数可以实现以下数据类型的交换功能,并编写测试案例.
   int,double,
   struct Person
   {
        int mID;
        int mAge;
   }

   #include <iostream>

using namespace std;

struct Person
{
    int mID;
    int mAge;
};

void MySwap(int &a, int &b)
{
    a ^= b;
    b ^= a;
    a ^= b;
}

void MySwap(double &a, double &b)
{
    double c = a;
    a = b;
    b = c;
}

void MySwap(Person &a, Person &b)
{
    Person c = a;
    a = b;
    b = c;
}

int main07(void)
{
   int a = 10;
   int b = 20;
   double c = 1.2;
   double d = 2.3;
   Person e = { 2010, 20 };
   Person f = { 2020, 30 };

   MySwap(a, b);
   MySwap(c, d);
   MySwap(e, f);

   cout << "a = " << a << ", b = " << b << endl;
   cout << "c = " << c << ", d = " << d << endl;
   cout << "e.mID = " << e.mID << ", e.mAge = " << e.mAge << endl;
   cout << "f.mID = " << f.mID << ", f.mAge = " << f.mAge << endl;
   return 0;
}




#endif
