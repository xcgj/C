// ����ṹ��struct
// �����ļ���ó���n, feof()+fgets()  fseek()+ftell  222204��  feof()+reallocѭ�������ڴ�
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
    char *content;
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

int StoreMemory(dic1 **s, int *len, const char *pf)
{
    int res = 0;
    if (pf == NULL || s == NULL || len == NULL)
    {
        res = -8;
        printf("err:%d, StoreMemory NULL pointer\n", res);
        return res;
    }
    //����ָ�������ڴ�
    int n = 1000;//��ʼ����1000���ṹ���ڴ�
    dic1 *meth = (dic1*)calloc(n, sizeof(dic1));
    if (meth == NULL)
    {
        printf("main pointer allocate memory failed\n");
        return -1;
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
    while (!feof(p))//(index < 111103)
    {
        n++;
        if (n % 1000 == 0)
        {
            dic1 *temp = (dic1*)realloc(meth, n * sizeof(dic1));
            if (temp == NULL)
            {
                printf("main pointer reallocate memory failed\n");
                FuncFree(&meth, n);
                return -1;
            }
            meth = temp;
        }
        memset(buf, 0, sizeof(buf));
        if(NULL == fgets(buf, sizeof(buf), p))
            break;
        int length = strlen(buf);//ÿ���ַ�������
        meth[index].key = (char*)calloc(length - 1/*������#�ַ�*/, sizeof(char));
        strncpy(meth[index].key, buf + 1, length - 2/*ȥ��\n*/);

        memset(buf, 0, sizeof(buf));
        if(NULL == fgets(buf, sizeof(buf), p))
            break;
        length = strlen(buf);//ÿ���ַ�������
        meth[index].content = (char*)calloc(length - 6/*������Trans:�ַ���*/, sizeof(char));
        strncpy(meth[index].content, buf + 6, length - 7);
        //printf("%s\n%s\n", meth[index].key, meth[index].content);
        index++;
    }
    *s = meth;
    *len = index - 1;

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
        printf("������������ʣ�");
        gets(buf);
        int flag = 0;
        //int ulen = strlen(buf);
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
                printf("���룺%s\n", p[index].content);
                flag = 1;
                break;
            }
        if (flag == 0)
            printf("NOT found\n");
    }
    free(buf);
    return res;
}



int main(void)
{
    const char *pf = "E:/dict.txt";
    int len = 0;
    dic1 *meth1 = NULL;//(dic1*)calloc(len, sizeof(dic1));
    int res1 = StoreMemory(&meth1, &len, pf);//�����ڴ�
    if (res1 != 0)
        FuncFree(&meth1, len);
    int res2 = CompareWord(meth1, len);//�ַ����Ƚ�
    if (res2 != 0)
        FuncFree(&meth1, len);
    FuncFree(&meth1, len);
    return 0;
}

