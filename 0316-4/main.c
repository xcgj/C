#include <stdio.h>
#include <time.h>
int isleapyear(int year)
{
    return  (((year % 100 != 0) && (year % 4 == 0)) || (year % 400 == 0)) ? 1 : 0;
}

void getyear(int *year, unsigned int *sum)
{//计算是第几年---逐年减去一年的时间，直到秒数不够一年
    unsigned int tsum = *sum;
    unsigned int lysec = 365 * 24 * 60 * 60;
    unsigned int ysec = 366 * 24 * 60 * 60;
    int count = 1;
    while (tsum >= ysec)//遇到闰年和平年，减掉的秒数不一样
    {
        if (count % 4 == 0)//闰年
            tsum -= ysec;
        else        //平年
            tsum -= lysec;
        count++;
    }
    if (tsum >= lysec)//遇到闰年到平年最后一天的情况
    {
        tsum -= lysec;
        count++;
    }
    count--;//减掉1969年这一年
    *sum = tsum;
    *year += count;
}

void getmonth_day(int *month, int *day, unsigned int *sum, int year)
{//计算第几个月---逐月减去一个月的时间，直到秒数不够一个月
    unsigned int dsum = *sum ;
    int tday = 1 + dsum / (60 * 60 * 24);//没有第0天，都是第1天开始
    int count = 1;
    while (tday >= 31)
    {
        if (count == 2)//2月
            tday -= (28 + isleapyear(year));
        else if(count <= 7)
        {
            if (count % 2)//奇数
                tday -= 31;
            else
                tday -= 30;
        }
        else
        {
            if (count % 2)//奇数
                tday -= 30;
            else
                tday -= 31;
        }
        count++;
    }
    *month = count;
    *sum = dsum % (60 * 60 * 24);
    *day = tday;
}

void getshi(int *shi, unsigned int *sum)
{//计算小时---减去每个小时的时间，直到秒数不够一个小时
    int hou = 0;
    unsigned int tsum = *sum;
    while (tsum >= 3600)
    {
        tsum -= 3600;
        hou++;
    }
    *shi = hou;
    *sum = tsum;
}

void getfen(int *fen, unsigned int *sum)
{//计算分和秒---减去每分的时间，直到秒数不够1分钟，剩下是秒数
    int min = 0;
    unsigned int tsum = *sum;
    while (tsum >= 60)
    {
        tsum -= 60;
        min++;
    }
    *fen = min;
    *sum = tsum;
}

int main(void)
{
    unsigned int seconds = time(NULL);//1489655969;2017/3/16 17:19:29
    unsigned int sum = seconds + 365 * 24 * 60 * 60 + 8 * 3600;
    int year = 1969;//让时间从闰年1968年之后开始，方便平年闰年的循环计算
    int month, day, shi, fen;
    getyear(&year, &sum);
    getmonth_day(&month, &day, &sum, year);
    getshi(&shi, &sum);
    getfen(&fen, &sum);
    printf("现在的时间戳是：%d\n\n现在的北京时间：%d年%d月%d日%d时%d分%d秒\n",
           seconds, year, month, day, shi, fen, sum);
    return 0;
}

