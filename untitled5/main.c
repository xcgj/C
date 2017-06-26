#include <stdio.h>
#include <string.h>
int main(void)
{
    char s[1024] = { 0 };
    //腾出内存搞事情
    FILE *p = fopen("E:\\C_project\\file.txt", "w");
    //定义指针指向文件打开的地址

    //如果把memset放这，输入会出现乱码，why？？？？？
    while(1)
    {
        memset(s, 0, sizeof(s));
        //搞事情的内存清零
        gets(s);
        //scanf("%s", s);用scanf不能输入空格
        //获得用户输入的字符串
        if(strcmp(s, "exit") == 0)
            break;//制定跳出循环条件
        int a = strlen(s);
        //计算用户每次输入多少个字符
        s[a] = '\n';
        fputs(s, p);
        //把存放字符串的地址赋值给文件的地址，
        //向文件写入一个字符串,
        //第二个参数和fopen的返回值配对使用
        //哪个指针打开这个文件，就写入哪个指针
    }
    fputs("end", p);
    //向文件写入一个字符串
    fclose(p);
    //关闭文件
    printf("DONE\n");
    return 0;
}
