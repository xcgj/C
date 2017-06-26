#include <stdio.h>
int main()
{
	double a = 3 / 2;	//C语言两个整数相除，结果自动转化为整数后，再赋值给a
	int b = 2;
	int c = 3;
	double d = (double)c / b;	//double强制转化了c的类型
	printf("%f\n%f\n", a, d);
	return 0;
}