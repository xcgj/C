//#include <stdio.h>//���ַ���תΪ����
//int main()
//{
//	char a[10] = "1234";
//	int i = 0;
//	while (a[i++]);
//	i -= 2;//����±�
//	//printf("%d\n", i);
//	int j = 0;
//	int sum = 0;
//	int e = 0;
//	for (j = i; j >= 0; j--)
//	{
//		int ee = e;
//		int sum1 = 1;
//		while (ee--)//����10�Ĵη�
//			sum1 *= 10;
//		sum += (a[j] - '0') * sum1;
//		e++;//����10�Ĵη���
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