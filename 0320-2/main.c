//统计文件中所有时间之和
//文件的每行均为一段时间形如01:20:30；请讲该文件中每一行的时间累加起来并且将最后的结果写到文件末尾
//示例文件 最终运算结果应该为02:20:12。文件行数未知。

//基本格式如下:
//01:00:30
//00:20:30
//00:59:12
//完善: 考虑可能异常的数据  不完善的数据 情况

//题解：
// 读一行加一行
// fgets，feof(p)， strtok()
// 每行各个分钟，秒数不会超过120，所以只需判断一次是否大于60，同理小时也判断一次大于24
// 当秒数大于60，分钟+1，同理分钟，小时

//异常：分秒大于等于60，小时大于等于24，不完善数据，直接跳过并报错。

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int Check1(char *pt)//判断每行分秒有没有超越过60
{
    int t = atoi(pt);
    if (t >= 60)
        return -1;
    return 0;
}

int Check2(char *pt)//判断每行小时有没有超越过60
{
    int t = atoi(pt);
    if (t >= 24)
        return -1;
    return 0;
}

int Adjust(int *phour, int *pminu, int *pseco, int *pday)
{
    if (*pseco >= 60)
    {
        *pseco -= 60;
        (*pminu)++;
    }
    if (*pminu >= 60)
    {
        *pminu -= 60;
        (*phour)++;
    }
    if (*phour >= 24)
    {
        *phour -= 24;
        (*pday)++;
    }
    return 0;
}

int main(void)
{
    FILE *p = fopen("E:/time.txt", "r");
    char buf[100] = { 0 };
    int hour = 0, minu = 0, seco = 0, day = 0, flag = 1;
    while (fgets(buf, sizeof(buf), p))
    {
        char temp[100] = { 0 };
        strcpy(temp, buf);

        char *h = strtok(temp, ":");
        char *m = strtok(NULL, ":");
        char *s = strtok(NULL, ":");
        if (h == NULL || m == NULL || s == NULL || Check2(h) || Check1(m) || Check1(s))
        {
            printf("error, line %d format invalid\n", flag++);
            continue;
        }
        hour += atoi(h);
        minu += atoi(m);
        seco += atoi(s);
        Adjust(&hour, &minu, &seco, &day);
        flag++;
    }
    fclose(p);
    printf("%d天%02d:%02d:%02d\n", day, hour, minu, seco);
    return 0;
}
