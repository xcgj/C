#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copy_(char *from, char *to)
{
	char *temp_from = from;//不要轻易改变形参的值
	char *temp_to = to;
	if (temp_from == NULL || temp_to == NULL)//避免主调函数没给指针分配内存空间
	{
		printf("error, operand NULL\n");
		exit(-1);
	}
	else
	{
		while (*temp_to++ = *temp_from++);
		printf("%s\n", to);//注意不是temp_to，已经位移
	}
}
int main01(void) 
{
	char *source = "abcde";
	char *destiney = NULL;//建议初始化
	destiney = (char *)malloc(100 * sizeof(char));
	copy_(source, destiney);
	return 0;
}