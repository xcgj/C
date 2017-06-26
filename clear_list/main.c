#include <stdio.h>
#include <stdlib.h>

struct list//定义链表结构
{
    int data;
    struct list *next;
};

struct list *creat_list()//创建单个链表空间
{
    return calloc(1, sizeof(struct list));
}

void traverse(struct list *ls)//遍历链表
{
    struct list *p = ls;
    while (p)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}

void clear_list(struct list *ls)//清空链表，只保留首结点
{
    struct list *p = ls->next;//保留头结点
    while (p)
    {
        struct list *temp = p;
        temp = p->next;//先把p的下一个指针域保存起来
        free(p);
        p = temp;//再把指针域替换，下移
    }
    ls->next = NULL;
}

int main(void)
{
    struct list *first = creat_list();
    struct list *second = creat_list();
    struct list *third = creat_list();
    first->next = second;
    second->next = third;
    third->next = NULL;
    first->data = 123;
    second->data = 234;
    third->data = 456;
    traverse(first);

    clear_list(first);
    printf("------------\n");

    traverse(first);

    return 0;
}

