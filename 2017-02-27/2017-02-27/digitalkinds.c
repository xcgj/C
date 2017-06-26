#include <stdio.h>

struct B
{
	int c;
	char b[9];
};

struct A
{
	struct B d;
	char a;
};

int main01(void)
{
	struct A f = { {0x12345678, {2,2,2,2,2,2,2,2,2}}, 0x33 };
	f.d.c = 10;
	printf("%d\n", f.d.c);
	struct A *g;
	g = malloc(sizeof(struct A));
	//g->d.c = 5;
	//(*(&(g->d))).c = 5;
	(&(g->d))->c = 5;
	//以上三种等效
	(&(g->d))->b[1] = 1;
	//(g->d)得到的是地址上的值，因此变成指针取b的地址，最后给该地址赋值
	printf("%d\t%d\n", g->d.c, (*g).d.b[1]);
	free(g);
	return 0;
}
