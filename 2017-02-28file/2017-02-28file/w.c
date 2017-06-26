#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
int main02()
{
	char s[1024];
	FILE *p = fopen("E:\\C_project\\file.txt", "w");
	while (1)
	{
		memset(s, 0, sizeof(s));
		gets(s);
		if (strcmp(s, "exit") == 0)
			break;
		int a = strlen(s);
		s[a] = '\n';
		fputs(s, p);
	}
	fputs("End\n", p);
	fclose(p);
	return 0;
}