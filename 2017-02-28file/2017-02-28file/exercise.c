#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
int main05(void)
{
	char a[100];
	FILE *p = fopen("E:\\C_project\\file5.txt", "w");
	FILE *p2 = fopen("E:\\C_project\\file3.txt", "r");
	while (1)
	{
		memset(a, 0, sizeof a);
		//scanf("%s", a);
		gets(a);
		if (strcmp(a, "exit") == 0)
			break;
		int len = strlen(a);
		a[len] = '\n';
		fputs(a, p);
	}
	fclose(p2);
	fclose(p);
	printf("end\n");
	return 0;
}