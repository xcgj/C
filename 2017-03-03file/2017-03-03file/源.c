#include <stdio.h>

void myitoa(char *s, int i)
{
	//������������
	int index = 0;
	int k = i;
	while (k)
	{
		k /= 10;
		index++;//λ��
	}
	//��Ϳ�ʼ���μ�'0'��ֱ����λ����������ַ�������
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
