//#include <stdio.h>
//int main()
//{
//	int a, b;
//	a = getchar();
//	getchar();	// ‰»Îªÿ≥µ
//	b = getchar();
//	printf("a + b = %d\n", a + b);
//	printf("a + b = %d\n", (a - '0') + (b - '0'));
//	return 0;
//}
#include "stdio.h"
void main()
{
	int i = 1;
	int a;
	a = (i++)+(++i)+(i++)+(++i)+(i++);
	printf("%d\n", a);
}