#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sub_max(int *s, int *sub, int len)
{
	//1 ��������ָ��ֱ�ָ�����飬����һ�����ƣ��������
	//2 ��¼���ֵ
	//3 ��������p1ָ��ֱ������
	if (s == NULL)
	{
		int res = -1;
		printf("func sub_max err:%d, (s == NULL)\n", res);
		exit(-1);
	}
	else
	{
		int *p1 = s;
		int *p2 = s;
		int result = 0;
		while (p1 < s + len -1)
		{
			if (*p1 < 0)//3
				p1++;
			else
			{
				p2 = p1;//ÿ����ѭ����p1��p2ָ��ͬһ��ַ
				int sum = *p1;
				while (p2 < s + len -1)
				{
					p2++;//p2����һ��
					sum += *p2;
					if (result < sum)
						result = sum;
				}
				p1++;
			}
		}
		*sub = result;
	}
}

int main01(void) 
{
	int arr[] = { 6, -1, 5, 4, -7, 100 };
	int sum = 0;
	sub_max(arr, &sum, 6);
	printf("%d\n", sum);
	return 0;
}