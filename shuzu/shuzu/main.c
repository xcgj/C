#include <stdio.h>
int main01()//统计混合汉字字母的字符串个数
{
	char arr[100] = "你s好hiy世c界";
	int lenth = 0;
	while (arr[lenth++]);//统计数组实际使用字节长度，包含字符串末尾的0
	lenth--;//统计数组非零字节长度，此例=13
	int lenstr = 0;
	int loop = 0;
	while(loop <= lenth-1)//loop取值:0-12；lenth取值:1-13,相差1
	{
		lenstr++;//统计字符长度
		if (arr[loop] < 0)//汉字字节数+2
		{
			loop += 2;
		}
		else//字母字节数+1
		{			
			loop++;
		}
	}
	printf("%d\n", lenstr);
	return 0;
}

int main02()
{
	char arr[100] = "你s好hiy世c界";
	int len = 0;//字符长度
	int i = 0;//循环次数
	while (arr[i])//值为零终止
	{
		if (arr[i] < 0)//遇到汉字进一位
			i++;
		i++;//不是汉字正常递增
		len++;
	}
	printf("The lenth of the arr is:%d\n", len);
	return 0;
}

int main()//去除字符串左侧空格
{
	char arr[100] = "你 y   ";
	int len = 0;
	while (arr[len++]);
	len--;//字节数
	len--;//最大非0下标
	while (arr[len--] == ' ');
	arr[len + 2] = 0;
	printf("(%s)\n", arr);
	return 0;
}