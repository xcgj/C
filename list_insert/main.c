#include <stdio.h>
#include <stdlib.h>

struct list
{
    int data;
    struct list *next;
};

struct list *creat_list()
{
    return calloc(sizeof(struct list), 1);
}

void traverse(struct list *ls)
{
    struct list *p = ls;
    while (p)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}

struct list *insert_list(struct list *ls, int n, int data)
{
    //定义同类型结构体p，指向ls
    //p位移一次，n--，直到找到指定的位置（n == 0）
    //如果n的范围超过原来结构体的数量了，p就会变成空指针
    //否则，新建结点node，
    //node->next（指针变量）得到旧的p->next（指针变量），
    //新的p->next（指针变量）指向node（地址）
    struct list *p = ls;
    while (p && n--)
    {
        p = p->next;
    }
    if (p->next == NULL)
        return NULL;
    else
    {
        struct list *node = creat_list();
        node->next = p->next;
        p->next = node;
        node->data = data;
        return node;
    }
}

int main(void)
{
    struct list *first = calloc(1, sizeof(struct list));
    struct list *second = creat_list();
    struct list *third = creat_list();
    first->next = second;
    second->next = third;
    third->next = NULL;
    first->data = 10;
    second->data = 20;
    third->data = 30;

    insert_list(first, 0, 50);//在头节点之后插入
    insert_list(first, 2, 100);//在下标为2的结点之后插入
    insert_list(first, 0, 200);//在头节点之后插入

    traverse(first);
    return 0;
}

