#include <stdio.h>

int bool(int *a)//判断终点
{
	int i = 0;
	int index = 0;
	for (i = 1; i < 10; i++)
	{
		if (a[i] != a[i + 1])
			return 1;//有糖果数量不相同就继续分糖
		else
			index++;//计算有几个小朋友糖果一样多
	}
	if (index == 9)
		return 0;
	else
		return 1;
}

int main()
{
	int arr[11] = { 0, 12, 2, 8, 22, 16, 4, 10, 6, 14, 20 };
	int count = 0;
	while (bool(arr))
	{
		count++;
		int i = 0;
		for (i = 1; i < 11; i++)
		{
			if (arr[i] % 2)//模是1就先给糖，这样商会+1
				arr[i]++;
			arr[i - 1] = arr[i] / 2 + arr[i - 1] / 2;//将计算结果赋值给前一位
		}
		arr[0] += arr[10] / 2;
		for (i = 10; i > 0; i--)//数组位置全部往后移一位
		{
			arr[i] = arr[i - 1];
			arr[0] = 0;
		}
	}
	printf("%d\n", count);
	printf("%d\n", arr[5]);
	return 0;
}