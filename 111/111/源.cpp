#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char a[100];
    char b[100];
}A;

int main()
{   
	A norm = { 0 }, max = { 0 }, smax = { 0 };
	FILE *p = fopen("E:\\sort.txt", "r");
	if (p == NULL)
		return -1;
	int i = 0;//�����±�
	for (; !feof(p); i++)
	{
		char buf[100] = { 0 }, buf2[100] = { 0 };
		fgets(buf, 100, p);//���һ���ַ���
		strcpy(buf2, buf);//��������
		strcpy(norm.b, strchr(strchr(buf2, '=') + 1, '=') + 1); //strchr��=�������ν�һλ���õ�����
		if (atoi(norm.b) > atoi(max.b))
		{//����������ȥ������
			strcpy(norm.a, strtok(strchr(buf, '=') + 1, ","));
			smax = max;
			max = norm;
		}else if (atoi(norm.b) > atoi(smax.b))
		{//����������ȥ������
			strcpy(norm.a, strtok(strchr(buf, '=') + 1, ","));
			smax = norm;
		}
		if (feof(p))//�����ļ�ĩ�У����ü���ѭ��
			break;
	}
	printf(" %s �������ǵڶ����� %d ��\n", smax.a, atoi(smax.b));
	fclose(p);
	return 0;
}