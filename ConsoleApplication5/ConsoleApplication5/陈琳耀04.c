#include <stdio.h>
#include <string.h>

int main_04(void)
{
	//遍历字符串,将字符的ASCII码对应上计数数组的下标，出现一次就+1
	//遍历计数数组，将最大的那个元素的下标输出
	char string[] = "asddfffhjcvb";
	char ascii[200] = { 0 };
	int i = 0;
	while (string[i])
	{
		ascii[string[i]]++;
		i++;
	}
	int max = 0;
	char index = 0;
	for (i = 0; i < 200; i++)
	{
		if (max < ascii[i])
		{
			max = ascii[i];//最多字符的个数
			index = i;//最多字符的ASCII码
		}
	}
	printf("出现次数最多的字符为%c\n出现了%d次\n", index, max);
	return 0;
}
