#include <stdio.h>

#define CALC(a) a * a + 1
#define LEN(h) sizeof(h) / sizeof(*h)

int main(void) 
{
	int b = 5;
	int c = CALC(b);
	printf("%d\n", c);

	char *g[] = { "abc", "efg", "sdf" };
	printf("%d\n", LEN(g));

	return 0;
}