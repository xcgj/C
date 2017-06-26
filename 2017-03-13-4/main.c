//4、将原字符串中处理的结果存放到一个动态开辟的堆空间中。（处理过程：将原字符中的aa替换为A）
//	函数原型：char *replace_char(const char *str);
//	函数返回值:
//  将替换后的字符串打印出来，并且释放动态开辟的内存空间。

//1 调用函数里面定义临时指针变量
//2 临时指针变量分配堆内存
//3 更改字符串，放到堆空间
//4 打印字符串
//5 释放堆空间
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
char *replace_char(const char *str)
{
    const char *str_temp = str;
    char *buffer = (char *)calloc(100, sizeof(char));//1 2
    int len = strlen(str_temp);
    for (int i = 0, j = 0; i < len; i++, j++)
    {
        if ((str_temp[i] == str_temp[i + 1]) && islower(str_temp[i]))
            buffer[j] = str_temp[i++] - ('a' - 'A');
        else
            buffer[j] = str_temp[i];
    }
    return buffer;
}

int main(void)
{
    const char *p= "aaBBccDDeeffgghikGH";
    char *p1 = replace_char(p);
    printf("%s\n", p1);//4
    free(p1);//5
    return 0;
}

