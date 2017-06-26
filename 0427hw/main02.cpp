#include <iostream>

using namespace std;

//02 编写程序，实现两个字符串变量的交换(使用引用和指针两种方式实现).

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

