#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct info
{
	char name[100];
	char addr[100];
	int age;
}info;

int print(info *d, int *m)
{
	if (d == NULL)
	{
		printf("error:-3, func print has NULL pointer\n");
		return -3;
	}
	int i = 0;
	for (; i < *m; i++)
		printf("%s\t%d\t%s\n", (d + i)->name, (d + i)->age, (d + i)->addr);
	return 0;
}

int getinfo(info *b)
{
	b = (info *)malloc(sizeof(info));
	if (b == NULL)
	{
		printf("error, NULL pointer\n");
		return -1;
	}
	info *c = NULL;
	int count = 0;
	char cmd[20] = { 0 };
	int result = 0;
	printf("请输入命令和信息，请用空格分开：\n");
	while (1)
	{
		memset(cmd, 0, sizeof(char) * 20);  //重置命令缓存
		scanf("%s", cmd);                   //获得命令
		if (strcmp(cmd, "exit") == 0)
			break;
		else if (strcmp(cmd, "print") == 0)	
		{
			if (count == 0)					//第一次就打印，提示错误
			{
				printf("error:-2, no information input\n");
				free(b);
				b = NULL;
				return -2;
			}
			result = print(b, &count);
		}
		else if (strcmp(cmd, "add") == 0)
		{
			c = (info *)realloc(b, sizeof(info) * (count + 1));//加内存空间
			if (c == NULL)					//加内存空间失败，退出
			{
				printf("error:-4, NULL pointer, memory allocate fail\n");
				free(b);
				b = NULL;
				return -4;
			}
			b = c;
			scanf("%s %d %s", b[count].name, &b[count].age, b[count].addr);
			count++;						//记录下标
		}
		else
		{
			printf("error:-5, invalid cmd\n");
			return -5;
		}
	}
	printf("程序退出\n");
	free(b);
	b = NULL;
	return result;
}

int main(void)
{
	info *s = { 0 };
	int res = 0;
	res = getinfo(s);
	if (res == 0)
		printf("complete\n");
	else
		printf("program dumped\n");
	return 0;
}

