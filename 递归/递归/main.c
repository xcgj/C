////#include <stdio.h>
////
////void test(int n)
////{
////	if (n > 0)
////	{
////		n--;
////		printf("����n=%d\n", n);//����ݹ飬����˳��ִ�У��ӵݹ���ʼ������ִ��
////		test(n);//�Լ������Լ����ͽк����ĵݹ�
////		printf("����n=%d\n", n);//����ݹ飬��������ִ�У��ӵݹ���ֹ������ִ��
////	}
////}
////
////int main()
////{
////	int a = 3;
////	test(a);
////	return 0;
////}
//
//#include <stdio.h>
//void Two(int n)
//{
//	int i = n / 2;//�����
//	int j = n % 2;//�������
//	if (i == 1 || i == 0)//�ж��Ƿ񵽴�ݹ��յ�
//	{
//		printf("%d", i);
//		printf("%d", j);
//	}
//	else
//	{
//		Two(i);
//		printf("%d", j);//�������
//	} 
//}
//
//void simple(int n)
//{
//	int i = n % 2;//�������
//	if (n > 0)//�ж��Ƿ񵽴�ݹ��յ�,n==0
//	{
//		simple(n / 2);//�����
//		printf("%d", i);//�������
//	}
//}
//
//int main()
//{
//	int k = 254;
//	printf("k�Ķ������ǣ�");
//	simple(k);
//	printf("\n");
//}

#include <stdio.h>
int fbi(char a[], int i)//���ַ�������
{
	if (a[i] == 0)
		return 0;//���д�ɡ�return i;������ôelse����ǾͲ�������+1������return fbi(a, i + 1);
	else
		return fbi(a, i + 1) + 1;//��������i++
}
int main()
{
	char arr[] = "1a3";
	printf("%d\n", fbi(arr, 0));
	return 0;
}
