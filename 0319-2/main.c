//���һ����ʦ��Ϣ����ϵͳ��
//�ܹ�֧��
//	open file��ʾ������ļ��е����ݼ����ڴ���
//	add name age address  �ܹ������Ϣ
//	print��ӡ�����Ѿ����������
//	save file��ʾ���ڴ��е�����д�뵽ָ���ļ���
//����ָ�
//*	���Խ�ϵ�һ����Ŀ�����ݵı༭��ϵ��ڶ����С�

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct
{
    char name[100];
    int age;
    char addr[100];
}manage;

int AddInfo(manage **a, int mem)
{
    //aģʽ�����ļ�
    //��ȡ��Ϣ
    //д���ļ�
    manage *inf = (manage *)realloc(*a, mem * sizeof(manage));
    if (inf == NULL)
        return 0;
    *a = inf;
    printf("please input: ");
    scanf("%s %d %s", (*a)[mem - 1].name, &((*a)[mem - 1].age) ,(*a)[mem - 1].addr);
    //FILE *p = fopen("E:/manage.dat", "a");
    //fwrite(&inf, 1, sizeof(manage), p);
    printf("information added\n");
    return 0;
}
//int AddInfo(void)
//{
//    //aģʽ�����ļ�
//    //��ȡ��Ϣ
//    //д���ļ�
//    manage inf = { 0 };
//    printf("please input: ");
//    scanf("%s %d %s", inf.name, &inf.age ,inf.addr);
//    FILE *p = fopen("E:/manage.dat", "a");
//    fwrite(&inf, 1, sizeof(manage), p);
//    printf("information added\n");
//    return 0;
//}

int OpenFile(manage **a, FILE **p, int *mem)
{
    //�ȼ����ж��ٳ�Ա���ٷ����ڴ泤��
    //�����ݶ����ڴ�
    *p = fopen("E:/manage.dat", "rb");
    int num_temp = fseek(*p, 1, SEEK_SET);
    fseek(*p, 0, SEEK_END);
    int num = ftell(*p) / num_temp;//��Ա����
    *mem = num;
    fseek(*p, 0, SEEK_SET);

    *a = (manage*)calloc(num, sizeof(manage));
    if (a == NULL)
        return 0;

    fread(a, num, sizeof(manage), *p);//ȫ����Ա�����ڴ�
    //δ�ͷſռ䣬δ�ر��ļ�
    return 0;
}

int freeall(manage **a)
{
    if (a == NULL || *a == NULL)
        return 0;
    free(*a);
    *a = NULL;
    return 0;
}

int Print(manage *a, int mem)
{
    if (a == NULL)
        return 0;
    int i = 0;
    for (; i < mem; i++)
    {
        printf("%s\t%d\t%s\n", a[i].name, a[i].age, a[i].addr);
    }
    return 0;
}

int Save(manage *a, FILE **p, int mem)
{
    if (a == NULL || p == NULL || *p == NULL)
        return 0;
    fwrite(a, mem, sizeof(manage), *p);
    fclose(*p);//����ر��ļ�
    return 0;
}

int main(void)
{
    printf("please input cmd1: \n");
    char cmd1[10] = { 0 };
    scanf("%s", cmd1);
    int add_t = 0;//��¼���ӵĴ���
    int member = 0;//��¼���ٳ�Ա
    manage *a = NULL;
    FILE *p = NULL;
    if (strncmp(cmd1, "open", 4) == 0)
    {
        int flag = 0;
        OpenFile(&a, &p, &member);
        char cmd2[10] = { 0 };
        printf("file is opened, please input cmd2: \n");
        scanf("%s", cmd2);
        if (strncmp(cmd2, "add", 3) == 0)
        {
            add_t++;
            member += add_t;
            AddInfo(&a, member);
        }
        else if (strncmp(cmd2, "print", 5) == 0)
        {
            Print(a, member);
        }
        else if (strncmp(cmd2, "save", 4) == 0)
        {
            Save(a, &p, member);
            flag = 1;
        }
        else
        {
            printf("error, invalid cmd\n");
        }
        if (flag == 0)
        {
            Save(a, &p, member);
            printf("file is saved\n");
        }
        freeall(&a);
        printf("memory is freed\n");
    }
    return 0;

}

