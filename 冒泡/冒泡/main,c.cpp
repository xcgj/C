#include <stdio.h>
#pragma warning(disable:4996)
int main()
{
	int arry[5];
	int k, j, temp;
	for (k = 0; k < 5; k++)
	{
		printf("please input arry[%d]£º", k);
		scanf("%d", &arry[k]);
	}
	//for (k = 0; k < 5; k++)
	//{
	//	for (j = 1; j < (5 - k); j++)
	//	{
	//		if (arry[j - 1] > arry[j])
	//		{
	//			temp = arry[j - 1];
	//			arry[j - 1] = arry[j];
	//			arry[j] = temp;
	//		}
	//	}
	//}
	for (k = 0; k < 5; k++)
	{
		for (j = 0; j < 4 - k; j++)
		{
			if (arry[j] > arry[j + 1])
			{
				temp = arry[j];
				arry[j] = arry[j + 1];
				arry[j + 1] = temp;
			}
		}
	}
	for (k = 0; k < 5; k++)
	{
		printf("arry[%d]=%d\n", k, arry[k]);
	}
	return 0;
}