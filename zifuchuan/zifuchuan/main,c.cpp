#include <stdio.h>
int main()
{
	char arr[] = "������磡";//һ������ռ�����ֽ�
	int max, min = 0, temp;
	max = sizeof(arr)-2;	//������±�
	printf("%d\n", max);
	while (min + 1 < max - 1)
	{
		if (((min + 1) - (max - 1)) == 1 && (min + 1) / 2 == 1)
		//���ĸ�����ż�� �ַ����±꣺01 23 45 67
		//���ĸ��������� �ַ����±꣺01 23 45 67 89
			break;//�����м������ֽڲ�����
		else
		{
			temp = arr[min];
			arr[min] = arr[max - 1];
			arr[max - 1] = temp;
			temp = arr[min + 1];
			arr[min + 1] = arr[max];
			arr[max] = temp;
			min += 2;
			max -= 2;
		}
	}
	printf("%s\n", arr);	
	return 0;
}