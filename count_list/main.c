#include <stdio.h>
#include <stdlib.h>

struct list//定义链表结构
{
    int data;
    struct list *next;
};

struct list *creat_list()//创建单个链表空间
{
    return calloc(sizeof(struct list), 1);
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

int count_list(struct list *ls)//返回链表元素个数
{
    struct list *p = ls;
    int count = 0;
    while (p)
    {
        count++;
        p = p->next;
    }
    return count;
}

int main(void)
{
    struct list *first = creat_list();
    struct list *second = creat_list();
    struct list *third = creat_list();
    first->next = second;
    second->next = third;
    third->next = NULL;
    first->data = 10;
    second->data = 20;
    third->data = 30;

    printf("%d\n", count_list(first));
    traverse(first);
    return 0;
}

