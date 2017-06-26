#include <stdio.h>

struct list
{
    int data;//数据域
    struct list *next;//指针域
};

int main(void)
{
    struct list *first = creat_list();//头结点
    struct list *second = calloc(1, sizeof(struct list));//在堆中创建链表
    struct list *third = calloc(1, sizeof(struct list));
    first->next = second;//
    second->next = third;
    third->next = NULL;
    first->data = 1;
    second->data = 2;
    third->data = 3;
    return 0;
}

struct list *creat_list()//建立一个结点
{
    return calloc(sizeof(struct list), 1);
}

void traverse(struct list *ls)//循环遍历链表
{
    struct list *p = ls;
    while (p)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}

struct list *insert_list(struct list *ls, int n, int data)//在n这个位置插入元素
{
    struct list *p = ls;
    while (p && n--)
    {
        p = p->next;
    }
    if (p->next == NULL)
        return NULL;
    struct list *node = creat_list();
    node->next = p->next;
    p->next = node;
    node->data = data;
    return node;
}

int delete_list(struct list *ls, int n)//删除指定n位置元素
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

int empty_list(struct list *ls)//返回链表是否为空
{
    if (ls->next)
        return 0;
    return -1;
}

struct list *locate_list(struct list *ls, int n)//返回链表指定位置的结点
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

struct list *elem_locale(struct list *ls, int data)//返回的数据域等于data的结点
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

int elem_pos(struct list *ls, int data)//返回数据域等于data的节点位置
{
    struct list *p = ls;
    int count;
    while (p)
    {
        count++;
        if (p->data == data)
            return count;
        p = p->next;
    }
    return -1;
}

struct list *last_list(struct list *ls)//得到链表最后一个节点
{
    struct list *p = ls;
    while (p->next)//最后一个节点指向NULL
    {
        p = p->next;
    }
    return p;
}

void merge_list(struct list *ls1, struct list *ls2)//合并两个链表，结果放入ls1中
{
    //不合并ls2的头节点
    //先找ls的尾节点
    last_list (ls1)->next = ls2->next;
    free(ls2);//ls2头节点不要了
}

void reverse(struct list *ls)//链表逆置
{//头节点不逆置，从第二个节点开始逆置
    if (ls == NULL || ls->next == NULL || ls->next->next == NULL)
        return 0;
    struct list *pf = ls->next;//初始化从第二个节点开始
    struct list *pm = pf->next->next;
    struct list *pl = NULL;
    while (pm)
    {
        pl = pm->next;
        pm->next = pf;
        pf = pm;
        pm = pl;
    }
    ls->next->next = NULL;	//第二节点指向NULL
    ls->next = pf;//头节点指向最后一个节点，当pl==NULL退出循环时，pm和pl都指向NULL
    return 0;
}
