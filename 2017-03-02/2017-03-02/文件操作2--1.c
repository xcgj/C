#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

void swap(int *, int *);
void paixu(int *, int);
void print(int *, int );

int main_1()
{
	//���建���ַ�������
	char buffer[100] = { 0 };

	//����len����Ԫ�س���
	int len = 0;

	//���ļ�1
	FILE *p = fopen("E:\\C_project\\file5.txt", "r");
	// !feof() fgets()�����������
	while (!feof(p))
	{
		memset(buffer, 0, sizeof buffer);
		fgets(buffer, sizeof buffer, p);//�ⲽ����ʡ�ԣ�������ѭ����why����������
		len++;
	}
	//�ر��ļ�1
	fclose(p);
	printf("%d\n", len);
	//���廻����������
	//int integer[len];
	//���ļ�1

	// !feof() fgets() atoi��ÿһ�пٳ������ַ�������ת����������

	//�ر��ļ�1

	//������������

	//���ļ�2

	//forѭ�� sprintf() ���ΰ���������Ԫ�ظ��ַ�������������ļ�

	//�ر��ļ�2
	return 0;
}