// ����ṹ��struct
// �����ļ���ó���n, feof()+fgets()
// ����ṹ�������ڴ棬����ı��ļ��е��������ݣ����鳤��=n/2
// key��Ա��ÿ��ѭ��strlen()-1�����ڴ棬 strtok()  strcpy()+ָ�����һλ  strchr()+strcpy()
// content��Ա��ÿ��ѭ��strlen()-1�����ڴ棬strchr()+strcpy()  strstr()+strcpy()
// ���������ַ�����ȥ�ڴ�ƥ��strncmp()�ṹ���key��Ա��ƥ��ɹ����content��Ա��ʧ����ʾû���ҵ�


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
    int index = 0;//�ṹ�������±�
    for (index = 0; index < len; index++)
    {
        memset(buf, 0, 1024);
        fgets(buf, 1024, p);
        int length = strlen(buf);//ÿ���ַ�������
        s[index].key = (char*)calloc(length - 1/*������#�ַ�*/, sizeof(char));
        strncpy(s[index].key, buf + 1, length - 2/*ȥ��\n*/);

        memset(buf, 0, 1024);
        fgets(buf, 1024, p);
        length = strlen(buf);//ÿ���ַ�������
        char *buf1 = (char*)calloc(length, sizeof(char));
        char *buf2 = (char*)calloc(length, sizeof(char));
        strncpy(buf1, buf + 6/*������Trans:�ַ���*/, length/*ȥ��\n*/);
        strncpy(buf2, buf + 6/*������Trans:�ַ���*/, length/*ȥ��\n*/);

        //���㳤��
        //�ٸ�ÿ��ָ����䳤��
        /*strchr(buf1, '@');
        buf1++;*/
        s[index].count = 1;
        while (buf1=strchr(buf1, '@'))
        {
            buf1++;
            s[index].count++;
        }
        // buf1 -= length - 7;ָ�����
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
    printf("���ʼ��سɹ�\n");
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
        printf("������������ʣ�");
        gets(buf);
        int flag = 0;
        getStr(&buf);
        if (strcmp(buf, "0") == 0)
        {
            printf("�����˳�\n");
            break;
        }

        int index = 0;
        for (index = 0; index < len; index++)
            if (strcmp(p[index].key, buf) == 0)
            {
                printf("���ʣ�%s\n", p[index].key);
                unsigned int i = 0;
                for (i = 0; i < p[index].count; i++)
                    printf("����%d��%s\n", i + 1, (p[index].content)[i]);
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
        char **t = (*p)[index].content;//2��ָ���2��ָ��
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
    printf("�ڴ��ͷųɹ�\n");
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
