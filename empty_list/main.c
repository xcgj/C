#include <stdio.h>
#include <stdlib.h>

struct list
{
    int data;
    struct list *next;
};

struct list *creat_list()
{
    return calloc(1, sizeof(struct list));
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

int empty_list(struct list *ls)//链表是否为空
{
    if (ls->next)
        return 0;
    return -1;
}

int main(void)
{
    struct list *first = creat_list();
    struct list *second = creat_list();
    first->next = second;
    second->next = NULL;
    first->data = 1;
    second->data = 2;

    int i = empty_list (first);
    printf("%d\n\n", i);

    traverse (first);
    return 0;
}

