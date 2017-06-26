#include <stdio.h>

void while_(int i)
{
	int sum = 0;
	while (i <= 1000)
	{
		sum += (i % 10 == 0) ? i : 0;
		i++;
	}
	printf("while_calc = %d\n", sum);
}

void do_while(int i)
{
	int sum = 0;
	do
	{
		sum += (i % 10 == 0) ? i : 0;
		i++;
	} while (i <= 1000);
	printf("do_while_calc = %d\n", sum);
}

void for_(int i)
{
	int sum = 0;
	for (; i <= 1000; i++)
	{
		sum += (i % 10 == 0) ? i : 0;
		i++;
	}
	printf("for_calc = %d\n", sum);
}

int main_1(void)
{
	int i = 100;
	while_(i);
	do_while(i);
	for_(i);
	return 0;
}