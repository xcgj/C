#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
	int a = 5;
	int b = 3;
	/*int temp = a;   �˷ѿռ�
	a = b;
	b = temp;*/

	//1,3,5,6,3,1
	a = a^a;    //ע�⣺ͬһ�����������0�������
	a = a^a;
	a = a^a;
	printf("%d\n", a);
	//a = a + b; //5+3=8  �������
	//b = a - b; //8-3=5
	//a = a - b; //8-5=3  

	//a = a - b; //5-3=2
	//b = a + b; //2+3=5
	//a = b - a; //5-2=3
}