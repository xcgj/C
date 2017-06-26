#include <stdio.h>
#include <Windows.h>
int main09()//æÿ–Œ‘À∂Ø
{
	int x = 0;
	int y = 0;
	int state = 0;
	while (1)
	{
		if (x <= 0 && y <= 0)
		{
			state = 1;
		}
		if (x >= 1070 && y <= 0)
		{
			state = 2;
		}
		if (x >=1070 && y >= 440)
		{
			state = 3;
		}
		if (x <= 0 && y >= 440)
		{
			state = 4;
		}
		SetWindowPos((HWND)0x00070BC2, NULL, x, y ,300, 300, 0);
		if (state == 1)
		{
			x += 10;
		}
		if (state == 2)
		{
			y += 10;
		}
		if (state == 3)
		{
			x -= 10;
		}
		if (state == 4)
		{
			y -= 10;
		}
		Sleep(50);
	}
	return 0;
}