//���ô������ơ�
//����Ļ������һ���� n
//Ȼ������n���˻�����Ϣ(���� ���)
//     ���������֮��  �����е���Ϣȫ����ӡ��
//     3
//     zhangsan 170
//     lisi 190
//     wanger 175

//     ��1���˵�����:zhangsan ���:170
//     ��2���˵�����:lisi     ���:190
//     ��1���˵�����:wanger   ���:175
//Ҫ��:ʹ��������ʽ�Ľṹ��


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
        printf("��%d���˵�������%s\t��ߣ�%d\n", i + 1, (b + i)->name, (b + i)->age);
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
    printf("������������");
    scanf("%d", &a);
    int res = makeinfo(&a);
    if (res != 0)
    {
        printf("func makeinfo err:%d\n", res);
        return -1;
    }
    return 0;
}

