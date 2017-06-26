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
                return 1;//相同返回非0；
        }
    return 0;
}

void randnum(int *num/*in*/)
{//产生随机数,数组接收，每个值不一样
    srand((unsigned int)time(NULL));
    while (1)
    {
        for (int i = 0; i < 4; i++)
            num[i] = rand() % 10;
        if (!isdiffer(num))//4个数不同停止循环
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
{//判断值是否一样，输出位置信息
    int ca = 0;
    int cb = 0;
    int i = 0;
    for(i = 0; i < 4; i++)
    {
        if (a[i] == b[i])
            ca++;//计算A的数量
        else
            for(int j = 0; j < 4; j++)
            {
                if (a[i] == b[j])
                    cb++;//计算B的数量；
            }
    }
    if (ca == 0 && cb == 0)
    {
        printf("厉害了我的哥，你成功了避开所有正确数字\n\n敢不敢再");
        return 0;
    }
    if (ca == 4)
    {
        printf("哎呦，不错，这个屌\n\n");
        return 1;//猜对了
    }
    for(i = 0; i < ca; i++)
        printf("A");
    for(i = 0; i < cb; i++)
        printf("B");
    printf("\n\n");
    return 0;
}

void getnum(int *num, int *unum/*in*/)
{//接收用户输入，放入数组，判断每个值不一样
    char numbuf[5] = { 0 };
    int *punum = unum;
    int *pnum = num;
    while (1)
    {
        printf("输入4个不一样的数字搞事：");
        scanf("%s", numbuf);
        stratoi(numbuf, punum);
        if (!isdiffer(punum))//说明四个数不同
        {
            if (compare(pnum, punum) == 0)//没猜对
                continue;
            break;//猜对
        }
        else
            printf("老哥，稳，格式都能写错，我要开始怀疑你的智商了\n\n敢不敢再");
    }
    printf("答案就是%s，科科\n", numbuf);
}

int main(void)
{
    int a[4] = { 0 };
    int b[4] = { 0 };
    randnum(a);
    getnum(a, b);
    return 0;
}
