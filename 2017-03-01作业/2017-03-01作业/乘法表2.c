//3����ӡ99�˷���Ч��2.png��99�˷���
#include <stdio.h>
int main03()
{
	int i = 0;
	int k = 0;
	int j = 0;
	//��ӡ��
	for (i = 1; i < 10; i++)
	{
		//��ӡ�Ʊ��
		for (j= 0; j <= i - 1; j++)
		{
			printf("\t");
		}
		//��ӡ��
		for (k = i; k < 10; k++)
		{
			printf("%d\t", i * k);
		}
		printf("\n");
	}
	return 0;
}