//判断长度,

//每切割一次接收一次字符串，赋值给缓冲二维字符数组

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cut(char *s, char c, char(*p)[6], int *count)//方法一
{
	if (s == NULL || count == NULL)
		return -1;
	int len = strlen(s);
	char *p0 = s;
	char *p1 = NULL;
	char *p2 = NULL;
	int i = 0;
	//切割，一个指针指向起始端，另一个指向结尾一端
	for (;p0 < s + len + 1; p0++)// + 1 算上字符\0
	{
		if (p1 == NULL)
			p1 = p0;
		p2 = p0;
		if(c == *p0 || *p0 == '\0')
		{
			if (p2 - p1 > 0)//判断切割符是否连续
			{//每切割一次接收一次字符串，赋值给缓冲二维字符数组
				strncpy(p[i], p1, p0 - p1);//拷贝字符串
				p[i][p0 - p1] = '\0';//字符串数组结尾补0
				p1 = p2 = NULL;
				i++;//计数器，下标计算
			}
			else
				p1 = p2 = NULL;
		}
	}
	*count = i;
	return 0;
}

int cut2(char *s, char c, char(*p)[6], int *count)//方法二
{
	if (s == NULL || count == NULL)
		return -1;
	char *p1 = s;
	char *p2 = s;
	int i = 0;
	while (*p2)
	{
		p2 = strchr(p2, c);//到达切割点位置
		if (p2 != NULL)
		{
			if (p2 - p1 > 0)//判断切割符是否连续
			{//每切割一次接收一次字符串，赋值给缓冲二维字符数组
				strncpy(p[i], p1, p2 - p1);
				p[i][p2 - p1] = '\0';
				i++;
			}
			p1 = p2 = p2 + 1;//离开切割点
		}
		else
		{
			strncpy(p[i], p1, sizeof p1);//末端子串p1处理
			p[i][sizeof p1] = '\0';
			i++;
			break;
		}
	}
	*count = i;
	return 0;
}

int main__2(void) 
{
	char s[100] = ",1234,,,5678,,9012,";
	char c = ',';
	char a[10][6];
	int ct = 0;
	int res = cut2(s, c, a, &ct);
	int i = 0;
	int j = 0;
	if (res != 0)
	{
		printf("func cut error: %d\n", res);
		return 0;
	}
	for (i = 0; i < 3; i++)
		printf("%s \n", a[i]);
	return 0;
}