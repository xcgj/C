#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int myatoi(char *s)
{
	int i = 0;
	while (s[i] != ' ')
	{
		i++;//整数的长度
	}
	i--;//字符最大下标
	int j = 0;
	int sum = 0;
	int k = 1;//计算10的次方
	for (j = i; j >= 0; j--)//计算整数
	{
		sum += k * (s[j] - '0');
		k *= 10;//计算权值
	}
	return sum;
}

void print(int *, int);

int calculate(char *s)
{
	char sum;
	switch (*(s+1))
	{
	case '+':
		sum = *s + *(s+2);
		break;
	case '-':
		sum = *s - *(s + 2);
		break;
	case '*':
		sum = *s * *(s + 2);
		break;
	case '/':
		sum = *s / *(s + 2);
	}
	return sum;
}

int main__2()
{
	//定义缓冲字符数组1、2
	char buffer1[100];
	char buffer2[100];
	//打开文件
	FILE *p = fopen("E:\\C_project\\file5.txt", "r");
	//!feof(p)
	int index_2 = 0;
	while (!feof(p))
	{
		memset(buffer1, 0, sizeof buffer1);
		//fgets获得字符，存到字符组1，calculate计算，结果存到字符组2
		fgets(buffer1, sizeof buffer1, p);

		puts(&buffer1[3]);
	}

	//关闭文件

	//打开文件1、2
	//!feof(p)  
	//fgets()得到文件1的字符组1和字符组2，fputs()字符组1和字符组2分别输入文件2
	//关闭文件1、2
	return 0;
}