#include <stdio.h>

struct A
{
	char a : 1;//����a��Աֻ��ʹ�� 1 bit
	int b : 2;//���ܳ��� sizeof(int)*8 �� bit �Ĵ�С
};

int main()
{
	printf("%d\n", sizeof(struct A));
	//�ֽڴ�С��λ�ֶ��޹أ���������������
	struct A a;
	a.a = 5;
	printf("%d\n", a.a);//�з��������Ҹ�λ����
	return 0;
}