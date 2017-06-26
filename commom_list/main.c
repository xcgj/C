#include <stdio.h>

typedef struct list//定义只有指针域的链表
{
    struct list *next;
}listc;

typedef struct commom//定义结构体包含单个节点
{
    char name[12];
    int age;
    char addre[16];
    listc *ls;
}commom;

int main(void)//利用结构体偏移量，以链表为起点访问结构体成员
{
    //组成链表
    commom s0, s1, s2, s3;
    s0.ls->next = s1.ls;
    s1.ls->next = s2.ls;
    s2.ls->next = s3.ls;
    s3.ls->next = NULL;
    //以节点访问 s1 的成员的地址
    int relative_variable_offsize = (int)&(((commom*)0)->age);
    int origin_list_offsize = (int)&(s1.ls);
    int variable_offsize = origin_list_offsize - relative_variable_offsize;
    printf("%d\n", variable_offsize);
    *((int*)variable_offsize) = 10;
    printf("%d\n", s1.age);
    return 0;
}
