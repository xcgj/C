//ͳ���ļ�������ʱ��֮��
//�ļ���ÿ�о�Ϊһ��ʱ������01:20:30���뽲���ļ���ÿһ�е�ʱ���ۼ��������ҽ����Ľ��д���ļ�ĩβ
//ʾ���ļ� ����������Ӧ��Ϊ02:20:12���ļ�����δ֪��

//������ʽ����:
//01:00:30
//00:20:30
//00:59:12
//����: ���ǿ����쳣������  �����Ƶ����� ���

//��⣺
// ��һ�м�һ��
// fgets��feof(p)�� strtok()
// ÿ�и������ӣ��������ᳬ��120������ֻ���ж�һ���Ƿ����60��ͬ��СʱҲ�ж�һ�δ���24
// ����������60������+1��ͬ����ӣ�Сʱ

//�쳣��������ڵ���60��Сʱ���ڵ���24�����������ݣ�ֱ������������

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int Check1(char *pt)//�ж�ÿ�з�����û�г�Խ��60
{
    int t = atoi(pt);
    if (t >= 60)
        return -1;
    return 0;
}

int Check2(char *pt)//�ж�ÿ��Сʱ��û�г�Խ��60
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
    printf("%d��%02d:%02d:%02d\n", day, hour, minu, seco);
    return 0;
}
