//3、编写calloc的实现,通过调用malloc执行分配,调用memset将内存设置为00
//  你的代码应该没有任何由算术溢出引起的漏洞,且无论数据类size\_t用多少位表示,代码都应该正常工作。
//  库函数calloc有如下声明:
//  void *calloc(size_t rmemb, size_t Size) ;
//  根据库文档: “函数calloc为一个数组分配内存,该数组有rmemb个元素,每个元素为size字节。内存设置为00,
//  如果rmemb或size为0,则calloc返回NULL。
//  作为参考,函数malloc和memset声明如下:
//  void malloc(size_t Size) ;
//  void memset(void *s, int c, size_t n);

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void *mycalloc(size_t n, size_t m)
{
    if (!(n && m))
        return NULL;
    void *p = malloc(n * m);
    if (p == NULL)
        return NULL;
    memset(p, 0, n * m);
    return p;
}


int main(void)
{
    size_t rmemb = 1;
    size_t size = 1;
    int *p = (int *)mycalloc(rmemb, size);
    if (p == NULL)
        return -1;
    free(p);
    printf("Hello World!\n");
    return 0;
}
