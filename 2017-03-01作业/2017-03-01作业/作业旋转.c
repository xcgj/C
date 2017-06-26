//1、代码实现会玩不如会旋转的题目所示的效果。
//编写代码 效果- / | - \ -*****的转动效果
#include <stdio.h>
#include <Windows.h>
#define TIME 100
int main0()
{
	while (1)
	{
		printf("- ");
		Sleep(TIME);
		printf("\b\b");
		printf("/ ");
		Sleep(TIME);
		printf("\b\b");
		printf("| ");
		Sleep(TIME);
		printf("\b\b");
		printf("- ");
		Sleep(TIME);
		printf("\b\b");
		Sleep(TIME);
		printf("\b\b");
		printf("\\ ");
		Sleep(TIME);
		printf("\b\b");
	}
	return 0;
}