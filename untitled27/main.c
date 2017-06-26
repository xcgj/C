//课堂代码完善。
//从屏幕上输入一个数 n
//然后输入n个人基本信息(姓名 身高)
//     待输入完成之后  将所有的信息全部打印出
//     3
//     zhangsan 170
//     lisi 190
//     wanger 175

//     第1个人的姓名:zhangsan 身高:170
//     第2个人的姓名:lisi     身高:190
//     第1个人的姓名:wanger   身高:175
//要求:使用以下形式的结构体


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Info_t
{
    char *name;
    int  age;
};

int print(struct Info_t *b, int *n)
{
    if (b == NULL || n == NULL)
        return -1;
    int i = 0;
    for (; i < *n; i++)
        printf("第%d个人的姓名：%s\t身高：%d\n", i + 1, (b + i)->name, (b + i)->age);
    return 0;
}

int makeinfo(int *n)
{
    if (n == NULL)
        return -1;
    struct Info_t *a = (struct Info_t *)malloc(*n * sizeof(struct Info_t));
    if (a == NULL)
        return -1;
    int i = 0;
    for (; i < *n; i++)
    {
        (a + i)->name = (char *)malloc(20 * sizeof(char));
        if ((a + i)->name == NULL)
            return -1;
        scanf("%s %d", (a + i)->name, &(a + i)->age);
    }

    print(a, n);

    for (i = 0; i < *n; i++)
    {
        free((a + i)->name);
        (a + i)->name = NULL;
    }
    free(a);
    a = NULL;
    return 0;
}

int main(void)
{
    int a;
    printf("请输入人数：");
    scanf("%d", &a);
    int res = makeinfo(&a);
    if (res != 0)
    {
        printf("func makeinfo err:%d\n", res);
        return -1;
    }
    return 0;
}

