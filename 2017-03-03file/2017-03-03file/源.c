#include <stdio.h>

void myitoa(char *s, int i)
{
	//计算整数长度
	int index = 0;
	int k = i;
	while (k)
	{
		k /= 10;
		index++;//位数
	}
	//最低开始依次加'0'，直到高位，逆序放入字符串数组
	int j = 0;
	for (j = index - 1; j >= 0; j--)
	{
		s[j] = (i % 10) + '0';
		i /= 10;
	}
}




int main(void)
{
	int i = 1024;
	char chara[100] = { 0 };
	myitoa(chara, i);
	printf("%s\n", chara, i);
	return 0;
}
