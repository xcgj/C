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
	//Ϊʲôtest.a��д��*(test.a)?????????
	free(test.a);
	//�������������ָ�룬һ��Ҫ��ʹ����ָ�룬��free�����ʹ��������Ա
	test.b = 10;
	printf("%d\t%p\t%d\t%p\n", test.a, &test.a, test.b, &test.b);
	return 0;
}