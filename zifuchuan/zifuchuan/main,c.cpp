#include <stdio.h>
int main()
{
	char arr[] = "你好世界！";//一个中文占两个字节
	int max, min = 0, temp;
	max = sizeof(arr)-2;	//求最大下标
	printf("%d\n", max);
	while (min + 1 < max - 1)
	{
		if (((min + 1) - (max - 1)) == 1 && (min + 1) / 2 == 1)
		//中文个数是偶数 字符串下标：01 23 45 67
		//中文个数是奇数 字符串下标：01 23 45 67 89
			break;//奇数中间两个字节不逆置
		else
		{
			temp = arr[min];
			arr[min] = arr[max - 1];
			arr[max - 1] = temp;
			temp = arr[min + 1];
			arr[min + 1] = arr[max];
			arr[max] = temp;
			min += 2;
			max -= 2;
		}
	}
	printf("%s\n", arr);	
	return 0;
}