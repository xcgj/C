#include <stdio.h>
int main()
{
	int a;
	int b;
	int c;
	//a = 1;
	//b = 2;
	//c = a + b;
	__asm
	{
		mov a, 1;
		mov b, 2;
		mov eax, a;
		add eax, b;
		mov c, eax;
	}
	printf("%d\n", c);
	return 0;
}