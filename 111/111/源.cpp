#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char a[100];
    char b[100];
}A;

int main()
{   
	A norm = { 0 }, max = { 0 }, smax = { 0 };
	FILE *p = fopen("E:\\sort.txt", "r");
	if (p == NULL)
		return -1;
	int i = 0;//计算下标
	for (; !feof(p); i++)
	{
		char buf[100] = { 0 }, buf2[100] = { 0 };
		fgets(buf, 100, p);//获得一行字符串
		strcpy(buf2, buf);//拷贝备份
		strcpy(norm.b, strchr(strchr(buf2, '=') + 1, '=') + 1); //strchr“=”，两次进一位，得到年龄
		if (atoi(norm.b) > atoi(max.b))
		{//条件成立才去算名字
			strcpy(norm.a, strtok(strchr(buf, '=') + 1, ","));
			smax = max;
			max = norm;
		}else if (atoi(norm.b) > atoi(smax.b))
		{//条件成立才去算名字
			strcpy(norm.a, strtok(strchr(buf, '=') + 1, ","));
			smax = norm;
		}
		if (feof(p))//读到文件末行，不用继续循环
			break;
	}
	printf(" %s 的年龄是第二大，是 %d 岁\n", smax.a, atoi(smax.b));
	fclose(p);
	return 0;
}