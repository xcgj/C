#include <stdio.h>
#include <stdlib.h>

struct list//定义链表结构体
{
    int data;
    struct list *next;
};

struct list *creat_list()//创建一个链表
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

int delete_list(struct list *ls, int n)//删除链表的结点
{
    struct list *p = ls;
    while (n-- && p)
    {
        p = p->next;
    }
    if (p == NULL)//if (p->next == NULL)也行
        return -1;
    struct list *p1 = p;//01
    p1 = p1->next;//02 p1走到了要删除的位置
    p->next = p1->next;//03
    //p->next指向了要删除的值的后面，因为p1指向了后面
    free(p1);//04 将删除的节点释放
    //01~04的另一种写法（视频的）：
    /*struct list *temp = p->next;//为什么能直接指向next成员,而不指向p？？？？？
     *p->next = p->next->next;
     *free(temp)
     */
    return 0;
}

int main(void)
{
    struct list *first = creat_list();
    struct list *second = creat_list();
    struct list *third = creat_list();
    first->next = second;
    second->next = third;
    third->next = NULL;
    first->data = 1;
    second->data = 3;
    third->data = 5;
    traverse(first);
    printf("---------------\n");

    delete_list(first, 0);

    traverse(first);
    return 0;
}
