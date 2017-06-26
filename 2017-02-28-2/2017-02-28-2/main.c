#include <stdio.h>
#include <stdlib.h>
union A
{
	int *a;
	int b;
};

int main(void)
{
	union A test;
	test.a = malloc(4);
	printf("%d\t%p\t%d\t%p\n", test.a, &test.a, test.b, &test.b);
	//为什么test.a不写成*(test.a)?????????
	free(test.a);
	//如果联合体中有指针，一定要先使用完指针，再free后才能使用其他成员
	test.b = 10;
	printf("%d\t%p\t%d\t%p\n", test.a, &test.a, test.b, &test.b);
	return 0;
}