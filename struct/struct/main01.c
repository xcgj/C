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
	//��ʼ������1��
	struct student st1 = { 0 };
	//��ʼ������2��
	struct student st2;
	memset(&st2, 0, sizeof(st2));//&
	//��ʼ������3��
	struct student st3 = { .name = "aaa" };//ûд�ĳ�Ա��ʼ��Ϊ0�����Բ���˳��д��Ա
	//��ʼ������4��
	struct student st4;
	//strcpy(st4.name, "bbb");
	st4.age = 20;
	//��ʼ������5��
	struct student st5;
	//scanf("name = %s", st5.name);
	scanf("age = %d", &st5.age);//&
	//��ʼ������6��
	struct student st6 = { "ccc", 20 };//���밴�ճ�Ա˳��д
	return 0;
}