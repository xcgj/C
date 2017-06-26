#include <stdio.h>
#include <string.h>

void is_palindrome(const char *str, int *resu)
{
    int *res = resu;
    if (str == NULL)//防止空指针
    {
        *res = -1;
        return;
    }
    *res = 0;
    const char *buf1 = str;//1
    int index = strlen(buf1) - 1;
    const char *buf2 = buf1 + index;//在内存中，数组地址是一定增长的
    while (buf1 < buf2)//2
    {
//        if (strncmp(buf1, buf2, 1) == 0)
//        {
//            buf1++;
//            buf2--;
//        }
//        else
//        {
//            *res = 1;
//            break;
//        }
        if (*buf1++ != *buf2--)
        {
            *res = 1;
            break;
        }
    }
}

int main(void)
{
    char buf[100] = { 0 };
    gets(buf);
    int result;
    is_palindrome(buf, &result);
    if (result == -1)
        printf("func is_palindrome err:%d, NULL pointer\n", result);
    else if (result == 0)
        printf("这是一个回文字符串\n");
    else
        printf("这不是一个回文字符串\n");
    return 0;
}

