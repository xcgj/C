#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void recur_char_stock(char *s, char *q)//���ò�������ջ���ص㣬��ϵݹ���ص�����ַ�������
{
	char *p = s;
	if (p == NULL)
		return;
	if (*p == '\0')
		return;//�ݹ���ֹ����
	recur_char_stock(p + 1, q - 1);
	printf("%c", *p);
	*q = *p;
	//q = q - 5;//Ϊɶд��ûд���һ��������
	//q�ĵ�ַÿ�ζ��Ǵ�˳�εݹ�ĺ���ʵ�λ�õģ�����εݹ�ĵ�ַû�й�ϵ
}

int main00000(void) 
{
	char *p = (char *)malloc(100 * sizeof(char));
	strcpy(p, "abcdefg");
	char q[100] = { 0 };
	recur_char_stock(p, q + 6);
	printf("\n%s\n", q);
	return 0;
}