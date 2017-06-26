/*3.	钻石 or 玉石。
	钻石一颗20000，玉石一颗15000
	函数原型 int isEqual(int diamonds,int jade)
	函数功能 将diamonds颗数量的钻石的价值和jade颗玉石的价格进行比较
	函数返回值 如果钻石价值大则返回1  如果相等返回0 如果钻石价值小则返回-1*/
#include <stdio.h>
#pragma warning(disable:4996)

int isEqual(int, int);

int main_hw3(void)
{
	int a = 0;
	printf("请输入钻石的数量：");
	scanf("%d", &a);
	int b = 0;
	printf("请输入玉石的数量：");
	scanf("%d", &b);
	int c = isEqual(a, b);
	if (1 == c)
		printf("钻石价值大\n");
	else if (-1 == c)
		printf("玉石价值大\n");
	else if (0 == c)
		printf("钻石玉石价值一样\n");
	return 0;
}

int isEqual(int diamonds, int jade)
{
	if (diamonds * 20000 > jade * 15000)
		return 1;
	else if (diamonds * 20000 == jade * 15000)
		return 0;
	return -1;
}