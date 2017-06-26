#include <stdio.h>

int main()
{
	char c = 127;	//0111 1111
	unsigned char b;
	c = c + 5;	//1000 0100
	b = c;	//1000 0100
	printf("%d\n", c);	//c是有符号char，先判断符号位再求值
	//符号位是负，则计算机存储的二进制是补码，求值需转换成原码
	//补码 000 0100 → 原码 111 1100，原码值加上符号位得到 -124
	printf("%d\n", b);	//b是无符号char，无需判断符号位，按正数输出
	return 0;
}