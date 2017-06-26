#include <stdio.h>
#pragma warning(disable:4996)
int main_1(void)
{
	int a[10] = { 1,2,3,4,5,6,7,8,9,0 };
	FILE *p = fopen("E:\\C_project\\file5.txt", "w");
	for (int i = 0; i < 10; i++)
		fprintf(p, "a[%d] = %d\n", i, a[i]);
	fclose(p);
	return 0;
}