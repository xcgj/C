/*	2���ô���ʵ�� �ϲ��������������arr1, arr2��arr3�в��ұ���Ԫ������
	int arr1[] = { 1,2,5,7,8 }; int arr2[] = { 2,3,4,6,9 };
	�ϲ���arr3���Ϊ{ 1,2,2,3,4,5,6,7,8,9 };
*/

#include <stdio.h>
int main() 
{
	char arr1[] = { 1,2,5,7,8 }; 
	char arr2[] = { 2,3,4,6,9,10,11,12 };
	char arr3[100] = { 0 };
	int i1 = sizeof(arr1);
	int i2 = sizeof(arr2);
	int i3 = i1 + i2;
	int j1 = 0;
	int j2 = 0;
	int j = 0;
	//1��2�������ѭ����ֹ
	while (j1 < i1 && j2 < i2)
	{
		//1��2�Ƚϣ�С�ĸ�3
		if (arr1[j1] < arr2[j2])
			arr3[j++] = arr1[j1++];
		else
			arr3[j++] = arr2[j2++];
	}
	//�ж��ĸ�û���꣬������ֵ��ֱ�����
	if (j1 == i1)
		for (;j < i3;)
			arr3[j++] = arr2[j2++];
	else
		for (; j < i3;)
			arr3[j++] = arr1[j1++];
	for (int k = 0; k < j; k++)
		printf("%-2d\n", arr3[k]);
	return 0;
}








int main__5_1(void)
{
	int arr1[] = { 1,2,5,7,8 }; 
	int arr2[] = { 2,3,4,6,9 };
	int arr3[100];
	int lenth_1 = sizeof arr1 / sizeof arr1[0];//����1����
	int lenth_2 = sizeof arr2 / sizeof arr2[0];//����2����
	int lenth_3 = lenth_1 + lenth_2;
	int p = (lenth_1 > lenth_2) ? lenth_1 - lenth_2 : lenth_2 - lenth_1; //����1���Ȳ�ֵ
	int i = 0;
	int j = 0;
	for (i = 0, j = 0; i < lenth_3 - p; j++)
	{
		arr3[i++] = (arr1[j] < arr2[j]) ? arr1[j] : arr2[j];
		arr3[i++] = (arr1[j] > arr2[j]) ? arr1[j] : arr2[j];
	}
	int k = 0;//������
	if (lenth_1 > lenth_2)//�������1�ж����Ԫ�أ���ֵ������3
		for (k = 0; j + k < lenth_1; k++)
			arr3[i + k] = arr1[j + k];
	if (lenth_1 < lenth_2)//�������2�ж����Ԫ�أ���ֵ������3
		for (k = 0; j + k < lenth_2; k++)
			arr3[i + k] = arr2[j + k];
	for (i = 0; i < lenth_3; i++)//����3����
		printf("arr3[%d] = %d\n", i, arr3[i]);
	return 0;
}
