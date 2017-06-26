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
	struct student st[] = { { "���»�", 30, 1 },{ "��������", 20, 0 },{ "����ʦ", 50, 0 },{ "������ʦ", 30, 0 },{ "�¹�ϣ��ʦ", 40, 1 } };
	int i, j;

	sort(st, 5);

	for (i = 0; i < sizeof(st) / sizeof(st[0]); i++)
	{
		if (st[i].sex == 1)
			printf("%s, %d, ��\n", st[i].name, st[i].age);
		else
			printf("%s, %d, Ů\n", st[i].name, st[i].age);
	}
	return 0;
}
