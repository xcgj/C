#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#pragma warning(disable:4996)
int main01()
{
	char a[100];
	scanf("%s", a);//scanf�Իس�����Ϊ������ʶ�����س������ᱻ���뵽�ַ�����
	//���scanf�����е����鳤��С���û��ڼ�������ĳ��ȣ���ôscanf�ͻỺ������������³������
	printf("%s\n", a);
	return 0;
}

int main02()
{
	char b[50] = { 0 };
	gets(b);//gets�������Կո�Ϊ������ʶ��������ո񣬵�Ҳ���ڻ������������
	int i;
	for (i = 0; i < 15; i++)
	{
		printf("b[%d]=%d, b[%d]=%c\n", i, b[i],i, b[i]);
	}
	return 0;
}

int main03()
{
	char a[50] = { 0 };
	char b[50] = { 0 };
	gets(a);
	gets(b);
	int a1 = atoi(a);//"atoi()"�����ַ���תΪһ������
	int b1 = atoi(b);
	printf("%d\n", a1 + b1);
	return 0;
}

int main04()
{
	char a[10];
	fgets(a, 9, stdin);
	printf("%s\n", a);
	puts(a);//ֻ������ַ����������������
	return 0;
}

int main05()
{
	char a[10] = "xcgj001";
	fputs(a, stdout);
	printf("%s\n", a);
	return 0;
}

