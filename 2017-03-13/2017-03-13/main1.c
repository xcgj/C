#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "a.h"
char a = 0;
char *p = "abcdef1";
static char b = 0;

int main(void) 
{
	test2();
	printf("%p %x %p %p\n", &a, p, &b, "abcdef1");
	return 0;
}