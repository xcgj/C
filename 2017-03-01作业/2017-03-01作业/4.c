//4.	编写代码求出给定的整数(0-255)中bit位上值为1的位数，比如65, 130，133
#include <stdio.h>
int main()
{
	int integer = 0;
	int count = 0;
	printf("请输入0-255间的任意整数：");
	scanf_s("%d", &integer);
	while (integer)
	{
		if(integer % 2)
			count++;
		integer /= 2;
	}
	printf("bit位上值为1的位数为：%d\n", count);
	return 0;
}