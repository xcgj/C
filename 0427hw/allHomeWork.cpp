
#if 0

01 ��˵��������:
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


02 ��д����ʵ�������ַ��������Ľ���(ʹ�����ú�ָ�����ַ�ʽʵ��).
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


03 �����ʵ�ֽ�����������������á���ͨ���������öԸ����鸳ֵ��(����2�ַ�ʽ)
   int arr[10];


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



04 ������C��C++��const������

ȫ��const������ڳ��������ֲ�const�������ջ�����ֲ�const������ָ�����޸�const��ֵ
C:ȫ��connst��extern�ģ�ȫ�ֺ;ֲ�const��������ڴ�ռ�
C++��ȫ��constĬ����static�ģ�ȫ�ֺ;ֲ�const������ȡ��ַ����extern�������߸�����������ʱ�Ż����ռ䣬���constû�з���ռ䣬�������ڱ���ʱ���ܻᷢ��ֵ�۵�����volatile�͸�ֵ����ʱ���⣩

05 ��������������������?�Լ����������ͺ꺯��������
�����������ã����ٺ���ѹջ��ջ���صĲ����������ڴ滻Ч��
�꺯��û�в���������ֵ���ͼ�飻û�����������Ʋ��ܳ�Ϊ��ĳ�Ա������Ԥ����ֱ���ı��滻���ܻ�ʹ�������߼����󣬵ò�����Ҫ�Ľ��

06 ��˵�����´����Ƿ�ᷢ��������������������һ�д���ᷢ������˵��ԭ��
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
        cout << add(a, c) << endl;//�����Ҳ�����������ƥ������غ���add(int, double)
    }


07 ��дMySwap������Ҫ��MySwap��������ʵ�������������͵Ľ�������,����д���԰���.
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
