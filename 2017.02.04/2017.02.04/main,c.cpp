//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#pragma warning(disable:4996)
int main()
{
	int arr1[3] = { 1,2 };	//�����ʼ������һ
	int arr2[] = { 2,3,4 };	//�����ʼ��������
	int arr3[3];	//�����ʼ��������
	arr3[0] = 5;
	arr3[1] = 6;
	arr3[2] = 7;
	int arr4[3];	//�û������ʼ������
	int q,w;
	w = sizeof(arr4);
	for (q = 0; q < (w / 4); q++)	//����ı���
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