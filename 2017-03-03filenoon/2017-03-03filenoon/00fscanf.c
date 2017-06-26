#include <stdio.h>
#pragma warning(disable:4996)
int main00(void)
{
	char s[100] = { 0 };
	FILE *p = fopen("E:\\C_project\\file5.txt", "r");
	while (!feof(p))
	{
		int a = 0;
		int b = 0;
		memset(s, 0, sizeof s);
		fscanf(p, "%d + %d =", &a, &b);
		//空格数量，字符格式要一直，否则无法解析
		printf("a=%d,b=%d\n", a, b);
	}
	fclose(p);
	return 0;
}