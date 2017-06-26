#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

void swap(int *a, int *b)//互换
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void paixu(int *a, int line)//排序
{
	int i = 0;
	int j = 0;
	for (i = 0; i < line; i++)
		for (j = 1; j < line - i; j++)
			if (a[j] < a[j - 1])
				swap(&a[j], &a[j - 1]);
}

void print(int *a, int num)
{
	int i = 0;
	for (i = 0; i < num; i++)
		printf("a[%d] = %d\n", i, a[i]);
}

int main00()
{
	//创建临时字符数组和整型数组存储输入
	int integer[100];
	char character[100];
	int i = 0;
	//print(integer, 10);
	//paixu(integer, 10);
	//print(integer, 10);
	//打开文件1
	FILE *p = fopen("E:\\C_project\\file5.txt", "r");
	//文件1抠出字符到字符数组, !feof()	fgets()
	while (!feof(p))
	{
		//将缓存字符串内存清零
		memset(character, 0, sizeof(character));
		fgets(character, sizeof(character), p);
		//printf("%s", character);
		//字符数组atoi拷贝到整型数组, 用i++记录有几行
		integer[i] = atoi(character);
		i++;
	}
	//关闭文件1
	fclose(p);
	//整形数组排序
	paixu(integer, i);
	//print(integer, i);
	//打开文件2，整形数组sprintf拷贝到文件2
	p = fopen("E:\\C_project\\file6.txt", "w");
	int j = 0;
	for (j = 0; j < i; j++)
	{
		//将缓存字符串内存清零
		memset(character, 0, sizeof(character));
		//将int型的数组用sprintf存到字符串区
		//sprintf用法：sprintf(字符串地址，“int数字”，int型变量);
		sprintf(character, "%d\n", integer[j]);
		//将字符串放到文件2里
		fputs(character, p);
	}
	//关闭文件2
	fclose(p);
	return 0;
}

