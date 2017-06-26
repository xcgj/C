#include <stdio.h>
int main()
{
	int a = 10;
	int *p;
	p = &a;
	//*p的意思是指针变量指向a存放在内存里的内容
	int b = *p;
	//指针变量将该内存地址里存放的内容赋值给b使用，但b用的是一个新地址
	*p = 20;//通过指针间接地修改指针指向变量的值（把a内存地址里存放的内容修改了）
	int c = *p;
	printf("%d %d %d %d %u %u\n", a, b, *p, c, &a, &b);
	char arr1[10] = { 0 };
	int arr2[10] = { 0 };
	printf("%u %u %u %u\n", arr1, &arr1[0], &arr1[1], &arr1[2]);
	printf("%u %u %u %u\n", arr2, &arr2[0], &arr2[1], &arr2[2]);
	//数组名是数组第一个元素的地址
	return 0;
}