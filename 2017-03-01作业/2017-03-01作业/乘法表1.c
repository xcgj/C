//2����ӡ99�˷���Ч��1.png��99�˷���
#include <stdio.h>
int main02()
{
	int i = 0;
	int j = 0;
	//��ӡ��
	for (i = 1; i < 10; i++)
	{
		//��ӡ��
		for (j = i; j < 10; j++)
		{
			printf("%-4d", i * j);
		}
		printf("\n");
	}
	return 0;
}