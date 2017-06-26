#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

//结构体类型的定义
struct stu
{
	char name[50];
	int age;
};

struct teach
{
	char n[100];
	int a;
};
t1;
t2;

int main()
{
	printf("t2.n = %s, t2.a = %d\n", t2.n, t1.a);
	//struct stu s1 = { "lily", 18 };

	////如果是指针变量，通过->操作结构体成员
	//struct stu *p = &s1;
	//printf("p->name = %s, p->age=%d\n", p->name, p->age);
	//printf("(*p).name = %s, (*p).age=%d\n", (*p).name, (*p).age);

	return 0;
}



//
//struct st
//{
//	char address[100];
//	int number;
//}; s2 = { 0 };
//
//int main()
//{
//	struct st *p = s2;
//	strcpy(p->address, "abc");
//	p->number = 10;
//	printf("%s, %d\n", p->address, p->number);
//	return 0;
//}








struct students
{
	char name[100];
	int age;
};

int main01(void)
{
	struct students s1;
	strcpy(s1.name, "jack");
	s1.age = 10;
	printf("s1.name = %s, s1.age = %d\n", s1.name, s1.age);
	return 0;
}

