#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

void swap(int *a, int *b)//����
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void paixu(int *a, int line)//����
{
	int i = 0;
	int j = 0;
	for (i = 0; i < line; i++)
		for (j = 1; j < line - i; j++)
			if (a[j] < a[j - 1])
				swap(&a[j], &a[j - 1]);
}

void print(int *a, int num)
{
	int i = 0;
	for (i = 0; i < num; i++)
		printf("a[%d] = %d\n", i, a[i]);
}

int main00()
{
	//������ʱ�ַ��������������洢����
	int integer[100];
	char character[100];
	int i = 0;
	//print(integer, 10);
	//paixu(integer, 10);
	//print(integer, 10);
	//���ļ�1
	FILE *p = fopen("E:\\C_project\\file5.txt", "r");
	//�ļ�1�ٳ��ַ����ַ�����, !feof()	fgets()
	while (!feof(p))
	{
		//�������ַ����ڴ�����
		memset(character, 0, sizeof(character));
		fgets(character, sizeof(character), p);
		//printf("%s", character);
		//�ַ�����atoi��������������, ��i++��¼�м���
		integer[i] = atoi(character);
		i++;
	}
	//�ر��ļ�1
	fclose(p);
	//������������
	paixu(integer, i);
	//print(integer, i);
	//���ļ�2����������sprintf�������ļ�2
	p = fopen("E:\\C_project\\file6.txt", "w");
	int j = 0;
	for (j = 0; j < i; j++)
	{
		//�������ַ����ڴ�����
		memset(character, 0, sizeof(character));
		//��int�͵�������sprintf�浽�ַ�����
		//sprintf�÷���sprintf(�ַ�����ַ����int���֡���int�ͱ���);
		sprintf(character, "%d\n", integer[j]);
		//���ַ����ŵ��ļ�2��
		fputs(character, p);
	}
	//�ر��ļ�2
	fclose(p);
	return 0;
}

