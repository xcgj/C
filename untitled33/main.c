//实现一个lite版的字符串替换函数
//创新工场 -C/C++: char *strreplace(char *str, const char *sub, const char *rep)
//限制条件和要求如下:
//其中str为原字符串，sub为待被替换的 子串 。为简单起见, 假定字符串sub和rep长度一样
//直接对原字符串  str进行修改并返回  , 不得使用malloc/new开辟新的内存空间
//不得使用任何库函数/API, 包括但不限于strlen, strstr, strcpy, 如需使用类似功能, 请自行实现
#include <stdio.h>

char *strreplace(char *str/*in*/, const char *sub/*in*/, const char *rep/*in*/)
{
    char *p_lacate = str;//定位找到的第一个匹配字符
    char *p_start = str;//遍历子串的指针
    int len = 0;
    while (sub[len++]);
    len--;//sub字符串长度
    int i = 0;//遍历str的下标
    int flag = 1;
    for (; p_start[i]; i++)//遍历字符串
        if (p_start[i] == sub[0])//遇到第一个字符匹配，检查是不是要找的子串
        {
            p_lacate += i;//标记子串起始位置
            int j = 1;
            for (; j < len; j++)
                if (p_start[i + j] != sub[j])
                {
                    flag = 0;
                    break;
                }
            if (flag)//说明直到循环结束字符都是匹配的
                break;//开始替换字符串
            else
                flag = 1;//重置为1
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

