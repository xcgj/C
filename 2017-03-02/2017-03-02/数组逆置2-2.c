#include <stdio.h>
int main02(void)
{
	int a[] = { 1, 0, 2, 4 , 5 };
	int times = sizeof a / sizeof a[0] - 1;//数组最大下标
	int max = times;
	int min = 0;//数组最小下标
	//当min < max,依次交换值
	while (min < max)
	{
		int temp = a[min];
		a[min] = a[max];
		a[max] = temp;
		min++;
		max--;
	}
	for (int j = 0; j <= times; j++)
		printf("a[%d] = %d\n", j, a[j]);
	return 0;
}