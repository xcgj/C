#include <stdio.h>

void count(int *p, int n)
{
	int sum = 0;
	int i = 0;
	for (i = 0; i < n; i++)
	{
		sum += *(p + i);
		printf("ar[%d] = %d\n", i, *(p + i));
	}
	printf("sum = %d\n", sum);
}