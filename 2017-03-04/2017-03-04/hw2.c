#include <stdio.h>
#pragma warning(disable:4996)

int isOddNumber(unsigned int);

int main_hw2(void)
{
	unsigned a;
	printf("������һ��������");
	scanf("%u", &a);
	while (isOddNumber(a))
	{
		printf("����\n");
		return 0;
	}
	printf("ż��\n");
	return 0;
}

int isOddNumber(unsigned int number)
{
	return (0 == number % 2) ? 0 : 1;
}