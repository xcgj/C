#include <stdio.h>
int main()
{
	double a = 3 / 2;	//C���������������������Զ�ת��Ϊ�������ٸ�ֵ��a
	int b = 2;
	int c = 3;
	double d = (double)c / b;	//doubleǿ��ת����c������
	printf("%f\n%f\n", a, d);
	return 0;
}