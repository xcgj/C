/*5.  编写函数完成逆置UTF - 8编码的汉字字符串的功能。<只需要在Linux上测试>
	input:我爱你886
	output : 688你爱我
*/
#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int inverse(char *s, int len)//逆置
{
	int i = 0;
	for (i = 0; i < len / 2; i++)//循环一半就能完成逆置
	{
		int temp = s[i];
		s[i] = s[len - 1 - i];//最大下标比长度小1
		s[len - 1 - i] = temp;
	}
}

int adjust(char *s, int len)
{
	int i = len - 1;//最大下标
	while(i >= 0)
	{
		if (s[i] < 0)
		{
			int temp = s[i];
			s[i] = s[i - 1];
			s[i - 1] = temp;
			i -= 2;
		}
		else
			i--;
	}
}

int main(void)
{
	char str[100] = "我爱你886";
	//1 计算字符串长度
	//2 先全部逆置
	//3 从字符串尾部开始检测字符是否小于0，开始调整位置
	int length = strlen(str);//1
	inverse(str, length);//2
	adjust(str, length);//2
	printf("%s\n", str);
	return 0;
}