#include <stdio.h>
#pragma warning(disable:4996)

int isOddNumber(unsigned int);

int main_hw2(void)
{
	unsigned a;
	printf("请输入一个正数：");
	scanf("%u", &a);
	while (isOddNumber(a))
	{
		printf("奇数\n");
		return 0;
	}
	printf("偶数\n");
	return 0;
}

int isOddNumber(unsigned int number)
{
	return (0 == number % 2) ? 0 : 1;
}