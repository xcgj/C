// ����ṹ��struct
// �����ļ���ó���n, feof()+fgets()  fseek()+ftell  222204��  feof()+reallocѭ�������ڴ�
// ����ṹ�������ڴ棬����ı��ļ��е��������ݣ����鳤��=n/2
// key��Ա��ÿ��ѭ��strlen()-1�����ڴ棬 strtok()  strcpy()+ָ�����һλ  strchr()+strcpy()
// content��Ա��ÿ��ѭ��strlen()-1�����ڴ棬strchr()+strcpy()  strstr()+strcpy()
// ���������ַ�����ȥ�ڴ�ƥ��strncmp()�ṹ���key��Ա��ƥ��ɹ����content��Ա��ʧ����ʾû���ҵ�

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct dic
{
    char *key;
    char *content;
}dic1;

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
        s[index].content = (char*)calloc(length - 6/*������Trans:�ַ���*/, sizeof(char));
        strncpy(s[index].content, buf + 6, length - 7/*ȥ��\n*/);
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
    char buf[1024] = { 0 };
    while (1)
    {
        printf("������������ʣ�");
        gets(buf);
        int flag = 0;
        int ulen = strlen(buf);
        if (strncmp(buf, "0", ulen) == 0)
        {
            printf("�����˳�\n");
            break;
        }
        int index = 0;
        for (index = 0; index < len; index++)
            if (strncmp(p[index].key, buf, ulen) == 0)
            {
                printf("���룺%s\n", p[index].content);
                flag = 1;
                break;
            }
        if (flag == 0)
            printf("404 NOT found\n");
    }
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
    for (;index < len; index++)
    {
        if ((*p)[index].key)
        {
            free((*p)[index].key);
            (*p)[index].key = NULL;
        }
        if ((*p)[index].content)
        {
            free((*p)[index].content);
            (*p)[index].content = NULL;
        }
    }
    free(*p);
    printf("�ڴ��ͷųɹ�\n");
    return res;
}

int main(void)
{
    const char *pf = "E:/dict.txt";
    int len = 111102;//getLen (pf);
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
