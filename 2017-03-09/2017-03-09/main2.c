#include <stdio.h>

void insert(char *a/*in out*/)
{
	char *p1 = a;
	char *p2 = a;
	while (*p1 == ' ' || *p1 == '\t' || *p1 == '\n')
		p1++;

	while (*p2++ = *p1++);

	p2 -= 2;//*p2 == 0时，多加了一次
	while (*p2 == ' ' || *p2 == '\t' || *p2 == '\n')
		p2--;

	*++p2 = '\0';
}

int main02(void) 
{
	char buf[] = "						hello heima     \n";
	insert(buf);
	printf("%s", buf);
	return 0;
}