#include <stdio.h>
#pragma warning(disable:4996)

int main(void)
{
	FILE *p = fopen("E:\\C_project\\file11.txt", "r");
	char buffer[100] = { 0 };
	memset(buffer, 0, sizeof(buffer));
	fseek(p, 1, 0);
	fgets(buffer, sizeof(buffer) - 1, p);
	printf("%s", buffer);
	fseek(p, 0, 1);
	fgets(buffer, sizeof(buffer) - 1, p);
	printf("%s", buffer);
	printf("%d\n", ftell(p));
	fclose(p);
	return 0;
}



