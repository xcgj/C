#include <stdio.h>
int main()
{
	int arry1[2][2] = { {1,6},{3,5} };
	int arry2[3][2][2] = { 1,2,3 };
	int arry3[][4] = { 8,5,6,4,9,4 };
	int q, w, e;
	printf("aary1占用字节数=%d\n", sizeof(arry1));
	for (q = 0; q < 2; q++)
	{
		for (w = 0; w < 2; w++)
			printf("arry1[%d][%d]=%d\n", q, w, arry1[q][w]);
	}
	printf("aary2占用字节数=%d\n", sizeof(arry2));
	for (q = 0; q < 3; q++)
	{
		for (w = 0; w < 2; w++)
		{
			for (e = 0; e < 2; e++)
			{
				printf("arry2[%d][%d][%d]=%d\n", q, w, e, arry2[q][w][e]);
			}
		}
	}
	printf("aary3占用字节数=%d\n", sizeof(arry3));
	for (q = 0; q < 2; q++)
	{
		for (w = 0; w < 4; w++)
			printf("arry3[%d][%d]=%d\n", q, w, arry3[q][w]);
	}
	return 0;
}