/*	2、用代码实现 合并两个有序的数组arr1, arr2到arr3中并且保持元素有序。
	int arr1[] = { 1,2,5,7,8 }; int arr2[] = { 2,3,4,6,9 };
	合并后arr3结果为{ 1,2,2,3,4,5,6,7,8,9 };
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
	//1或2到达最大循环终止
	while (j1 < i1 && j2 < i2)
	{
		//1和2比较，小的给3
		if (arr1[j1] < arr2[j2])
			arr3[j++] = arr1[j1++];
		else
			arr3[j++] = arr2[j2++];
	}
	//判断哪个没走完，继续赋值，直到最大
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
	int lenth_1 = sizeof arr1 / sizeof arr1[0];//数组1长度
	int lenth_2 = sizeof arr2 / sizeof arr2[0];//数组2长度
	int lenth_3 = lenth_1 + lenth_2;
	int p = (lenth_1 > lenth_2) ? lenth_1 - lenth_2 : lenth_2 - lenth_1; //数组1长度差值
	int i = 0;
	int j = 0;
	for (i = 0, j = 0; i < lenth_3 - p; j++)
	{
		arr3[i++] = (arr1[j] < arr2[j]) ? arr1[j] : arr2[j];
		arr3[i++] = (arr1[j] > arr2[j]) ? arr1[j] : arr2[j];
	}
	int k = 0;//计数器
	if (lenth_1 > lenth_2)//如果数组1有多余的元素，赋值给数组3
		for (k = 0; j + k < lenth_1; k++)
			arr3[i + k] = arr1[j + k];
	if (lenth_1 < lenth_2)//如果数组2有多余的元素，赋值给数组3
		for (k = 0; j + k < lenth_2; k++)
			arr3[i + k] = arr2[j + k];
	for (i = 0; i < lenth_3; i++)//数组3遍历
		printf("arr3[%d] = %d\n", i, arr3[i]);
	return 0;
}
