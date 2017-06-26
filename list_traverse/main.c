#include <stdio.h>

struct list
{
    int data;//数据域
    struct list *next;//指针域
};

void traverse(struct list *ls)//循环遍历链表
{
    struct list *p = ls;
    while (p)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}

int main(void)
{
    struct list *first = calloc(1, sizeof(struct list));;//头结点
    struct list *second = calloc(1, sizeof(struct list));//在堆中创建链表
    struct list *third = calloc(1, sizeof(struct list));
    first->next = second;//
    second->next = third;
    third->next = NULL;
    first->data = 1;
    second->data = 2;
    third->data = 3;
    traverse(first);
    return 0;
}
