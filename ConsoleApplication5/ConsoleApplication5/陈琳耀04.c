#include <stdio.h>
#include <string.h>

int main_04(void)
{
	//�����ַ���,���ַ���ASCII���Ӧ�ϼ���������±꣬����һ�ξ�+1
	//�����������飬�������Ǹ�Ԫ�ص��±����
	char string[] = "asddfffhjcvb";
	char ascii[200] = { 0 };
	int i = 0;
	while (string[i])
	{
		ascii[string[i]]++;
		i++;
	}
	int max = 0;
	char index = 0;
	for (i = 0; i < 200; i++)
	{
		if (max < ascii[i])
		{
			max = ascii[i];//����ַ��ĸ���
			index = i;//����ַ���ASCII��
		}
	}
	printf("���ִ��������ַ�Ϊ%c\n������%d��\n", index, max);
	return 0;
}
