//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#pragma warning(disable:4996)
int main()
{
	int arr1[3] = { 1,2 };	//数组初始化方法一
	int arr2[] = { 2,3,4 };	//数组初始化方法二
	int arr3[3];	//数组初始化方法三
	arr3[0] = 5;
	arr3[1] = 6;
	arr3[2] = 7;
	int arr4[3];	//用户输入初始化数组
	int q,w;
	w = sizeof(arr4);
	for (q = 0; q < (w / 4); q++)	//数组的遍历
	{
		printf("please input the value of arr4[%d]: ", q);
		scanf("%d", &arr4[q]);
	}
	w = sizeof(arr2);
	for (q = 0; q < (w / 4); q++)
	{
		printf("arr1[%d]=%d\n", q, arr1[q]);
		printf("arr2[%d]=%d\n", q, arr2[q]);
		printf("arr3[%d]=%d\n", q, arr3[q]);
		printf("arr4[%d]=%d\n", q, arr4[q]);
	}
		
	return 0;
}