#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copy_(char *from, char *to)
{
	char *temp_from = from;//��Ҫ���׸ı��βε�ֵ
	char *temp_to = to;
	if (temp_from == NULL || temp_to == NULL)//������������û��ָ������ڴ�ռ�
	{
		printf("error, operand NULL\n");
		exit(-1);
	}
	else
	{
		while (*temp_to++ = *temp_from++);
		printf("%s\n", to);//ע�ⲻ��temp_to���Ѿ�λ��
	}
}
int main01(void) 
{
	char *source = "abcde";
	char *destiney = NULL;//�����ʼ��
	destiney = (char *)malloc(100 * sizeof(char));
	copy_(source, destiney);
	return 0;
}