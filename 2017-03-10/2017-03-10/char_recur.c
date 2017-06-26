#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void recur_char_stock(char *s, char *q)//利用参数进出栈的特点，结合递归的特点进行字符串逆置
{
	char *p = s;
	if (p == NULL)
		return;
	if (*p == '\0')
		return;//递归终止条件
	recur_char_stock(p + 1, q - 1);
	printf("%c", *p);
	*q = *p;
	//q = q - 5;//为啥写和没写结果一样？？？
	//q的地址每次都是从顺次递归的函数实参获得的，与逆次递归的地址没有关系
}

int main00000(void) 
{
	char *p = (char *)malloc(100 * sizeof(char));
	strcpy(p, "abcdefg");
	char q[100] = { 0 };
	recur_char_stock(p, q + 6);
	printf("\n%s\n", q);
	return 0;
}