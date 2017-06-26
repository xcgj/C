/*4.  写1个函数 并且调用 输出运行结果。
	int getNumbers(int y1,int m1,int d1,int y2,int m2,int d2);
	函数功能: 获取出y1年m1月d1日到y2年m2月d2日之间有多少天？
	返回值:   返回两个日期之间所差的天数。*/

#include <stdio.h>
#pragma warning(disable:4996)
int leapyear(int);//计算闰年还是平年
int spendday(int, int, int);//计算当年过去多少天
int yearcrap(int, int);//计算中间差多少年(单位/天)
int getNumbers(int y1, int m1, int d1, int y2, int m2, int d2);

int main_4(void)
{
	int year1 = 0;
	int year2 = 0; 
	int month1 = 0;
	int month2 = 0;
	int day1 = 0;
	int day2 = 0;
	printf("请输入第一个年 月 日，请用空格隔开：");
	scanf("%d %d %d", &year1, &month1, &day1);
	printf("请输入第二个年 月 日，请用空格隔开：");
	scanf("%d %d %d", &year2, &month2, &day2);
	int days = getNumbers(year1, month1, day1, year2, month2, day2);
	printf("相差%d天\n", days);
	return 0;
}

int leapyear(int year)//判断闰年
{
	if ((year % 100 != 0 || year % 4 == 0) && year % 400 == 0)
		return 1;
	return 0;
}

int spendday(int year, int month, int day)
{
	switch (month)//月份自动下移
	{
	case 12:
		day += 30;//代表11月天数
	case 11:
		day += 31;
	case 10:
		day += 30;
	case 9:
		day += 31;
	case 8:
		day += 31;
	case 7:
		day += 30;//代表6月天数
	case 6:
		day += 31;
	case 5:
		day += 30;
	case 4:
		day += 31;
	case 3:
		day += 28 + leapyear(year);//代表2月天数
	case 2:
		day += 31;//代表1月天数
	}
	return day;
}

int yearcrap(int y1, int y2)
{
	int crap = 0;
	for (; y1 < y2 - 1; y1++)//1999~2000，相隔年数大于2才能加年数
		crap += (leapyear(y1 + 1)) ? 366 : 365;
	//总是判断下一年是不是闰年，因为当年已经计算过了
	return crap;
}

int getNumbers(int y1, int m1, int d1, int y2, int m2, int d2)
{
	int sum1 = 0;
	int sum2 = 0;
	if (y1 < y2)//y2年份比较大
	{
		if (leapyear(y1))//闰年
			sum1 = 366 - spendday(y1, m1, d1);
		else
			sum1 = 365 - spendday(y1, m1, d1);
		return sum2 = spendday(y2, m2, d2) + sum1 + yearcrap(y1, y2);
	}
	else if (y1 > y2)//y1年份比较大
	{
		if (leapyear(y2))//闰年
			sum2 = 366 - spendday(y2, m2, d2);
		else
			sum2 = 365 - spendday(y2, m2, d2);
		return sum1 = spendday(y1, m1, d1) + sum2 + yearcrap(y2, y1);
	}
	else//年份相同,比较哪个天数多
	{
		sum1 = spendday(y1, m1, d1) - spendday(y2, m2, d2);
		return (sum1 > 0) ? sum1 : -sum1;
	}
}

