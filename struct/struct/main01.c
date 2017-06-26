#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

struct student
{
	char name;
	int age;
};

int main01()
{
	//初始化方法1：
	struct student st1 = { 0 };
	//初始化方法2：
	struct student st2;
	memset(&st2, 0, sizeof(st2));//&
	//初始化方法3：
	struct student st3 = { .name = "aaa" };//没写的成员初始化为0，可以不按顺序写成员
	//初始化方法4：
	struct student st4;
	//strcpy(st4.name, "bbb");
	st4.age = 20;
	//初始化方法5：
	struct student st5;
	//scanf("name = %s", st5.name);
	scanf("age = %d", &st5.age);//&
	//初始化方法6：
	struct student st6 = { "ccc", 20 };//必须按照成员顺序写
	return 0;
}