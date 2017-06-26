//1、求数组中第二大的元素的值。
#include <stdio.h>
int main__1(void)
{
	int a[] = { 1,3,99,88,77,222,9222 };
	int max = a[0];
	int i;
	for (i = 1; i < sizeof(a) / sizeof(a[0]); i++)
		max = (max < a[i]) ? a[i] : max;
	int smax = a[0];
	for (i = 1; i < sizeof(a) / sizeof(a[0]); i++)
		smax = (smax < a[i] && a[i] < max) ? a[i] : smax;
	printf("%d\t%d\n", max, smax);
	return 0;
}