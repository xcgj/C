//�жϳ���,

//ÿ�и�һ�ν���һ���ַ�������ֵ�������ά�ַ�����

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cut(char *s, char c, char(*p)[6], int *count)//����һ
{
	if (s == NULL || count == NULL)
		return -1;
	int len = strlen(s);
	char *p0 = s;
	char *p1 = NULL;
	char *p2 = NULL;
	int i = 0;
	//�иһ��ָ��ָ����ʼ�ˣ���һ��ָ���βһ��
	for (;p0 < s + len + 1; p0++)// + 1 �����ַ�\0
	{
		if (p1 == NULL)
			p1 = p0;
		p2 = p0;
		if(c == *p0 || *p0 == '\0')
		{
			if (p2 - p1 > 0)//�ж��и���Ƿ�����
			{//ÿ�и�һ�ν���һ���ַ�������ֵ�������ά�ַ�����
				strncpy(p[i], p1, p0 - p1);//�����ַ���
				p[i][p0 - p1] = '\0';//�ַ��������β��0
				p1 = p2 = NULL;
				i++;//���������±����
			}
			else
				p1 = p2 = NULL;
		}
	}
	*count = i;
	return 0;
}

int cut2(char *s, char c, char(*p)[6], int *count)//������
{
	if (s == NULL || count == NULL)
		return -1;
	char *p1 = s;
	char *p2 = s;
	int i = 0;
	while (*p2)
	{
		p2 = strchr(p2, c);//�����и��λ��
		if (p2 != NULL)
		{
			if (p2 - p1 > 0)//�ж��и���Ƿ�����
			{//ÿ�и�һ�ν���һ���ַ�������ֵ�������ά�ַ�����
				strncpy(p[i], p1, p2 - p1);
				p[i][p2 - p1] = '\0';
				i++;
			}
			p1 = p2 = p2 + 1;//�뿪�и��
		}
		else
		{
			strncpy(p[i], p1, sizeof p1);//ĩ���Ӵ�p1����
			p[i][sizeof p1] = '\0';
			i++;
			break;
		}
	}
	*count = i;
	return 0;
}

int main__2(void) 
{
	char s[100] = ",1234,,,5678,,9012,";
	char c = ',';
	char a[10][6];
	int ct = 0;
	int res = cut2(s, c, a, &ct);
	int i = 0;
	int j = 0;
	if (res != 0)
	{
		printf("func cut error: %d\n", res);
		return 0;
	}
	for (i = 0; i < 3; i++)
		printf("%s \n", a[i]);
	return 0;
}