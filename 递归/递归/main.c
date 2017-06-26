////#include <stdio.h>
////
////void test(int n)
////{
////	if (n > 0)
////	{
////		n--;
////		printf("先序n=%d\n", n);//先序递归，代码顺序执行，从递归起始处往后执行
////		test(n);//自己调用自己，就叫函数的递归
////		printf("后序n=%d\n", n);//逆序递归，代码逆序执行，从递归终止处往回执行
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
//	int i = n / 2;//存放商
//	int j = n % 2;//存放余数
//	if (i == 1 || i == 0)//判断是否到达递归终点
//	{
//		printf("%d", i);
//		printf("%d", j);
//	}
//	else
//	{
//		Two(i);
//		printf("%d", j);//逆序输出
//	} 
//}
//
//void simple(int n)
//{
//	int i = n % 2;//存放余数
//	if (n > 0)//判断是否到达递归终点,n==0
//	{
//		simple(n / 2);//存放商
//		printf("%d", i);//逆序输出
//	}
//}
//
//int main()
//{
//	int k = 254;
//	printf("k的二进制是：");
//	simple(k);
//	printf("\n");
//}

#include <stdio.h>
int fbi(char a[], int i)//求字符串长度
{
	if (a[i] == 0)
		return 0;//如果写成“return i;”，那么else语句那就不用逆序+1，即：return fbi(a, i + 1);
	else
		return fbi(a, i + 1) + 1;//好像不能用i++
}
int main()
{
	char arr[] = "1a3";
	printf("%d\n", fbi(arr, 0));
	return 0;
}
