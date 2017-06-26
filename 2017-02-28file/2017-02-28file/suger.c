#include <stdio.h>
int main03()
{
	int arr[11] = { 0, 12, 2, 8, 22, 16, 4, 10, 6, 14, 20 };
	int i = 0;
	int count = 0;
	printf("start\n");
	while (cmp(arr))
	{
		//判断是否循环，并计算次数
		count++;
		for (i = 1; i <= 10; i++)//每个人先分出一半
			arr[i] /= 2;
		arr[0] = arr[10];//第十个放在arr[0]
						 //将一半与前一个人相加
		for (i = 10; i >= 1; i--)
			arr[i] += arr[i - 1];
		//判断模，是1就加一
		for (i = 1; i <= 10; i++)
			arr[i] = (arr[i] % 2) ? ++arr[i] : arr[i];
		for (i = 0; i <= 10; i++)
			printf("a[%d]=%d\n", i, arr[i]);
	}
	printf("%d\n%d\n", count, arr[1]);
	printf("end\n");
	return 0;
}

int cmp(int *a)
{
	int i = 0;
	for (i = 1; i <= 10; i++)
		if (a[1] != a[i])
			return 1;
	return 0;
}
