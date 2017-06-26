#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int cut(char *p, char *pbuf)
{
	//1 判断空指针
	//2 定义辅助指针
	//3 计算字符串长度
	//4 从头开始找非空字符，记下下标
	//5 从尾开始找非空字符，记下下标
	//6 算下标距离，strncpy过来
	//7 末尾加'\0'，组成字符串
	int res = 0;
	if (p == NULL || pbuf == NULL)		//1
		return res = -1;
	char *a = p;						//2
	int index = strlen(a) - 1;			//3 最大下标
	int i = 0;
	while (isspace(a[i]) && a[i] != '\0')//4
		i++;							//循环结束，在第一个非空字符位置
	while (isspace(a[index]) && a[index])//5
		index--;						//循环结束，在倒数第一个非空字符位置
	strncpy(pbuf, a + i, index - i + 1);//6
	//*(pbuf + index - i + 1) = '\0';	//主调函数已置零
	return 0;
}

int main(void) 
{
	char *s = "      asdf   ";
	char sbuf[100] = { 0 };
	int res = cut(s, sbuf);
	if (res != 0)
	{
		printf("function cut error:%d\n", res);
		return 0;
	}
	printf("%s", sbuf);
	return 0;
}