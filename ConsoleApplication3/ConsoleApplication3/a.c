#include <stdio.h>
#pragma warning(disable:4996)
int main(void)
{
	FILE *p1 = fopen("E:\\C_project\\file2.txt", "r");
	FILE *p2 = fopen("E:\\C_project\\file3.txt", "w");
	char c = 0;
	while ((c = getc(p1)) != EOF)
	{
		putc(c, p2);
	}
	return 0;
}