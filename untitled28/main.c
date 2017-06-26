#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct info //����ṹ��
{
    char *name;
    char *addr;
    int age;
}info;

int print(info *d, int *m)  //��ӡ
{
    if (d == NULL)  //����ָ��
    {
        printf("error:-3, func print has NULL pointer\n");
        return -3;
    }
    int i = 0;
    for (; i < *m; i++)
        printf("%s\t%d\t%s\n", (d + i)->name, (d + i)->age, (d + i)->addr);
    return 0;
}

int freeall(info *d, int *m)    //�ͷ��ڴ�
{
    if (d == NULL)  //����ָ��
    {
        printf("error:-6, func print has NULL pointer\n");
        return -6;
    }
    int i = 0;
    for (; i < *m; i++)
    {
        free(d[i].name);
        free((d + i)->addr);
        (d + i)->name = d[i].addr = NULL;
    }
    free(d);
    return 0;
}

int getinfo(info *b)
{
    b = (info *)malloc(sizeof(info));
    if (b == NULL)  //����ָ��
    {
        printf("error, NULL pointer\n");
        return -1;
    }
    info *c = NULL;
    int count = 0;
    char cmd[20] = { 0 };
    int result = 0;

    while (1)
    {
        printf("���������");
        memset(cmd, 0, sizeof(char) * 20);  //���������
        scanf("%s", cmd);                   //�������
        if (strcmp(cmd, "exit") == 0)
            break;


        else if (strcmp(cmd, "print") == 0)
        {
            if (count == 0)					//��һ�ξʹ�ӡ����ʾ����
            {
                printf("error:-2, no information input\n");
                free(b);
                b = NULL;
                return -2;
            }
            result = print(b, &count);
        }


        else if (strcmp(cmd, "add") == 0)
        {
            c = (info *)realloc(b, sizeof(info) * (count + 1));//���ڴ�ռ�
            if (c == NULL)	//�ж��ڴ��Ƿ����
            {
                printf("error:-4, NULL pointer, memory allocate fail\n");
                free(b);
                b = NULL;
                return -4;
            }
            b = c;
            b[count].name = (char *)malloc(100 * sizeof(char));//�����ַ���ѿռ�
            b[count].addr = (char *)malloc(100 * sizeof(char));//����ַ����ѿռ�
            if (b[count].name == NULL || b[count].addr == NULL)//�ж��ڴ��Ƿ����
            {
                printf("error:-5, NULL pointer, MEMBERS allocate fail\n");
                freeall(b, &count);
                return -5;
            }
            printf("������3����Ϣ��");
            scanf("%s %d %s", b[count].name, &b[count].age, b[count].addr);
            count++;		//��¼�±�
        }


        else
        {
            printf("error:-7, invalid cmd\n");
            freeall(b, &count);
            return -7;
        }
    }
    printf("�����˳�\n");
    freeall(b, &count);
    return result;
}

int main(void)
{
    info *s = { 0 };
    int res = 0;
    res = getinfo(s);
    if (res == 0)
        printf("complete\n");
    else
        printf("program dumped\n");
    return 0;
}
