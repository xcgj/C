#include <stdio.h>
//#pragma warning(disable:4996)
int main08()
{
	int a = 0;
	int n = 0;
	int i = 0;
	while (1)
	{
		scanf_s("%d", &a);
		if (a == 0)
		{
			printf("Program exit!\n");
			break;
		}
		for (n = 1; n <= a; n++)
		{
			for (i = 0; i < (a - n); i++)
			{
				printf(" ");
			}
			for (i = 0; i < (2 * n - 1); i++)
			{
				printf("*");
			}
			printf("\n");
		}
	}
	return 0;
}






int main07()
{
	int a = 1;
	int i, j, k, b, c, sum;
	for (a = 1; a < 1000; a++)
	{
		for (b = a, i = 0; b != 0; b /= 10)//求出位数
		{
			i++;
		}
		c = a;
		for (j = 0, sum = 0; j < i; j++)
		{
			k = (c % 10);
			sum += k * k * k;
			c /= 10;
		}
		if(sum == a)
		{
			printf("%d\n", a);
		}
	}
	return 0;
}










int main06()
{
	int a;
	scanf_s("%d", &a);
	int i = 0;
	for (;a != 0; a /= 10)
	{
		i++;
	}
	printf("%d\n", i);
	return 0;
}








int main11(void)
{
	int a = 0;
	int b = 0;
	int sum = 0;
	scanf_s("%d", &b);
	while (a <= b)
	{
		if (1 == a % 2)
			sum += a;
		a++;

	}
	printf("%d\n", sum);
	return 0;
}