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

struct list *elem_locale(struct list *ls, int data)
{
    struct list *p = ls;
    while (p)
    {
        if (p->data == data)
            return p;
        p = p->next;
    }
    return NULL;
}

int main(void)
{
    struct list *first = creat_list();
    struct list *second = creat_list();
    first->next = second;
    second->next = NULL;
    first->data = 1;
    second->data = 2;

    printf("%d\n%p\n", elem_locale (first, 1)->data, elem_locale (first, 1)->next);

    traverse (first);
    return 0;
}

