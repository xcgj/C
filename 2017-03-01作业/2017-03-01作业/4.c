//4.	��д�����������������(0-255)��bitλ��ֵΪ1��λ��������65, 130��133
#include <stdio.h>
int main()
{
	int integer = 0;
	int count = 0;
	printf("������0-255�������������");
	scanf_s("%d", &integer);
	while (integer)
	{
		if(integer % 2)
			count++;
		integer /= 2;
	}
	printf("bitλ��ֵΪ1��λ��Ϊ��%d\n", count);
	return 0;
}