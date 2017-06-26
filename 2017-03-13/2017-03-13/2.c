#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static a = 100;

int test2(void)
{
	a += 100;
	printf("%d\n", a);
	return 0;
}