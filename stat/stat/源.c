#include <stdio.h>
#pragma warning(disable:4996)
struct A
{
	int a;
	char b[100];
};

int main_out()
{
	//����ṹ��ձ���
	//���ļ�
	//fread�ļ����ṹ�����
	struct A xcgj;
	FILE *p = fopen("E:\\C_project\\file8.dat", "rb");
	fread(&xcgj, sizeof(xcgj), 1, p);
	fclose(p);
	printf("xcgj.a = %d\nxcgj.b = %s\n", xcgj.a, xcgj.b);
	return 0;
}


int main_in()//��fwrite���ṹ��д��������ļ�
{
	//����ṹ�����
	//�����ļ�
	//д���ļ�
	struct A xcgj = { 1, "c01" };
	FILE *p = fopen("E:\\C_project\\file8.dat", "wb");
	fwrite(&xcgj, sizeof(xcgj), 1, p);
	fclose(p);
	printf("Program complete\n");
	return 0;
}