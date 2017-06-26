#include <stdio.h>
#pragma warning(disable:4996)
int main_2(void)
{
	FILE *p = fopen("E:\\C_project\\file1.txt", "r");//表示以二进制方式读取，不忽略'\r'
	while (!feof(p))
	{
		char buffer[15] = { 0 };
		int a = fread(buffer, sizeof(char), 3, p);//每次读三个
		for (int i = 0; i < a; i++)//遍历这三个数
			printf("buffer[%d] = %x\n", i, buffer[i]);
	}
	return 0;
}