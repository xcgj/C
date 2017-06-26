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

struct list *locale_list(struct list *ls, int n)//返回链表指定n位置的结点
{
    struct list *p = ls;
    while (p && n--)
    {
        p = p->next;
    }
    if (p == NULL)
        return NULL;
    return p;
}

int main(void)
{
    struct list *first = creat_list();
    struct list *second = creat_list();
    first->next = second;
    second->next = NULL;
    first->data = 1;
    second->data = 2;

    //struct list *recept = creat_list();
    //recept = locale_list(first, 1);
    //printf ("%d\n", recept->data);
    printf ("%d\n", locale_list(first, 1)->data);//一句顶仨

    traverse (first);
    return 0;
}
