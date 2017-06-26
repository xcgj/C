//2、打印99乘法表效果1.png的99乘法表。
#include <stdio.h>
int main02()
{
	int i = 0;
	int j = 0;
	//打印列
	for (i = 1; i < 10; i++)
	{
		//打印行
		for (j = i; j < 10; j++)
		{
			printf("%-4d", i * j);
		}
		printf("\n");
	}
	return 0;
}