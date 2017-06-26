#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
int main04(void)
{
	char read[1024];
	char *p = fopen("E:\\C_project\\file.text", "r");
	fgets(read, sizeof(read), p);
	fclose(p);
	return 0;
}