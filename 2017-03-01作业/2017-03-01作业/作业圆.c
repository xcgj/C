#include <stdio.h>
#include <Windows.h>
#include <math.h>
int main0000()
{
	int x = 500;
	int y = 0;
	int state = 0;
	while (1)
	{
		if (x >= 0)
		{
			state = 1;
		}
		if (x <= 0)
		{
			state = 2;
		}
		SetWindowPos((HWND)0x001309D0, NULL, x, sqrt(800-x*x), 300, 300, 0);
		if (state == 1)
		{
			x -= 20;
		}
		if (state == 2)
		{
			x += 20;
		}
		
		Sleep(50);
	}
	return 0;
}