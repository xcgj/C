#include <stdio.h>
int main()
{
	int p, q, j;
	for (p = 1; p < 100; p++)
	{
		j = 1;
		for (q = 2; q < p; q++)	//1和2不会被执行循环，但能输出
		{
			if (p % q == 0)
			{
				j = 0;
				break;
			}
		}
		if (j == 1)
		{
			printf("%d\n", p);
		}
	}
	return 0;
}
























int main01()
{
	int q, w, e, r;
	for (q = 100; q < 1000; q++)
	{
		w = q % 10;	//个位
		e = q / 10 % 10;	//十位
		r = q / 100;	//百位
		if (q == (w*w*w + e*e*e + r*r*r))
		{
			printf("%d\n", q);
		}
	}
	return 0;
}