/*5.  ��д�����������UTF - 8����ĺ����ַ����Ĺ��ܡ�<ֻ��Ҫ��Linux�ϲ���>
	input:�Ұ���886
	output : 688�㰮��
*/
#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int inverse(char *s, int len)//����
{
	int i = 0;
	for (i = 0; i < len / 2; i++)//ѭ��һ������������
	{
		int temp = s[i];
		s[i] = s[len - 1 - i];//����±�ȳ���С1
		s[len - 1 - i] = temp;
	}
}

int adjust(char *s, int len)
{
	int i = len - 1;//����±�
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
	char str[100] = "�Ұ���886";
	//1 �����ַ�������
	//2 ��ȫ������
	//3 ���ַ���β����ʼ����ַ��Ƿ�С��0����ʼ����λ��
	int length = strlen(str);//1
	inverse(str, length);//2
	adjust(str, length);//2
	printf("%s\n", str);
	return 0;
}