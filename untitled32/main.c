// ����ṹ��struct
// �����ļ���ó���n, feof()+fgets()  fseek()+ftell  222204��  feof()+reallocѭ�������ڴ�
// ����ṹ�������ڴ棬����ı��ļ��е��������ݣ����鳤��=n/2
// key��Ա��ÿ��ѭ��strlen()-1�����ڴ棬 strtok()  strcpy()+ָ�����һλ  strchr()+strcpy()
// content��Ա��ÿ��ѭ��strlen()-1�����ڴ棬strchr()+strcpy()  strstr()+strcpy()
// ���������ַ�����ȥ�ڴ�ƥ��strncmp()�ṹ���key��Ա��ƥ��ɹ����content��Ա��ʧ����ʾû���ҵ�
#define _CRT_SECURE_NO_WARNINGS

//����ṹ��ֱ��ȡtar�ļ�����tar�ļ�����
//ת��tar�ļ�����
//fread 512�ֽ��Ժ��size����
//fwrite�����ļ�
//���������ļ�����NULLʱ��ֹͣ��ȡ

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct tar_header
{
    char name[100];//�ļ���
    char mode[8];
    char uid[8];
    char gid[8];
    char size[12]; //�ļ���С�İ˽��������ַ�����ʽ
    char mtime[12];
    char chksum[8];
    char typeflag;
    char linkname[100];
    char magic[6];
    char version[2];
    char uname[32];
    char gname[32];
    char devmajor[8];
    char devminor[8];
    char prefix[155];
    char padding[12];
};

int otod(char *s)
{
    int o = atoi(s);
    int i = 1;
    int sum = 0;
    while (o)
    {
        sum += i * (o % 10);
        i *= 8;
        o /= 10;
    }
    return sum;
}

int main(void)
{
    char a[] = "01314";
    int res = otod(a);
    printf("%d", res);
    return 0;
}
