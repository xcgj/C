// 定义结构体struct
// 遍历文件获得长度n, feof()+fgets()
// 申请结构体数组内存，存放文本文件中的所有数据，数组长度=n/2
// key成员：每次循环strlen()-1分配内存， strtok()  strcpy()+指针后移一位  strchr()+strcpy()
// content成员：每次循环strlen()-1分配内存，strchr()+strcpy()  strstr()+strcpy()
// 获得输入的字符串，去内存匹配strncmp()结构体的key成员，匹配成功输出content成员，失败提示没有找到


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct dic
{
    char *key;
    char **content;
    unsigned int count;
}dic1;


int getStr(char **a)
{
    char *p = *a;
    char *q = *a + strlen(*a) - 1;
    while (isspace(*p++));

    while (isspace(*q))
    {
        if (p > q)
        {
            **a = '0';
            return 0;
        }
        q--;
    }
    p--;
    p[q - p + 1] = '\0';
    *a = p;
    return 0;
}


int getLen(const char *pf, int *len)
{
    int res = 0;
    if (pf == NULL || len == NULL)
    {
        res = -6;
        printf("err:%d, getLen NULL pointer\n", res);
        return res;
    }
    FILE *p = fopen(pf, "r");
    if (p == NULL)
    {
        res = -5;
        printf("err:%d, FILE pointer open failed\n", res);
        return res;
    }
    int n = 0;
    char buf[1024] = { 0 };
    for (; fgets(buf, 1024, p); n++);
    *len = n;
    fclose(p);
    return res;
}


int StoreMemory(dic1 *s, int len, const char *pf)
{
    int res = 0;
    if (pf == NULL || s == NULL)
    {
        res = -8;
        printf("err:%d, StoreMemory NULL pointer\n", res);
        return res;
    }
    FILE *p = fopen(pf, "r");
    if (p == NULL)
    {
        res = -7;
        printf("err:%d, FILE pointer open failed\n", res);
        return res;
    }
    char buf[1024] = { 0 };
    int index = 0;//结构体数组下标
    for (index = 0; index < len; index++)
    {
        memset(buf, 0, 1024);
        fgets(buf, 1024, p);
        int length = strlen(buf);//每行字符串长度
        s[index].key = (char*)calloc(length - 1/*不包含#字符*/, sizeof(char));
        strncpy(s[index].key, buf + 1, length - 2/*去掉\n*/);

        memset(buf, 0, 1024);
        fgets(buf, 1024, p);
        length = strlen(buf);//每行字符串长度
        char *buf1 = (char*)calloc(length, sizeof(char));
        char *buf2 = (char*)calloc(length, sizeof(char));
        strncpy(buf1, buf + 6/*不包含Trans:字符串*/, length/*去掉\n*/);
        strncpy(buf2, buf + 6/*不包含Trans:字符串*/, length/*去掉\n*/);

        //先算长度
        //再给每个指针分配长度
        /*strchr(buf1, '@');
        buf1++;*/
        s[index].count = 1;
        while (buf1=strchr(buf1, '@'))
        {
            buf1++;
            s[index].count++;
        }
        // buf1 -= length - 7;指针回退
        s[index].content = (char**)calloc(s[index].count, sizeof(char*));

        unsigned int i = 0;
        char *p = NULL;
        for (i = 0; i < s[index].count; i++)
        {
            p = buf2;
            buf2 = strchr(buf2, '@');
            int j;
            if (buf2)
                j = buf2 - p;
            else
                j = strlen(p);
            (s[index].content)[i] = (char*)calloc(j, sizeof(char));
            strncpy((s[index].content)[i], p, j);
            (s[index].content)[i][j] = '\0';
            buf2++;
        }
    }
    fclose(p);
    printf("单词加载成功\n");
    return res;
}

int CompareWord(dic1 *p, int len)
{
    int res = 0;
    if (p == NULL)
    {
        res = -9;
        printf("err:%d, CompareWord NULL pointer\n", res);
        return res;
    }
    char *buf = (char *)calloc(1024, sizeof(char));
    while (1)
    {
        memset(buf, 0, 1024);
        printf("请输入检索单词：");
        gets(buf);
        int flag = 0;
        getStr(&buf);
        if (strcmp(buf, "0") == 0)
        {
            printf("检索退出\n");
            break;
        }

        int index = 0;
        for (index = 0; index < len; index++)
            if (strcmp(p[index].key, buf) == 0)
            {
                printf("单词：%s\n", p[index].key);
                unsigned int i = 0;
                for (i = 0; i < p[index].count; i++)
                    printf("释义%d：%s\n", i + 1, (p[index].content)[i]);
                flag = 1;
                break;
            }
        if (flag == 0)
            printf("404 NOT found\n\n");
    }
    free(buf);
    return res;
}

int FuncFree(dic1 **p, int len)
{
    int res = 0;
    if (p == NULL || *p == NULL)
    {
        res = -10;
        printf("err:%d, FuncFree NULL pointer\n", res);
        return res;
    }
    int index = 0;
    for (; index < len; index++)
    {
        char **t = (*p)[index].content;//2级指针接2级指针
        if (t)
        {
            unsigned int j = 0;
            for (j = 0; j < (*p)[index].count; j++)
            {
                if (t[j] == NULL)
                    free(t[j]);
                t[j] = NULL;
            }
            free(t);
            t = NULL;
        }
        if ((*p)[index].key)
        {
            free((*p)[index].key);
            (*p)[index].key = NULL;
        }
    }
    free(*p);
    printf("内存释放成功\n");
    return res;
}

int main(void)
{
    const char *pf = "E:/dict.txt";
    int len;
    getLen(pf, &len);
    len /= 2;
    dic1 *meth1 = (dic1*)calloc(len, sizeof(dic1));
    if (meth1 == NULL)
    {
        printf("main pointer allocate memory failed\n");
        return -1;
    }
    int res1 = StoreMemory(meth1, len, pf);
    if (res1 != 0)
        FuncFree(&meth1, len);
    int res2 = CompareWord(meth1, len);
    if (res2 != 0)
        FuncFree(&meth1, len);
    FuncFree(&meth1, len);
    return 0;
}
