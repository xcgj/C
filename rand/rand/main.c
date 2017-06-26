#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	time_t tm = time(NULL);//得到系统时间
	srand(tm);//随机数种子发生器
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		int j = rand();	//随机数产生器
		printf("%d\n", j);
	}
	return 0;
}