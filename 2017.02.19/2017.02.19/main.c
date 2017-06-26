#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int main(int argc, char *args[])
//*args[]是二维数组
{
	if (argc != 4)
		printf("格式错误\n");
	else
	{
		float i = 0;
		int a = atoi(args[1]);
		int c = atoi(args[3]);
		char *s;
		//s = args[2];//args[]存放的是地址，不用&
		//char b = *s;//获取首地址里存放的内存值,即s[0]
		switch (args[2][0])
		{
		case '+':
			i = a + c;
			break;
		case '-':
			i = a - c;
			break;
		case '*':
			i = a * c;
			break;
		case '/':
			if (c != 0)
				i = (float)a / c;
			else
			{
				printf("error\n");
				return 0;
			}
			break;
		default:
			printf("运算符错误\n");
			return 0;
		}
		printf("%0.2f\n", i);
	}
	return 0;
}

int main02(int argc, char *args[])
{
	//system("dir");
	char get[100] = "dir";
	int i = 0;
	for (i = 1; i < argc; i++)
	{
		strcat(get, " ");
		strcat(get, *(args + i));
	}
	system(get);
	return 0;
}





int main01(int argc, char *args[])
//argc表示程序执行的时候有几个参数，程序名称也是一个参数
//char *args[]是一个指针数组，每个成员的类型是char *
//*args[] 成员的数量是argc个
{
	printf("%d\n", argc);
	int i = 0;
	for (i = 0; i < argc; i++)
	{
		printf("a[%d] = %s\n", i, args[i]);
	}
	return 0;
}