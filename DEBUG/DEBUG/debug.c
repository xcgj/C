#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
	int a = 5;
	int b = 3;
	/*int temp = a;   浪费空间
	a = b;
	b = temp;*/

	//1,3,5,6,3,1
	a = a^a;    //注意：同一个变量会出现0的情况？
	a = a^a;
	a = a^a;
	printf("%d\n", a);
	//a = a + b; //5+3=8  数据溢出
	//b = a - b; //8-3=5
	//a = a - b; //8-5=3  

	//a = a - b; //5-3=2
	//b = a + b; //2+3=5
	//a = b - a; //5-2=3
}