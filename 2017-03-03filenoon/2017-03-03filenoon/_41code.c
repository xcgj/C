#include <stdio.h>
#include <string.h>
void code(char *s, size_t n)
{
	size_t i;
	for (i = 0; i < n; i++)
		*(s+i) += 5;
}
