/*3.	��ʯ or ��ʯ��
	��ʯһ��20000����ʯһ��15000
	����ԭ�� int isEqual(int diamonds,int jade)
	�������� ��diamonds����������ʯ�ļ�ֵ��jade����ʯ�ļ۸���бȽ�
	��������ֵ �����ʯ��ֵ���򷵻�1  �����ȷ���0 �����ʯ��ֵС�򷵻�-1*/
#include <stdio.h>
#pragma warning(disable:4996)

int isEqual(int, int);

int main_hw3(void)
{
	int a = 0;
	printf("��������ʯ��������");
	scanf("%d", &a);
	int b = 0;
	printf("��������ʯ��������");
	scanf("%d", &b);
	int c = isEqual(a, b);
	if (1 == c)
		printf("��ʯ��ֵ��\n");
	else if (-1 == c)
		printf("��ʯ��ֵ��\n");
	else if (0 == c)
		printf("��ʯ��ʯ��ֵһ��\n");
	return 0;
}

int isEqual(int diamonds, int jade)
{
	if (diamonds * 20000 > jade * 15000)
		return 1;
	else if (diamonds * 20000 == jade * 15000)
		return 0;
	return -1;
}