#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

void swap(int *, int *);
void paixu(int *, int);
void print(int *, int );

int main_1()
{
	//定义缓冲字符串数组
	char buffer[100] = { 0 };

	//变量len计算元素长度
	int len = 0;

	//打开文件1
	FILE *p = fopen("E:\\C_project\\file5.txt", "r");
	// !feof() fgets()将行数搞出来
	while (!feof(p))
	{
		memset(buffer, 0, sizeof buffer);
		fgets(buffer, sizeof buffer, p);//这步不能省略，否则死循环，why？？？？？
		len++;
	}
	//关闭文件1
	fclose(p);
	printf("%d\n", len);
	//定义换成整型数组
	//int integer[len];
	//打开文件1

	// !feof() fgets() atoi将每一行抠出来给字符串，再转给整型数组

	//关闭文件1

	//整型数组排序

	//打开文件2

	//for循环 sprintf() 依次把整型数组元素给字符串，再输出到文件

	//关闭文件2
	return 0;
}