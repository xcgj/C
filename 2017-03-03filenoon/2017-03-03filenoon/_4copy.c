#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

void decode(char *, size_t);

int main(void)
{
	//��ȡ��Ƶ�ļ�������д���ļ�
	FILE *p1 = fopen("E:\\zh2017.2.18_c", "rb");//�����ƶ�д
	FILE *p2 = fopen("E:\\zh2017.2.18_d", "wb");
	//���建���С
	char buffer[1024 * 4] = { 0 };
	//ѭ��
	while (!feof(p1))
	{
		//�建�壬��ʼ�����ļ���ע��д���Ĵ�СҪ��д��Ĵ�Сһ��
		memset(buffer, 0, sizeof buffer);
		int set = fread(buffer, sizeof(char), sizeof(buffer), p1);
		decode(buffer, set);
		fwrite(buffer, sizeof(char), set, p2);
		//set:��Դ�ļ���ȡ�����ֽڣ�����Ŀ���ļ�д������ֽ�
	}
	//�ر��ļ�
	fclose(p1);
	fclose(p2);
	printf("Complete\n");
	return 0;
}