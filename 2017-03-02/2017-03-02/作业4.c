//4. ����Ļ������һ���ַ���\(����Ϊn\)
//ͳ�����г��ֵĴ�д��ĸ��Сд��ĸ�������ַ����հ��ַ�\(' ', '\n'��'\t'��\)�ȵ�������
#include <stdio.h>
int main__4(void)
{
	char cha[] = "\t\t\t\t\taaaaaAAAAA12345     \n\n\n\n\n";
	int i = 0;
	int length = 0;
	while (cha[length++]);
	length--;//�����ַ�����
	int A = 0;
	int a = 0;
	int number = 0;
	int space = 0;
	int n = 0;
	int t = 0;
	for (i = 0; i < length; i++)
	{
		if (cha[i] <=90 && cha[i] >= 65)//��д��ĸ
			A++;
		if (cha[i] <= 122 && cha[i] >= 97)//Сд��ĸ
			a++;
		if (cha[i] <= 57 && cha[i] >= 48)//����
			number++;
		if (cha[i] == ' ')//�ո�
			space++;
		if (cha[i] == '\n')//����
			n++;
		if (cha[i] == '\t')//�ո�
			t++;
	}
	printf("��д��ĸ=%d\nСд��ĸ=%d\n�����ַ�=%d\n' '=%d\n'\\n'=%d\n'\\t'=%d\n",
		A, a, number, space, n, t);
	return 0;
}