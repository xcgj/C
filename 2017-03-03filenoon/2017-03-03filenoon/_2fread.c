#include <stdio.h>
#pragma warning(disable:4996)
int main_2(void)
{
	FILE *p = fopen("E:\\C_project\\file1.txt", "r");//��ʾ�Զ����Ʒ�ʽ��ȡ��������'\r'
	while (!feof(p))
	{
		char buffer[15] = { 0 };
		int a = fread(buffer, sizeof(char), 3, p);//ÿ�ζ�����
		for (int i = 0; i < a; i++)//������������
			printf("buffer[%d] = %x\n", i, buffer[i]);
	}
	return 0;
}