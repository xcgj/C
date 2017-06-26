#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char extbuf[100] = { 0 };

void char_recur(char *p, char *buffer)
{
	if (p == NULL || buffer == NULL)
		return;
	if (*p == '\0')
		return;
	char_recur(p + 1, buffer);
	strncat(buffer, p, 1);
}

void char_recur2(char *p)
{
	if (p == NULL)
		return;
	if (*p == '\0')
		return;
	char_recur2(p + 1);
	strncat(extbuf, p, 1);
}

int main022(void) 
{
	char *p = (char *)malloc(100 * sizeof(char));
	memset(p, 0, 100 * sizeof(char));
	strcpy(p, "abcdefg");
	char *buffer = (char *)malloc(100 * sizeof(char));
	memset(buffer, 0, 100 * sizeof(char));
	memset(extbuf, 0, 100 * sizeof(char));
	
	char_recur(p, buffer);
	char_recur2(p);//使用全局变量接收，在多线程运行时可能会出错

	printf("%s\n", buffer);
	printf("%s\n", extbuf);
	return 0;
}