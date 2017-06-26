#include <stdio.h>

void count(int [], int);

int main01()
{
	int ar[] = { 0,1,2,3,4,5,6,7,8 };
	count(ar, sizeof(ar) / sizeof(int));
	printf("size of ar = %zd Bytes\n", sizeof(ar));
	return 0;
}