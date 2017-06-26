//07 编写MySwap函数，要求MySwap函数可以实现以下数据类型的交换功能,并编写测试案例.
   //int,double,
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
