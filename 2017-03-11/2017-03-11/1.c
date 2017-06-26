#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int cut(char *p, char *pbuf)
{
	//1 �жϿ�ָ��
	//2 ���帨��ָ��
	//3 �����ַ�������
	//4 ��ͷ��ʼ�ҷǿ��ַ��������±�
	//5 ��β��ʼ�ҷǿ��ַ��������±�
	//6 ���±���룬strncpy����
	//7 ĩβ��'\0'������ַ���
	int res = 0;
	if (p == NULL || pbuf == NULL)		//1
		return res = -1;
	char *a = p;						//2
	int index = strlen(a) - 1;			//3 ����±�
	int i = 0;
	while (isspace(a[i]) && a[i] != '\0')//4
		i++;							//ѭ���������ڵ�һ���ǿ��ַ�λ��
	while (isspace(a[index]) && a[index])//5
		index--;						//ѭ���������ڵ�����һ���ǿ��ַ�λ��
	strncpy(pbuf, a + i, index - i + 1);//6
	//*(pbuf + index - i + 1) = '\0';	//��������������
	return 0;
}

int main(void) 
{
	char *s = "      asdf   ";
	char sbuf[100] = { 0 };
	int res = cut(s, sbuf);
	if (res != 0)
	{
		printf("function cut error:%d\n", res);
		return 0;
	}
	printf("%s", sbuf);
	return 0;
}