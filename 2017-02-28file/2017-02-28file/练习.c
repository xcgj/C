#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
int main01(void)
{
	char a[100];
	FILE *p1 = fopen("E:\\C_project\\file3.txt", "r");
	FILE *p2 = fopen("E:\\C_project\\file5.txt", "w");
	char c = 0;
	while (c != EOF)
	{
		c = getc(p1);
		putc(c, p2);
	}
	printf("done\n");
	fclose(p1);
	fclose(p2);
	return 0;
}