#include <stdio.h>

struct A
{
	char a : 1;//定义a成员只能使用 1 bit
	int b : 2;//不能超过 sizeof(int)*8 个 bit 的大小
};

int main()
{
	printf("%d\n", sizeof(struct A));
	//字节大小与位字段无关，与变量的类型相关
	struct A a;
	a.a = 5;
	printf("%d\n", a.a);//有符号数，且高位舍弃
	return 0;
}