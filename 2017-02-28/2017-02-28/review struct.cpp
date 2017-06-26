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
//char *a接收的是字符串常量，需要指针指向它的地址
{
	strcpy(s->a, a);
	//s和test指向同一地址，这种说法对吗？？？？？
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
