#include <stdio.h>

int main()
{
	int br[2][3] = { 
					{ 1, 2, 3 },
					{ 5, 6, 7 }
								};
	int **p;
	p = br;
	printf("%d\n", *(*(p+0)+2));
	return 0;
}