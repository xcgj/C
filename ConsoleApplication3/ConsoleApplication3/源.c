#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
int main01(void)
{
	char read[1024];
	FILE *p = fopen("E:\\C_project\\file.txt", "r");
	while (!feof(p))
	//foef(p):��������ļ���β����������ֵΪ��
	//����ֵΪ�٣��Զ��ƶ�����һ��
	{
		memset(read, 0, sizeof(read));
		fgets(read, sizeof(read), p);
		//ÿ��ֻ�����һ��
		//read:�ڴ��ַ��������Ŷ�ȡ�����ַ�
		//sizeofread:����ַ����ڴ��С
		//p:fopen���ص��ļ�ָ��
		printf("%s", read);
		//��Ϊ�Ѿ����ļ�����read�������ˣ�����Ҫ��read�ĵ�ַ���
	}
	fclose(p);
	return 0;
}