#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
void searchnum(char *st, int *a)
{
    if (st == NULL || a == NULL)
    {
        printf("func searchnum error: NULL pointer\n");
        return;
    }
    int len = strlen(st);
    for (int i = 0; i < len; i++)//�����ַ���
    {
        if (isdigit (st[i]))//����������ַ�
            a[st[i] - '0']++;//4  int isdigit ( int c )�ж������ַ�������0��ת������
    }//5  a[10]���飬��������0-9������һ�����֣���Ӧ�����±��Ԫ�ص�ֵ��1
}

void listnum(int *a)
{
    if (a == NULL)
    {
        printf("func listnum error: NULL pointer\n");
        return;
    }
    for (int i = 0; i < 10; i++)//��������
        printf("%d����%d��\n", i, a[i]);
}

void getin(char **st)
{
    if (st == NULL)
    {
        printf("func getin error: NULL pointer\n");
        return;
    }
    char *s = (char *)malloc(1024 * sizeof(char));
    if (s == NULL)
    {
        printf("func getin error: memory allocate failed\n");
        return;
    }
    gets(s);
    *st = s;
}

int main(void)
{
    char *str = NULL;
    int arr[10] = { 0 };//2 ����һ��a[10]����
    getin(&str);//1 ����ַ���

    searchnum(str, arr);//3 ��������

    listnum(arr);//6 ����a[10]����

    free(str);
    str = NULL;

    return 0;
}

