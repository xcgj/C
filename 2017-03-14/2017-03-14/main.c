#include <stdio.h>

struct student
{
	char name[20];
	unsigned char age;
	int sex;
};

void sort(struct student *a, int n)
{
	int i = 0;
	int j = 0;
	for (; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
			if (a[i].age > a[j].age)
			{
				struct student b = a[i];
				a[i] = a[j];
				a[j] = b;
			}
}

int main_1()
{
	struct student st[] = { { "刘德华", 30, 1 },{ "安倍晋三", 20, 0 },{ "苍老师", 50, 0 },{ "饭岛老师", 30, 0 },{ "陈冠希老师", 40, 1 } };
	int i, j;

	sort(st, 5);

	for (i = 0; i < sizeof(st) / sizeof(st[0]); i++)
	{
		if (st[i].sex == 1)
			printf("%s, %d, 男\n", st[i].name, st[i].age);
		else
			printf("%s, %d, 女\n", st[i].name, st[i].age);
	}
	return 0;
}
