#include <stdio.h>
#include <time.h>
#include <stdlib.h>
//编写随机数函数
//编写双色球函数
//比较双色球序列和用户序列
//flag标记红球猜对个数
//判断获奖

int ProNum(int *a)//实参传个数组存放7个序列
{
	srand((unsigned int)time(NULL));
	a[6] = rand() % 16 + 1;//蓝球的号码
	int i, j;
	for (i = 0; i < 6; i++)//红球的号码
	{
		a[i] = rand() % 33 + 1;
		for (j = 0; j < i; j++)//将生成的新数和前几个数比较
			if (a[i] == a[j])
			{
				i--;
				break;
			}
	}
	return 0;
}

int GetUserNum(int *a)
{
	int i, j;
	printf("请输入6个不同的红球的数字(1-33)：\n");
	for (i = 0; i < 6; i++)
	{
		printf("第%d个红球(1-33)：", i + 1);
		scanf("%d", &a[i]);
		if (a[i] < 1 || a[i] > 33)
		{
			printf("错误，数字不在范围内，需要重新输入\n");
			i--;
			continue;
		}
		for (j = 0; j < i; j++)
			if (a[j] == a[i])
			{
				printf("错误，数字重复。需要重新输入\n");
				i--;
				break;
			}
	}
	while (1)
	{
		printf("请输入1个蓝球的数字(1-16)：\n");
		scanf("%d", &a[6]);
		if (a[6] < 1 || a[6] > 16)
		{
			printf("错误，数字不在范围内，需要重新输入\n");
			continue;
		}
		else
			break;
	}
	return 0;
}


int Print(int *a)
{
	int i;
	for (i = 0; i < 7; i++)
		printf("a[%d] = %d\n", i, a[i]);
	return 0;
}

int Compare(int *a, int *b)
{
	int flag = 0;
	int i, j;
	for (i = 0; i < 6; i++)
		for (j = 0; j < 6; j++)
			if (a[i] == b[j])
				flag++;
	if (a[6] == b[6] && flag < 3)	//中蓝球没中红球，6等奖
		return 6;
	if (a[6] != b[6])	//判断2等奖
		if (flag == 6)
			return 2;
	if (a[6] == b[6])			//中了蓝球
		flag++;
	switch (flag)		//判断猜中的数量
	{
	case 7:
		return 1;
	case 6:
		return 3;
	case 5:
		return 4;
	case 4:
		return 5;
	default:
		return 0;
	}	
}

int main(void)
{
	int array[7] = { 0 };
	int brray[7] = { 0 };
	ProNum(array);
	//Print(array);
	GetUserNum(brray);
	//Print(brray);
	int res = Compare(array, brray);
	if (res != 0)
		printf("恭喜中了%d等奖\n", res);
	else
		printf("谢谢惠顾\n");
	return 0;
}
