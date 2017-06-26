#include <stdio.h>

static int ab = 100;

int *getab()
{
	return &ab;
}

void printab()
{
	printf("ab = %d\n", ab);
}