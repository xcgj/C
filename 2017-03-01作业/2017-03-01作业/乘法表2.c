//3、打印99乘法表效果2.png的99乘法表。
#include <stdio.h>
int main03()
{
	int i = 0;
	int k = 0;
	int j = 0;
	//打印列
	for (i = 1; i < 10; i++)
	{
		//打印制表符
		for (j= 0; j <= i - 1; j++)
		{
			printf("\t");
		}
		//打印行
		for (k = i; k < 10; k++)
		{
			printf("%d\t", i * k);
		}
		printf("\n");
	}
	return 0;
}