// 定义结构体struct
// 遍历文件获得长度n, feof()+fgets()  fseek()+ftell  222204行  feof()+realloc循环申请内存
// 申请结构体数组内存，存放文本文件中的所有数据，数组长度=n/2
// key成员：每次循环strlen()-1分配内存， strtok()  strcpy()+指针后移一位  strchr()+strcpy()
// content成员：每次循环strlen()-1分配内存，strchr()+strcpy()  strstr()+strcpy()
// 获得输入的字符串，去内存匹配strncmp()结构体的key成员，匹配成功输出content成员，失败提示没有找到
#define _CRT_SECURE_NO_WARNINGS

//定义结构体分别读取tar文件名和tar文件长度
//转化tar文件长度
//fread 512字节以后的size长度
//fwrite到新文件
//当读到的文件名是NULL时，停止读取

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct tar_header
{
    char name[100];//文件名
    char mode[8];
    char uid[8];
    char gid[8];
    char size[12]; //文件大小的八进制数的字符串形式
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
