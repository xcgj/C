//#include <stdio.h>//将字符串转为整型
//int main()
//{
//	char a[10] = "1234";
//	int i = 0;
//	while (a[i++]);
//	i -= 2;//最大下标
//	//printf("%d\n", i);
//	int j = 0;
//	int sum = 0;
//	int e = 0;
//	for (j = i; j >= 0; j--)
//	{
//		int ee = e;
//		int sum1 = 1;
//		while (ee--)//计算10的次方
//			sum1 *= 10;
//		sum += (a[j] - '0') * sum1;
//		e++;//计算10的次方根
//	}
//	printf("%d\n", sum);
//	return 0;
//}


#include <stdio.h>

int main()
{
	char a[100] = "abc";
	char b[100] = "cb";
	printf("%d\n", strcmp(a, b));
	return 0;
}