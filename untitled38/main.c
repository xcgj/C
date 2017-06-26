//��һ�����飬����Ԫ��û�з��������һ����������ָ��λ�ò���ָ��Ԫ�أ�ָ��λ��ɾ��Ԫ��
//int a[15] = {1, 3, 5, 7, 9, 11, 13};
//a��������Ԫ�ص�ַ
//pos��ָ����λ��
//data����Ҫ�����Ԫ��
//size������ĳ��ȣ�����Ԫ�صĸ�������������Ĵ�С������Ԫ�أ���Ҫ����Ӧ�޸�

#include <stdio.h>

void insert_array(int *a, int pos, int data, int *size);
void remove_array(int *a, int pos, int *size);
void print_array(int *a, int size); //��ӡ����

int main()
{

    int a[15] = {1, 3, 5, 7, 9, 11, 13};
    int size = 7; //���鳤�ȣ��Ѿ���Ԫ�صĸ���

    print_array(a, size); //��ӡ
    insert_array(a, 0, -1, &size); //��0��λ�ò���-1
    print_array(a, size); //��ӡ

    insert_array(a, 2, 8, &size); //��2��λ�ò���8
    print_array(a, size); //��ӡ

    insert_array(a, size, 250, &size); //��ĩβ��λ�ò���250
    print_array(a, size); //��ӡ

    print_array(a, size); //��ӡ
    remove_array(a, 0, &size); //ɾ����0��Ԫ��
    print_array(a, size); //��ӡ

    return 0;
}

void print_array(int *a, int size)
{
    int i = 0;
    for (; i < size; i++)
        printf("a[%d] = %d\n", i, a[i]);
}

void insert_array(int *a, int pos, int data, int *size)
{
    int i = *size;
    for (; i > pos; i--)
        a[i] = a[i - 1];    //��һλ��ȡǰһλ��ֵ
    a[pos] = data;          //�������
    (*size)++;              //����Ԫ�ؼ�1
}

void remove_array(int *a, int pos, int *size)
{
    int i = pos;;
    for (; i < *size - 1; i++)
        a[i] = a[i + 1];
    (*size)--;
}
