#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count_line(char **p, int *line, char c)
{
    int result = 0;
    if (*p == NULL || p == NULL || line == NULL)
    {
        result = -1;
        printf("err:%d, func count_line gains NULL pointer!\n", result);
        return result;
    }

    char *p1 = *p;
    char *p2 = *p;
    while (*p2)
    {
        p2 = strchr(p2, c);
        if (p2 == NULL)//因为已经判断过p是否为空，所谓不必担心p2第一次就是空
        {
            if (strlen(p1) != 0)
                (*line)++;
            break;
        }
        else
        {
            if (p2 - p1 > 0)
                (*line)++;
            p1 = p2 = p2 + 1;
        }
    }
    return result;
}

int print(char ***s, int line)
{
    int result = 0;
    if (*s == NULL || s == NULL)
    {
        result = line;
        printf("err:%d, func print gains NULL pointer!\n", -result);
        return -result;
    }

    char ***buf = s;
    int j = 0;
    for (; j < line; j++)
    {
        printf("%s\n", (*buf)[j]);
    }
    return result;
}

int freeall(char ***s, int index)
{
    int result = 0;
    if (*s == NULL || s == NULL)
    {
        result = index;
        printf("err:%d, func freeall gains NULL pointer!\n", -result);
        return -result;
    }

    char ***buf = s;
    int i = 0;
    for (; i < index; i++)
    {
        free((*buf)[i]);
        (*buf)[i] = NULL;
    }
    free(*buf);
    *buf = NULL;
    return result;
}

int digout(char **p/*in*/, const int line/*in*/, const char c/*in*/, char ***getbuf)
{
    int index = 0;
    if (*p == NULL || p == NULL || getbuf == NULL)
    {
        index = -2;
        printf("err:%d, func digout gains NULL pointer!\n", index);
        exit(-1);//程序结束
    }

    char *p1 = *p;
    char *p2 = *p;
    char ***buf = getbuf;
    *buf = (char**)malloc(line * sizeof(char*)); //(line - 1)最大下标
    if (*buf == NULL)
    {
        index = -3;
        printf("err:%d, func digout allocates main-memory failed!\n", index);
        return 0;//0：清空一维
    }

    while (*p2)
    {
        p2 = strchr(p2, c);
        if (p2 != NULL)
        {
            if (p2 - p1 > 0)
            {
                *(*buf + index) = (char*)malloc((p2 - p1 + 1) * sizeof(char));//+1是为'\0'
                if (*(*buf + index) == NULL)
                {
                    printf("err:%d, func digout allocates dio-(%d)-memory failed!\n", -index, index);
                    return -index;
                }

                strncpy((*buf)[index], p1, p2 - p1);
                (*buf)[index][p2 - p1] = '\0';//组成字符串
                index++;//下标进一位
            }
            p1 = p2 = p2 + 1;
        }
        else
        {
            (*buf)[index] = (char*)malloc((strlen(p1) + 1) * sizeof(char));//+1是为'\0'
            if (*(*buf + index) == NULL)
            {
                printf("err:%d, func digout allocates dio-(%d)-memory failed!\n", -index, index);
                return -index;
            }

            strncpy((*buf)[index], p1, (strlen(p1)));//陷阱，这里不要 +1,
            (*buf)[index][strlen(p1)] = '\0';//组成字符串,不要 +1,否则溢出
            break;
        }
    }
    return index;
}

int main(void)
{
    char    *s = ",ad,fsdfd,,,sdsa,ddd,,,sd";
    char    **buffer = NULL;
    char    ch = ',';
    int     lines = 0;
    int     res_lines = 0;
    int     res_digou = 0;
    int     res_print = 0;
    int     res_freea = 0;

    res_lines = count_line(&s, &lines, ch);
    if (res_lines < 0)
        return res_lines;

    res_digou = digout(&s, lines, ch, &buffer);
    if (res_digou == 0)//一维分配失败
    {
        freeall(&buffer, 0);
        return -1;
    }
    if (res_digou < 0)//二维分配失败
    {
        freeall(&buffer, -res_digou);
        return res_digou;
    }//>0:程序正常运行

    res_print = print(&buffer, lines);
    if (res_print < 0)
    {
        freeall(&buffer, -res_print);
        return res_print;
    }

    res_freea = freeall(&buffer, lines);
    if (res_freea < 0)
        return res_freea;

    printf("-----------\nAPI compelete\n");
    return 0;
}
