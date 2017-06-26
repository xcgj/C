#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

void decodes(char *);

int main03(void)
{
	int cp[1024];
	FILE *p1 = fopen("E:\\C_project\\code.txt", "r");
	FILE *p2 = fopen("E:\\C_project\\decode.txt", "w");
	while (!feof(p1))
	{
		memset(cp, 0, sizeof cp);
		fgets(cp, sizeof cp, p1);
		decodes(cp);
		fputs(cp, p2);
	}
	fclose(p1);
	fclose(p2);
	printf("404 found!\n");
	return 0;
}

void decodes(char *s)
{
	while (*s)
	{
		(*s) -= 10;
		s++;
	}
}