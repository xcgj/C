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
		//�ո��������ַ���ʽҪһֱ�������޷�����
		printf("a=%d,b=%d\n", a, b);
	}
	fclose(p);
	return 0;
}