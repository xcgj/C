#include <stdio.h>

struct C
{
	char a;
	int b;
};

int main()
{
	struct C a;
	char *p = &a;
	*p = 0;
	p[1] = 1;//利用浪费的内存
	p[2] = 2;//利用浪费的内存
	p[3] = 3;//利用浪费的内存
	p[4] = 4;
	printf("%-2d%-2d%-2d%-2d%-2d\n", p[0], p[1], p[2], p[3], a.b);
	return 0;
}