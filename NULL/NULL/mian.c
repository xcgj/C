#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print(int *p)
{
	int i = 0;
	for (; i < 5; i++)
		printf("%d\n", *(p + i));
}

int main()
{
	int *p = malloc(sizeof(int) * 5);
	int i = 0;
	for (; i < 5; i++)
		printf("%d\n", *(p + i));
	//print(p);
	memset(p, 0, sizeof(int) * 5);
	print(p);
	system("pause");
	return 0;
}