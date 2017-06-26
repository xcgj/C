#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main()
{
	int a[5] = { 7,8,10,15, 12};
	int max = a[0] > a[1] ? a[0] : a[1];
	int smax = a[0] < a[1] ? a[0] : a[1];
	int i;
	for (i = 2; i < 5; i++)
	{
		if (max < a[i])
		{
			int dex = 0;
			dex = max;
			max = a[i];
			a[i] = dex;
		}
		else if (smax < a[i])
		{
			int dex = 0;
			dex = smax;
			smax = a[i];
			a[i] = dex;
		}
	}
	printf("%d\n", smax);
	return 0;
}









int main03()
{
	int *p = calloc(sizeof(int), 100);
	//int *p = calloc(100, sizeof(int)); 等效
	int *q = realloc(p, sizeof(int) * 200);
	memset(q + 100, 0, sizeof(int) * 100);
	//将400字节后的值初始化为0，但是不对前400字节的值作修
	free(q);
	return 0;
}





















int getab();
void printab();

int main01()
{
	int *pointer = getab();
	*pointer = 500;
	printab();
	return 0;
}