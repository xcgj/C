//0�����������ʼ��һ����ά���� ���Ҵ�ӡ�����ά����
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main__0(void)
{
	int array[3][5];
	int i = 0;
	int j = 0;
	int lines = sizeof array / sizeof array[0];//����
	int rows = sizeof array[0] / sizeof array[0][0];//����
	srand((unsigned int)time(NULL));
	//��ֵ
	for (i = 0; i < lines; i++)
		for (j = 0; j < rows; j++)
			array[i][j] = rand();
	//����
	for (i = 0; i < lines; i++)
	{
		for (j = 0; j < rows; j++)
			printf("array[%d][%d]=%d\t", i, j, array[i][j]);
		printf("\n");
	}
	return 0;
}
