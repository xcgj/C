#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
struct A
{
	char a[100];
	int b;
};

void print(struct A *s)
{
	printf("%s\t%d\n", (*s).a, s->b);
}

void swap(struct A *s, const char *a, const int b)
//char *a���յ����ַ�����������Ҫָ��ָ�����ĵ�ַ
{
	strcpy(s->a, a);
	//s��testָ��ͬһ��ַ������˵�����𣿣�������
	s->b = b;
	print(s);//s == &test
}

int main()
{
	struct A test = { "tom", 30 };
	print(&test);
	swap(&test, "mike", 20);
	print(&test);
	return 0;
}
