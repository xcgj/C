#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int myatoi(char *s)
{
	int i = 0;
	while (s[i] != ' ')
	{
		i++;//�����ĳ���
	}
	i--;//�ַ�����±�
	int j = 0;
	int sum = 0;
	int k = 1;//����10�Ĵη�
	for (j = i; j >= 0; j--)//��������
	{
		sum += k * (s[j] - '0');
		k *= 10;//����Ȩֵ
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
	//���建���ַ�����1��2
	char buffer1[100];
	char buffer2[100];
	//���ļ�
	FILE *p = fopen("E:\\C_project\\file5.txt", "r");
	//!feof(p)
	int index_2 = 0;
	while (!feof(p))
	{
		memset(buffer1, 0, sizeof buffer1);
		//fgets����ַ����浽�ַ���1��calculate���㣬����浽�ַ���2
		fgets(buffer1, sizeof buffer1, p);

		puts(&buffer1[3]);
	}

	//�ر��ļ�

	//���ļ�1��2
	//!feof(p)  
	//fgets()�õ��ļ�1���ַ���1���ַ���2��fputs()�ַ���1���ַ���2�ֱ������ļ�2
	//�ر��ļ�1��2
	return 0;
}