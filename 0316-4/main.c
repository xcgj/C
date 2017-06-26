#include <stdio.h>
#include <time.h>
int isleapyear(int year)
{
    return  (((year % 100 != 0) && (year % 4 == 0)) || (year % 400 == 0)) ? 1 : 0;
}

void getyear(int *year, unsigned int *sum)
{//�����ǵڼ���---�����ȥһ���ʱ�䣬ֱ����������һ��
    unsigned int tsum = *sum;
    unsigned int lysec = 365 * 24 * 60 * 60;
    unsigned int ysec = 366 * 24 * 60 * 60;
    int count = 1;
    while (tsum >= ysec)//���������ƽ�꣬������������һ��
    {
        if (count % 4 == 0)//����
            tsum -= ysec;
        else        //ƽ��
            tsum -= lysec;
        count++;
    }
    if (tsum >= lysec)//�������굽ƽ�����һ������
    {
        tsum -= lysec;
        count++;
    }
    count--;//����1969����һ��
    *sum = tsum;
    *year += count;
}

void getmonth_day(int *month, int *day, unsigned int *sum, int year)
{//����ڼ�����---���¼�ȥһ���µ�ʱ�䣬ֱ����������һ����
    unsigned int dsum = *sum ;
    int tday = 1 + dsum / (60 * 60 * 24);//û�е�0�죬���ǵ�1�쿪ʼ
    int count = 1;
    while (tday >= 31)
    {
        if (count == 2)//2��
            tday -= (28 + isleapyear(year));
        else if(count <= 7)
        {
            if (count % 2)//����
                tday -= 31;
            else
                tday -= 30;
        }
        else
        {
            if (count % 2)//����
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
{//����Сʱ---��ȥÿ��Сʱ��ʱ�䣬ֱ����������һ��Сʱ
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
{//����ֺ���---��ȥÿ�ֵ�ʱ�䣬ֱ����������1���ӣ�ʣ��������
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
    int year = 1969;//��ʱ�������1968��֮��ʼ������ƽ�������ѭ������
    int month, day, shi, fen;
    getyear(&year, &sum);
    getmonth_day(&month, &day, &sum, year);
    getshi(&shi, &sum);
    getfen(&fen, &sum);
    printf("���ڵ�ʱ����ǣ�%d\n\n���ڵı���ʱ�䣺%d��%d��%d��%dʱ%d��%d��\n",
           seconds, year, month, day, shi, fen, sum);
    return 0;
}

