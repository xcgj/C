#include <stdio.h>
#pragma warning(disable:4996)
int main_22(void)
{
	FILE *p = fopen("E:\\C_project\\file1.txt", "rb");
	char buffer[15] = { 0 };
	size_t a = fread(buffer, sizeof(char), 100, p);
	printf("%u\n", a);
	a = fread(buffer, sizeof(int), 100, p);
	printf("%u\n", a);
	fclose(p);
	return 0;
}