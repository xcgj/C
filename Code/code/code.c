#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
#define XCGJ 8

void code(char *s, size_t n)
{
	size_t i;
	for (i = 0; i < n; i++)
		*(s + i) += XCGJ;
}

int main(void)
{
	//��ȡ�ļ�������д���ļ�
	FILE *p1 = fopen("E:\\zh2017.2.18.xlsx", "rb");//�����ƶ�д
	FILE *p2 = fopen("E:\\zh2017.2.18_d.xlsx", "wb");
	//���建���С
	char buffer[1024 * 4] = { 0 };
	//ѭ��
	while (!feof(p1))
	{
		//�建�壬��ʼ�����ļ���ע��д���Ĵ�СҪ��д��Ĵ�Сһ��
		memset(buffer, 0, sizeof buffer);
		int set = fread(buffer, sizeof(char), sizeof(buffer), p1);
		//����
		code(buffer, set);
		fwrite(buffer, sizeof(char), set, p2);
		//set:��Դ�ļ���ȡ�����ֽڣ�����Ŀ���ļ�д������ֽ�
	}
	//�ر��ļ�
	fclose(p1);
	fclose(p2);
	printf("Complete\n");
	return 0;
}