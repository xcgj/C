//1������ʵ�ֻ��治�����ת����Ŀ��ʾ��Ч����
//��д���� Ч��- / | - \ -*****��ת��Ч��
#include <stdio.h>
#include <Windows.h>
#define TIME 100
int main0()
{
	while (1)
	{
		printf("- ");
		Sleep(TIME);
		printf("\b\b");
		printf("/ ");
		Sleep(TIME);
		printf("\b\b");
		printf("| ");
		Sleep(TIME);
		printf("\b\b");
		printf("- ");
		Sleep(TIME);
		printf("\b\b");
		Sleep(TIME);
		printf("\b\b");
		printf("\\ ");
		Sleep(TIME);
		printf("\b\b");
	}
	return 0;
}