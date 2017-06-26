#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

void inrow(int *s, int n)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (s[j] < s[j + 1])
			{
				int temp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = temp;
			}
		}
	}
}


void print(int *a, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
		printf("a[%d] = %d\n", i, a[i]);
}

int main00000()
{
	char a[100];
	int b[100] = {0};
	char *c = b;
	int i = 0;
	FILE *p = fopen("E:\\C_project\\file5.txt", "r");
	while(!feof(p))
	{
		memset(a, 0, 100);
		fgets(a, 100, p);
		//printf("%s", a);
		b[i] = atoi(a);
		i++;//得到元素的个数
	}
	inrow(b, i - 1);
	print(b, i - 1);
	fclose(p);
	return 0;
}

