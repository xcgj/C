/*4.  д1������ ���ҵ��� ������н����
	int getNumbers(int y1,int m1,int d1,int y2,int m2,int d2);
	��������: ��ȡ��y1��m1��d1�յ�y2��m2��d2��֮���ж����죿
	����ֵ:   ������������֮�������������*/

#include <stdio.h>
#pragma warning(disable:4996)
int leapyear(int);//�������껹��ƽ��
int spendday(int, int, int);//���㵱���ȥ������
int yearcrap(int, int);//�����м�������(��λ/��)
int getNumbers(int y1, int m1, int d1, int y2, int m2, int d2);

int main_4(void)
{
	int year1 = 0;
	int year2 = 0; 
	int month1 = 0;
	int month2 = 0;
	int day1 = 0;
	int day2 = 0;
	printf("�������һ���� �� �գ����ÿո������");
	scanf("%d %d %d", &year1, &month1, &day1);
	printf("������ڶ����� �� �գ����ÿո������");
	scanf("%d %d %d", &year2, &month2, &day2);
	int days = getNumbers(year1, month1, day1, year2, month2, day2);
	printf("���%d��\n", days);
	return 0;
}

int leapyear(int year)//�ж�����
{
	if ((year % 100 != 0 || year % 4 == 0) && year % 400 == 0)
		return 1;
	return 0;
}

int spendday(int year, int month, int day)
{
	switch (month)//�·��Զ�����
	{
	case 12:
		day += 30;//����11������
	case 11:
		day += 31;
	case 10:
		day += 30;
	case 9:
		day += 31;
	case 8:
		day += 31;
	case 7:
		day += 30;//����6������
	case 6:
		day += 31;
	case 5:
		day += 30;
	case 4:
		day += 31;
	case 3:
		day += 28 + leapyear(year);//����2������
	case 2:
		day += 31;//����1������
	}
	return day;
}

int yearcrap(int y1, int y2)
{
	int crap = 0;
	for (; y1 < y2 - 1; y1++)//1999~2000�������������2���ܼ�����
		crap += (leapyear(y1 + 1)) ? 366 : 365;
	//�����ж���һ���ǲ������꣬��Ϊ�����Ѿ��������
	return crap;
}

int getNumbers(int y1, int m1, int d1, int y2, int m2, int d2)
{
	int sum1 = 0;
	int sum2 = 0;
	if (y1 < y2)//y2��ݱȽϴ�
	{
		if (leapyear(y1))//����
			sum1 = 366 - spendday(y1, m1, d1);
		else
			sum1 = 365 - spendday(y1, m1, d1);
		return sum2 = spendday(y2, m2, d2) + sum1 + yearcrap(y1, y2);
	}
	else if (y1 > y2)//y1��ݱȽϴ�
	{
		if (leapyear(y2))//����
			sum2 = 366 - spendday(y2, m2, d2);
		else
			sum2 = 365 - spendday(y2, m2, d2);
		return sum1 = spendday(y1, m1, d1) + sum2 + yearcrap(y2, y1);
	}
	else//�����ͬ,�Ƚ��ĸ�������
	{
		sum1 = spendday(y1, m1, d1) - spendday(y2, m2, d2);
		return (sum1 > 0) ? sum1 : -sum1;
	}
}

