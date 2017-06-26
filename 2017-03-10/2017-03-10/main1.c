#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sub_max(int *s, int *sub, int len)
{
	//1 定义两个指针分别指向数组，其中一个后移，将和相加
	//2 记录最大值
	//3 遇到负数p1指针直接跳过
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
				p2 = p1;//每次外循环，p1和p2指向同一地址
				int sum = *p1;
				while (p2 < s + len -1)
				{
					p2++;//p2先走一步
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