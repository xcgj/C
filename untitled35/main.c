/*
 * ����ԭ�� int *getSpace(int n);
 *  ����n�����Դ洢n��������Ķѿռ�  ����ͨ����������ֵ���ء�
 * ����ԭ�� int createNumber(int n,int *p); //����n��������� (1<= x <=n)
 *  ����Ҫ�����������Χ��1��n֮��浽pָ��Ŀռ�
 * ����ԭ�� int writeFile(int n,const char *p);
 *  ����pָ���ڴ��n�����ظ�����д�뵽test.txt�ļ���
 * ����ԭ�� int readFile(int n,const char **p1);
 *  ����test.txt�ļ��е�n������n�ɶ�ȡ��һ�л�ã�д��*p1ָ���ڴ�ռ�
 * ����ԭ�� int deleteSame(int n,const int *p);
 *  ��pָ���n���ռ��е����ֽ���ɾ���ظ��Ĳ��� ��������n������ɾ���ظ���֮��ʣ�����ֵĸ���
 * ����ԭ�� int freeSpace(int **p);
 *  ��getSpace����Ŀռ��ͷ� ���ҷ�ֹ������;ָ��
 * ����ԭ�� int printfSpace(int *p,int n);
 *  ��pָ��Ŀռ��n��������ӡ����
    1 ������������n��n����������Ҫ�������ٸ���������ں���Ĳ�����
    2 ���ú��� p=getSpace(n) ��������n�����ܹ�����n�������Ķѿռ���p�����׵�ַ
    3 ���ú���createNumber(n,p)���ڲ���n�����ظ�����������Ҵ洢��pָ����ڴ���
    3 ���ú��� writeFile(n,p);��pָ���ڴ��n�����ظ�����д�뵽test.txt�ļ���,��д���ļ���ʱ�� ��һ��д��n����ֵ
    4 ���ú��� freeSpace�ͷŵ�pָ��Ŀռ�
    5 ���ú��� readFile(n,&p1);ʱ�ȶ�ȡ��һ�� ��ȡ��nֵ Ȼ�����getSpace(n)��ȡ�ڴ�ռ�֮���Ҵ洢�׵�ַ��p1��
    6 ���ú���int m= deleteSame(n,p1);ɾ��p1ָ����ڴ���n������ͬ������
    7 ���ú���printfSpace(m,p1);��ӡ��p1ָ����ڴ���ʣ���m������
    8 �ͷ�p1ָ����ڴ� freeSpace(&p1);
    */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int printfSpace(int m, int *p1);
int deleteSame(int n, int **p1);
int freeSpace(int **p);
int *getSpace(int n);
int createNumber(int n, int *p);
int writeFile(int n, int *p);
int readFile(int n, int **p1);

int main(void)
{
    int n = 0;
    while (n < 1)
    {
        printf("please input a number(n > 0):\n");
        scanf("%d", &n);
    }

    int *p = getSpace(n);
    createNumber(n, p);
    int i = 0;
    for (i = 0; i < n ; i++)
        printf("%d\n", p[i]);
    writeFile(n, p);
    freeSpace(&p);

    int *p1 = NULL;
    readFile(n, &p1);

    int m = deleteSame(n, &p1);
    printfSpace(m, p1);
    freeSpace(&p1);

    return 0;
}

int *getSpace(int n)//����n�����Դ洢n��������Ķѿռ�  ����ͨ����������ֵ���ء�
{
    int *num = (int*)calloc(n, sizeof(int));
    if (num == NULL)
        fprintf(stderr, "p_temp is a NULL pointer\n");
    return num;
}

int createNumber(int n,int *p)
//����n��������� (1<= x <=n) ����Ҫ�����������Χ��1��n֮��浽pָ��Ŀռ�
{
    int ret = 0;
    if (n < 1 || p == NULL)
    {
        ret = -1;
        fprintf(stderr, "n < 1 or p is a NULL pointer\n");
        return ret;
    }
    srand((unsigned int)time(NULL));
    int i, j;
    for (i = 0; i < n; i++)
    {
        p[i] = rand() % n + 1;
        for (j = 0; j < i; j++)
        {
            if (p[j] == p[i])
            {
                i--;
                break;
            }
        }
    }
    return ret;
}

int writeFile(int n, int *p)
//����pָ���ڴ��n�����ظ�����д�뵽test.txt�ļ���,��д���ļ���ʱ�� ��һ��д��n����ֵ
{
    int res = 0;
    if (p == NULL)
    {
        res = -1;
        fprintf(stderr, "writeFile err");
        return res;
    }
    FILE *pf = fopen("test.txt", "w");
    if (pf == NULL)
    {
        res = -1;
        fprintf(stderr, "fopen err");
        return res;
    }
    fprintf(pf, "%d\n", n);
    int i = 0;
    for (i = 0; i < n; i++)
        fprintf(pf, "%d\n", p[i]);
    fclose(pf);
    return res;
}

int freeSpace(int **p)//��getSpace����Ŀռ��ͷ� ���ҷ�ֹ������;ָ��
{
    int ret = 0;
    if(p == NULL)
    {
        ret = -1;
        fprintf(stderr, "freeSpace err");
        return ret;
    }
    if(*p)
    {
        free(*p);
        *p = NULL;
    }
    return ret;
}

int readFile(int n, int **p1)//��test.txt�ļ��е�n������n�ɶ�ȡ��һ�л�ã�д��*p1ָ���ڴ�ռ�
//�ȶ�ȡ��һ�� ��ȡ��nֵ Ȼ�����getSpace(n)��ȡ�ڴ�ռ�֮���Ҵ洢�׵�ַ��p1��
{
    int res = 0;
    if (p1 == NULL)
    {
        res = -1;
        fprintf(stderr, "readFile err");
        return res;
    }
    FILE *pf = fopen("test.txt", "r");
    if (pf == NULL)
    {
        res = -1;
        fprintf(stderr, "fopen err");
        return res;
    }
    char c[10] = { 0 };
    fgets(c, 10, pf);
    n = atoi(c);
    //printf("%d\n", n);
    *p1 = getSpace(n);
    return res;
}

int deleteSame(int n, int **p1)
//��pָ���n���ռ��е����ֽ���ɾ���ظ��Ĳ��� ��������n������ɾ���ظ���֮��ʣ�����ֵĸ���
//ɾ��p1ָ����ڴ���n������ͬ������
{
    int res = 0;
    if (p1 == NULL || *p1 == NULL)
    {
        res = -1;
        fprintf(stderr, "deleteSame err");
        return res;
    }
    int i, j, k, flag = 0;
    int *temp = (int*)calloc(n, sizeof(int));
    for (i = 0, k = 0; i < n; i++)//ͳ�Ʋ���ͬ�ĸ���
    {
        for (j = 0; j < i; j++)
        {
            if ((*p1)[i] == (*p1)[j])
            {
                flag = 1;
                break;
            }
        }
        if (flag)
            continue;
        temp[k] = (*p1)[i];
        k++;
    }
    *p1 = (int*)realloc(*p1, k + 1);//����p1�Ķѿռ�
    for (i = 0; i <= k; i++)//���鿽��
        (*p1)[i] = temp[i];
    free(temp);
    return k + 1;
}


int printfSpace(int m, int *p1)
{
    int res = 0;
    if (p1 == NULL)
    {
        res = -1;
        fprintf(stderr, "printfSpace err");
        return res;
    }
    int i = 0;
    for (i = 0; i < m; i++)
        printf("%d\n", p1[i]);
    return res;
}
