#include <stdio.h>
int main_n2(void)
{
	//1������buffer�������ַ�����
	//2-1������buffer����ÿ���ַ�-��0����
	//2-2��Ȩֵ1*10*10����ѭ�����������
	char buf[100] = "10086";
	int number = 0;
	int index = 0;
	int E = 1;
	while (buf[index++]);//1
	printf("%d\n", index);
	for (int i = index - 2; i >= 0; i--)//2-1
	{//index - 2 ���������,whileѭ������'\0',�����Լ���һ��
		number += E * (buf[i] - '0');//2-2
		E *= 10;
	}
	printf("%d\n", number);
	return 0;
}