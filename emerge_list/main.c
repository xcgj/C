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

void traverse (struct list *ls)
{
    struct list *p = ls;
    while (p)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}

struct list *insert_list (struct list *ls, int n, int data)
{
    struct list *p = ls;
    while (p && n--)
    {
        p = p->next;
    }
    if (p == NULL)
        return NULL;
    struct list *temp = creat_list ();
    temp->next = p->next;
    p->next = temp;
    temp->data = data;
    return temp;
}

struct list *last_list (struct list *ls)
{
    struct list *p = ls;
    while (p->next)
    {
        p = p->next;
    }
    return p;
}

void merge_list (struct list *ls1, struct list *ls2)
{
    //不合并ls2的头节点
    //先找ls的尾节点
    last_list (ls1)->next = ls2->next;
    free(ls2);//ls2头节点不要了
}

int main(void)
{
    struct list *first = creat_list ();
    struct list *second = creat_list ();
    first->next = second;
    second->next = NULL;
    first->data = 1;
    second->data = 2;

    struct list *another = creat_list ();
    int i = 0;
    for (; i < 10; i++)
    {
        insert_list (another, 0, i);
    }

    merge_list (first, another);

    traverse (first);
    return 0;
}


