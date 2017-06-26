//2. 说一下这个代码有什么问题，为什么，怎么改正?
// 提示 当length输入为0的时候结果不是输出0，而是错误

#include <stdio.h>
#pragma warning(disable:4996)
int main__2(void)
{
	unsigned int length;//没有指明类型，加了int
	scanf("%d", &length);
	int i;
	int result = 0;
	if (0 == length)
		printf("error\n");
	else
	{
		int a[5];//定义数组,乱码
		for (i = 0; i <= length - 1; i++)//大写的英文字母O，改成了0
			result += a[i];
		printf("%d\n", result);
	}
	return 0;
}