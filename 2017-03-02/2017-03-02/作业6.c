//���ú���
#include <stdio.h>
int main__6(void)
{
	char character[] = "��˾��";
	int min = 0;
	int lenth = 0;
	while (character[lenth++]);//�õ�Ԫ�ظ���
	printf("%d\n", lenth);
	int max = lenth - 2;//��1�õ�����Ԫ�ظ������ټ�1�õ�����±�
	//(min|min+1)~(max-1|max)
	while (min + 1 < max - 1)//��λ����
	{
		char swap = character[min];
		character[min] = character[max - 1];
		character[max - 1] = swap;

		swap = character[max];
		character[max] = character[min + 1];
		character[min + 1] = swap;

		min += 2;
		max -= 2;
	}
	printf("%s\n", character);
	return 0;
}