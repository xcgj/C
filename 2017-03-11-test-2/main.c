#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
void recur_verse(char *s, char *verse)
{
    if (s == NULL)  //  判断空指针
    {
         printf("func recur_inverse error, (s == NULL)\n");
         return;
    }
    else if (*s == '\0')
        return; //递归终止条件
    char *temp_s = s;
    char *temp_verse = verse;
    recur_verse(temp_s + 1, temp_verse);
    strncat(temp_verse, temp_s, 1); //逆序递归赋值
}


void str_verse(char *str)
{
    if (str == NULL)  //判断空指针
    {
        printf("func str_verse error, (str == NULL)\n");
        exit(-1);
    }
    char *temp_str = str;//临时指针
    char buf_str[100] = { 0 };//提取子串
    char store_str[100] = { 0 };//子串接收并逆置
    char store_str2[100] = { 0 };//合并逆置的子串
    while (*temp_str)
    {
        memset(buf_str, 0, 100 * sizeof(char));//1 每次循环清空buf，//提取子串
        memset(store_str, 0, 100 * sizeof(char));//子串接收并逆置
        while (!isspace(*temp_str)/**temp_str != ' '*/ && *temp_str)//2 当temp != ' '，赋值给buf
        {
            strncat(buf_str, temp_str, 1);
            temp_str++;
        }
        recur_verse(buf_str, store_str);//递归逆置
        strcat(store_str2, store_str);
        while (isspace(*temp_str)/**temp_str == ' '*/)
        {
            strncat(store_str2, temp_str, 1);//循环结束两个都指向空格字符后一位
            temp_str++;
        }
    }
    strcpy(str, store_str2);
}

int main(void)
{
    char p[100] = "hello world itheima good";
    str_verse(p);
    printf("%s\n", p);
    return 0;
}
