#include <stdio.h>

int main02()
{
	int br[] = { 0,1,2,3,4,5,6,7,8 };
	const int ar[] = { 0,1,2,3,4,5,6,7,8 };
	int *p = br;
	p = ar;
	*(p + 3) = 100;
	printf("%d\n", ar[3]);
	return 0;
}