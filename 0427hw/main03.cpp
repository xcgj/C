#include <iostream>

using namespace std;

//03 �����ʵ�ֽ�����������������á���ͨ���������öԸ����鸳ֵ��(����2�ַ�ʽ)
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

int main03(void)
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
