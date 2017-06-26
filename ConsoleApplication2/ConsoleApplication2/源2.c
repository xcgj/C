#include <stdio.h>

struct A
{
	short a;
	char b;
};

struct B
{
	struct A c;
	char e;
};

int main()
{
	struct B z[2] = { {{ 2,3 }, 4}, { {6,7},9 } };
	printf("%p\n", &z);
	printf("sizeof struct B = %d\n", sizeof(struct B));
	printf("sizeof struct A = %d\n", sizeof(struct A));
	return 0;
}
