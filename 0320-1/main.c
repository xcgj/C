//��ȡ�������������ĸ���
//����ԭ�ͣ�int getCountOfPrimer(int arr[],int len,unsigned int *p_count);
//�������ܣ���ȡ������arr�������ĸ���
//��������:	arr����Ҫ��ɨ�������
//	p_count��һ��������ָ�����,����ȡ����������������
//��������ֵ��
//	�ɹ�����0��
//	����д��󷵻�-1

//����������1��������֮��û��������Լ����
//Լ�����ֳ�����������a��������b(b��0) ���õ���������������û�����������Ǿ�˵a�ܱ�b��������b������a��

//����2����1�ͱ���2�ܹ�����2֮�⣬û�е��������ܹ�����2������2��������
//����5����1�ͱ���5�ܹ�����5֮�⣬û�е��������ܹ�����5������5��������

//��⣺
// ��������
// ��������������+1
// ����������������&(flag = 1), ����Ԫ�����βδ��룬
// ���������2��n-1��ʼģ��ģ����0����ѭ����flag = 0����������������flag = 1

#include <stdio.h>
#include <stdlib.h>

int IsPrime(int a)//�ж��ǲ�������
{
    if (a == 0)
        return 0;
    int i = 2;
    for(; i < a; i++)
        if (!(a % i))
            return 0;
    return 1;
}

int getCountOfPrimer(int *arr/*in*/,int len,unsigned int *p_count/*out*/)
{
    if (arr == NULL || p_count == NULL)
        return -1;
    int i = 0;
    for (; i < len; i++)
        *p_count += IsPrime(arr[i]);
    return 0;
}

int main(void)
{
    int i = 0;
    int length = 0;
    unsigned int count = 0;

    printf("���������鳤��: ");
    scanf("%d", &length);

    int *array = (int*)calloc(length, sizeof(int));
    printf("������%d��Ԫ��: \n", length);
    for (; i < length; i++)
        scanf("%d", &array[i]);

    getCountOfPrimer(array, length, &count);
    printf("��������������Ϊ %u ��\n", count);
    return 0;
}

