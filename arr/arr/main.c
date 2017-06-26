#include <stdio.h>
int main()
{
	int k, j, p;
	for (k = 3; k < 100; k++)
	{
		p = 0;
		for (j = 2; j < k; j++)
		{
			if ((k % j) == 0)
			{
				p = 1;
				break;
			}					
		}
		if (p == 0)
		{
			printf("%d\n", k);
		}
	}
	return 0;
}