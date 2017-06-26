#include <stdio.h>
#include <string.h>
#include <time.h>
void print(int *a)
{
    for (int i = 0; i < 4; i++)
        printf("a_rand[%d] = %d\n", i, a[i]);
}

int isdiffer(int *a/*in*/)
{
    for (int i = 0; i < 4; i++)
        for (int j = i + 1; j < 4; j++)
        {
            if (a[i] == a[j])
                return 1;//��ͬ���ط�0��
        }
    return 0;
}

void randnum(int *num/*in*/)
{//���������,������գ�ÿ��ֵ��һ��
    srand((unsigned int)time(NULL));
    while (1)
    {
        for (int i = 0; i < 4; i++)
            num[i] = rand() % 10;
        if (!isdiffer(num))//4������ֹͬͣѭ��
            break;
    }
}

void stratoi(char *s/*in*/, int *a/*out*/)
{
    int n = atoi(s);
    for (int i = 3; i >= 0; i--)
    {
        a[i] = n % 10;
        n /= 10;
    }
}

int compare(int *a/*in*/, int *b/*in*/)
{//�ж�ֵ�Ƿ�һ�������λ����Ϣ
    int ca = 0;
    int cb = 0;
    int i = 0;
    for(i = 0; i < 4; i++)
    {
        if (a[i] == b[i])
            ca++;//����A������
        else
            for(int j = 0; j < 4; j++)
            {
                if (a[i] == b[j])
                    cb++;//����B��������
            }
    }
    if (ca == 0 && cb == 0)
    {
        printf("�������ҵĸ磬��ɹ��˱ܿ�������ȷ����\n\n�Ҳ�����");
        return 0;
    }
    if (ca == 4)
    {
        printf("���ϣ����������\n\n");
        return 1;//�¶���
    }
    for(i = 0; i < ca; i++)
        printf("A");
    for(i = 0; i < cb; i++)
        printf("B");
    printf("\n\n");
    return 0;
}

void getnum(int *num, int *unum/*in*/)
{//�����û����룬�������飬�ж�ÿ��ֵ��һ��
    char numbuf[5] = { 0 };
    int *punum = unum;
    int *pnum = num;
    while (1)
    {
        printf("����4����һ�������ָ��£�");
        scanf("%s", numbuf);
        stratoi(numbuf, punum);
        if (!isdiffer(punum))//˵���ĸ�����ͬ
        {
            if (compare(pnum, punum) == 0)//û�¶�
                continue;
            break;//�¶�
        }
        else
            printf("�ϸ磬�ȣ���ʽ����д����Ҫ��ʼ�������������\n\n�Ҳ�����");
    }
    printf("�𰸾���%s���ƿ�\n", numbuf);
}

int main(void)
{
    int a[4] = { 0 };
    int b[4] = { 0 };
    randnum(a);
    getnum(a, b);
    return 0;
}
