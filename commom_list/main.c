#include <stdio.h>

typedef struct list//����ֻ��ָ���������
{
    struct list *next;
}listc;

typedef struct commom//����ṹ����������ڵ�
{
    char name[12];
    int age;
    char addre[16];
    listc *ls;
}commom;

int main(void)//���ýṹ��ƫ������������Ϊ�����ʽṹ���Ա
{
    //�������
    commom s0, s1, s2, s3;
    s0.ls->next = s1.ls;
    s1.ls->next = s2.ls;
    s2.ls->next = s3.ls;
    s3.ls->next = NULL;
    //�Խڵ���� s1 �ĳ�Ա�ĵ�ַ
    int relative_variable_offsize = (int)&(((commom*)0)->age);
    int origin_list_offsize = (int)&(s1.ls);
    int variable_offsize = origin_list_offsize - relative_variable_offsize;
    printf("%d\n", variable_offsize);
    *((int*)variable_offsize) = 10;
    printf("%d\n", s1.age);
    return 0;
}
