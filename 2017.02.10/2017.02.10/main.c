#include <stdio.h>
void secondMax(int *s);

int main()//�������ֵ
{
	int ar[8] = { 1,9,5,4,8,6,10,3 };
	secondMax(ar);
	return 0;
}

void secondMax(int *s)
{
	int one = *s;
	int two = *s;
	int i = 0;
	for (; i < 8; i++)
	{
		if (one < *(s + i))
		{
			one = *(s + i);
		}
	}
	for (i = 0; i < 8; i++)
	{
		if (*(s + i) != one && two < *(s + i))
		{
			two = *(s + i);
		}
	}
	printf("%d\n", two);
}

void pointer(int *s)//ָ�������һ��Ԫ�صĵ�ַ
{
	int i = 0;
	int j = 0;
	for (j = 0; j < 10; j++)
	{
		for (i = 0; i < (9 - j); i++)
		//i�����ֵֻ����8��������������-j���������
		{
			int temp = 0;
			if (*(s + i) > *(s + i + 1))
			//��ַ�ȼ�i���ٱȽ�ֵ�Ĵ�С
			{
				temp = *(s + i);
				*(s + i) = *(s + i + 1);
				*(s + i + 1) = temp;
			}
		}
	}
}

void print(int *s)
{
	int i = 0;
	for(i = 0; i < 8; i++)
	{
		printf("%d\n", *(s + i));
		//s++;������Ҫ�ı��ʼָ������ĵ�ַ
	}
} 

void upsidedown(int *s)
{
	int max = 7;//����±�
	int min = 0;
	while (min < max)
	{
		int index = *(s + min);
		*(s + min) = *(s + max);
		*(s + max) = index;
		min++;
		max--;
	}
}

void upsidedown2(int *s)
{
	int *down = s;
	int *up = down + 7;
	int index = 0;
	while (down < up)
	{
		index = *down;
		*down = *up;
		*up = index;
		down++;
		up--;
	}
}

int lenth(int *s)//���ֲ������������鳤��
{
	int i = 0;
	while (*(s + i))
	{
		printf("i=%d,ar=%d\n", i, *(s + i));
		i++;
	}
	return i;
}

void Max(int *s)
{
	int m = *s;
	int i = 0;
	for (i = 0 ; i < 8; i++)
	{
		if (m < *(s + i))
			m = *(s + i);
	}
	printf("%d\n", m);
}

int main01()
{
	int arr[10] = { 1,2,6,4,7,3,8,5,0,9 };
	pointer(arr);
	print(arr);
	return 0;
}
