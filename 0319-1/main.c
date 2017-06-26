#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Teacher
{
    char *name;
    int age;
}teach;

int write(void)
{
    //获得信息放入结构体tch
    //将结构体写入文件
    //死循环， exit退出循环
    teach tch = { 0 };
    tch.name = (char*)malloc(30);
    FILE *p = fopen("a1.dat", "wb");
    if (p == NULL)
        return 0;
    while (1)
    {
        memset(tch.name, 0, 30);
        printf("please input name: \n");
        scanf("%s", tch.name);
        if (strncmp(tch.name, "exit", 4) == 0)
            break;
        printf("please input age: \n");
        scanf("%d", &tch.age);
        fwrite(&tch, 1, sizeof(teach), p);
    }
    fclose(p);
    free(tch.name);
    printf("write success\n");
    return 0;
}

int main(void)
{
    //读取文件内容
    //打出到屏幕
    //遇到结尾循环终止
    teach tch = { 0 };
    tch.name = (char*)malloc(30);
    FILE *p = fopen("a1.dat", "rb");
    if (p == NULL)
        return 0;
    while (1)
    {
        //memset(tch.name, 0, 30);
        fread(&tch, 1, sizeof(teach), p);
        if (feof(p))
            break;
        printf("%s\t%d\n", tch.name, tch.age);
    }
    fclose(p);
    free(tch.name);
    printf("read success\n");
    return 0;
}

