//姓名=刘德华,年龄=50
//姓名=安倍,年龄=30
//姓名=张学友,年龄=45
//姓名=苍老师,年龄=70
#include <stdio.h>
#include <string.h>
//typedef struct
//{
//    char a[100];
//    char b[100];
//}A;

int main()
{   //1 fscanf"姓名="获得字符串
    //2 strtok'，'得到名字
    //3 strchr“=”，两次，再进一位得到年龄
    char *sto[100] = { 0 };
    char *stp[100] = { 0 };
    FILE *p = fopen("E:\\sort.txt", "r");
    if (p == NULL)
        return -1;
    int i = 0;//计算下标
    while (1)
    {

        fscanf(p, "姓名=%s", sto[i]);//1 fscanf"姓名="获得字符串
        strcpy(sto[i], strtok(sto[i], ','));//2 strtok'，'得到名字
        char buf[100] = { 0 };
        fgets(buf, sizeof buf, p);
        strcpy(buf, strchr(strchr(buf, '='), '=')); //3 strchr“=”，两次，
        strcpy(stp[i], buf + 1);//再进一位得到年龄

        if (!feof(p))//读到文件末行，不用继续循环
            break;

        printf("%s, %s\n", sto[i], stp[i]);

        i++;
    }
    fclose(p);

    return 0;
}
