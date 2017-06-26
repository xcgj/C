#include <stdio.h>
int main01(void)
{
	int a[] = { 1, 0, 2, 4 , 5};
	int times = sizeof a / sizeof a[0] - 1;
	for (int i = 0; i <= times / 2; i++)
	{
		int temp = a[i];
		a[i] = a[times - i];
		a[times - i] = temp;
	}
	for (int j = 0; j <= times; j++)
		printf("a[%d] = %d\n", j, a[j]);
	return 0;
}