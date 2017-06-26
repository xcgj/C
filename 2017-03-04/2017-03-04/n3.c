#include <stdio.h>
int main_n2(void)
{
	//1、遍历buffer，计算字符长度
	//2-1、遍历buffer，将每个字符-‘0’，
	//2-2、权值1*10*10……循环，依次相加
	char buf[100] = "10086";
	int number = 0;
	int index = 0;
	int E = 1;
	while (buf[index++]);//1
	printf("%d\n", index);
	for (int i = index - 2; i >= 0; i--)//2-1
	{//index - 2 是最大索引,while循环读到'\0',还是自加了一次
		number += E * (buf[i] - '0');//2-2
		E *= 10;
	}
	printf("%d\n", number);
	return 0;
}