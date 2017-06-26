#include <stdio.h>
#pragma warning(disable:4996)
int main_3(void)
{
	FILE *p = fopen("E:\\C_project\\file4.txt", "wb");
	int a = 0x123456878;
	fwrite(&a, sizeof(char), 4, p);
	//fwrite(&a, 4, sizeof(char), p); µÈÐ§Ð´·¨
	fclose(p);
	return 0;
}