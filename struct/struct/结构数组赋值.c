#include <stdio.h>

struct excha
{
	int arr[5];
};

int main(void)
{
	struct excha a = { 0, 1, 2, 3, 4 };
	struct excha b = { 0 };
	b = a;
	int *p = b.arr;
	int i = 0;
	for (i = 0; i < 5; i++)
		printf("b[%d] = %d\n", i, *(p + i));
	return 0;
}