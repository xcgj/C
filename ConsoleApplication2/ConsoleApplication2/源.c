#include <stdio.h>

struct A
{
	int a;
	char b[4];
};

struct B
{
	int a;
	struct A c;
};

int main01()
{
	printf("sizeof struct B = %d\n", sizeof (struct B));
	struct B j[2] = { {100,{200,"abcd"}},{300,{400,"efgh"}} };
	int i = 0;
	for (i = 0; i < 2; i++)
		printf("j[%d].a = %d\nj[%d].c.a = %d\nj[%d].c.b = %s\n",
			i, j[i].a, i, j[i].c.a, i, j[i].c.b);
	return 0;
}