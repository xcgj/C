#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	time_t tm = time(NULL);//�õ�ϵͳʱ��
	srand(tm);//��������ӷ�����
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		int j = rand();	//�����������
		printf("%d\n", j);
	}
	return 0;
}