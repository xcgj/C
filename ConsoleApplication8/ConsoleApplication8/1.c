#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

struct student
{
	char name[10];
	int age;
};


int main()
{
	struct student stu;
	scanf("%s", stu.name);
	getchar();
	stu.age = getchar();
	printf("%d", stu.age);
	return 0;
}
