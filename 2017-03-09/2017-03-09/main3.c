#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main03(void) 
{
	char buf[10] = { 0 };
	char *p = buf;
	char *q = p;
	q++;

	printf("%lu\n", q-p);
	return 0;
}