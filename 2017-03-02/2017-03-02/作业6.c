//逆置汉字
#include <stdio.h>
int main__6(void)
{
	char character[] = "老司机";
	int min = 0;
	int lenth = 0;
	while (character[lenth++]);//得到元素个数
	printf("%d\n", lenth);
	int max = lenth - 2;//减1得到非零元素个数，再减1得到最大下标
	//(min|min+1)~(max-1|max)
	while (min + 1 < max - 1)//错位互换
	{
		char swap = character[min];
		character[min] = character[max - 1];
		character[max - 1] = swap;

		swap = character[max];
		character[max] = character[min + 1];
		character[min + 1] = swap;

		min += 2;
		max -= 2;
	}
	printf("%s\n", character);
	return 0;
}