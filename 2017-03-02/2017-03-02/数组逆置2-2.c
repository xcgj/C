#include <stdio.h>
int main02(void)
{
	int a[] = { 1, 0, 2, 4 , 5 };
	int times = sizeof a / sizeof a[0] - 1;//��������±�
	int max = times;
	int min = 0;//������С�±�
	//��min < max,���ν���ֵ
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