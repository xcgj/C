#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#pragma warning(disable:4996)
int main01()
{
	char a[100];
	scanf("%s", a);//scanf以回车键作为结束标识，但回车键不会被输入到字符串中
	//如果scanf参数中的数组长度小于用户在键盘输入的长度，那么scanf就会缓冲区溢出，导致程序崩溃
	printf("%s\n", a);
	return 0;
}

int main02()
{
	char b[50] = { 0 };
	gets(b);//gets函数不以空格为结束标识，可输入空格，但也存在缓冲溢出的问题
	int i;
	for (i = 0; i < 15; i++)
	{
		printf("b[%d]=%d, b[%d]=%c\n", i, b[i],i, b[i]);
	}
	return 0;
}

int main03()
{
	char a[50] = { 0 };
	char b[50] = { 0 };
	gets(a);
	gets(b);
	int a1 = atoi(a);//"atoi()"：将字符串转为一个整数
	int b1 = atoi(b);
	printf("%d\n", a1 + b1);
	return 0;
}

int main04()
{
	char a[10];
	fgets(a, 9, stdin);
	printf("%s\n", a);
	puts(a);//只能输出字符串，不能输出整型
	return 0;
}

int main05()
{
	char a[10] = "xcgj001";
	fputs(a, stdout);
	printf("%s\n", a);
	return 0;
}

