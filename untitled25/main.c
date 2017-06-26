#include <stdio.h>

struct A
{
    char name[20];
    int height;
};

void getinfor(struct A *t, int *n)
{
    int i = 0;
    printf("请输入信息\n");
    for (; i < *n; i++)
    {
        scanf("%s", (t + i)->name);
        scanf("%d", &(t + i)->height);
    }
}

void print(struct A *p, int *n)
{
    int i = 0;
    for (; i < *n; i++)
    {
        printf("第%d个人的姓名：%s\t身高：%d\n", i + 1, (p + i)->name, (p + i)->height);
    }
}

int main(void)
{
    int n = 0;
    printf("请输入人数\n");
    scanf("%d", &n);
    struct A s[n];
    getinfor(s, &n);
    print(s, &n);
    printf("Hello World!\n");
    return 0;
}

