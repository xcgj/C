//ʵ��һ��lite����ַ����滻����
//���¹��� -C/C++: char *strreplace(char *str, const char *sub, const char *rep)
//����������Ҫ������:
//����strΪԭ�ַ�����subΪ�����滻�� �Ӵ� ��Ϊ�����, �ٶ��ַ���sub��rep����һ��
//ֱ�Ӷ�ԭ�ַ���  str�����޸Ĳ�����  , ����ʹ��malloc/new�����µ��ڴ�ռ�
//����ʹ���κο⺯��/API, ������������strlen, strstr, strcpy, ����ʹ�����ƹ���, ������ʵ��
#include <stdio.h>

char *strreplace(char *str/*in*/, const char *sub/*in*/, const char *rep/*in*/)
{
    char *p_lacate = str;//��λ�ҵ��ĵ�һ��ƥ���ַ�
    char *p_start = str;//�����Ӵ���ָ��
    int len = 0;
    while (sub[len++]);
    len--;//sub�ַ�������
    int i = 0;//����str���±�
    int flag = 1;
    for (; p_start[i]; i++)//�����ַ���
        if (p_start[i] == sub[0])//������һ���ַ�ƥ�䣬����ǲ���Ҫ�ҵ��Ӵ�
        {
            p_lacate += i;//����Ӵ���ʼλ��
            int j = 1;
            for (; j < len; j++)
                if (p_start[i + j] != sub[j])
                {
                    flag = 0;
                    break;
                }
            if (flag)//˵��ֱ��ѭ�������ַ�����ƥ���
                break;//��ʼ�滻�ַ���
            else
                flag = 1;//����Ϊ1
        }
    for(i = 0; i < len; i++)
        p_lacate[i] = rep[i];
    return str;
}

int main_1(void)
{
    char a[100] = "qwertyuixcgjwert";
    const char b[5] = "xcgj";
    const char c[5] = "RBMW";
    strreplace(a, b, c);
    printf("%s\n", a);
    return 0;
}

int main(void)
{
    printf("%d\n", sizeof(int*));
    return 0;
}

