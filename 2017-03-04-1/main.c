#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main00(void)
{
    char a[100] = {0};
    fgets(a, 100, stdin);
    fputs(a, stdout);
    //printf("Hello World!\n");
    return 0;
}

int main01(void)
{
    char a[100] = "阿三sa速度d";
    int count = 0;
    int hanzi = 0;
    while(a[count])
    {
        if (a[count] < 0)
        {
            count += 3;
            hanzi++;
        }
        else
            count++;
    }
    printf("%d\n", hanzi);
    return 0;
}

int main_1(void)
{
    char s1[100] = { 0 };
    char s2[100] = { 0 };
    fgets(s1, 49, stdin);
    fgets(s2, 49, stdin);
    s1[strlen(s1) - 1] = '\0';
    s2[strlen(s2) - 1] = '\0';
    if (strcmp(s1, s2) == 0)
        strncat(s1, s2, 49);
    else
        strncpy(s1, s2, 99);
    fputs(s1, stdout);
    return 0;
}


int main_2(void)
{
    char s[100] = { 0 };
    //fgets(s, 99, stdin);
    gets(s);
    //fgets(s, sizeof(s) - 1, stdin);
    int a[10] = { 0 };
    sscanf(s, "%d+%d=", &a[0], &a[1]);
    char s2[100] = { 0 };
    sprintf(s2, "%s%d", s, a[0] + a[1]);
    //strcat
    fputs(s2, stdout);
    return 0;
}


/*
 *
3
int main()
{
    char buf[100] = "10086";
    int  number = 0;
    //你写的代码  要求不能使用任何库函数

    printf("%d",number);//结果显示为10086
}
*/
int main_atoi1(void)
{
    //1、遍历buffer，计算字符长度
    //2-1、遍历buffer，将每个字符-‘0’，
    //2-2、权值1*10*10……循环，依次相加
    char buf[100] = "10086";
    int  number = 0;
    int index = 0;
    int E = 1;
    while (buf[index++]);//1
    for (int i = index - 2; i >= 0; i--)//2-1
    {
        number += E * (buf[i] - '0');//2-2
        E *= 10;
    }
    printf("%d\n", number);
    return 0;
}







int main_____(void)
{
    //1 获取字符串长度
    //2 根据长度算每位上的权值
    //3 获取每位的数
    //4 每个位的权值和位上的数相乘
    char buf[100] = "10086";
    int len = length(buf);

    return 0;
}

int length(char *s)//1
{
    int i = 0;
    while(s[i])
    {
        i++;
    }
    return i;//长度，不是最大索引i-1
}

int weight(int n)//传递过来的n是索引，最小是0
{
    int i = 1;//权值
    int j = 0;
    for (j = 1; j <= n; j++)
    {
        i *= 10;
    }
}

int num(char c)
{

}










char max(char n, char m)
{
    return (n > m) ? n : m;
}

int main_5(void)
{
    int a = 5;
    int b = 6;
    printf("%c\n", max(a, b));
    return 0;
}





int year_calc(int year)
{
    if ((year % 100 != 0 || year % 4 == 0)
            && year % 400 == 0)
        //if (year %400 == 0 || year
        return 1;
    else
        return 0;
}

int month_calc(int year, int mon)
{
    int monday = 0;
    switch(mon)
    {
    case 12:case 10:case 8:case 7:case 5:
        case 3:case 1:
        monday = 31;
        break;
    case 2:
            monday = 28 + year_calc(year);
            break;
    default:
        monday = 30;
    }
    return monday;
}

int main_year_month(void)
{
    int a = 0;
    int b = 0;
    printf("please input year: ");
    scanf("%d", &a);
    printf("please input month: ");
    scanf("%d", &b);
    printf("mon %d,year %d have %d days\n", b, a, month_calc(a, b));
    return 0;
}






/*2.	奇数。
    函数原型 int isOddNumber(unsigned int number);
    函数功能 判断参数number是否是奇数 奇数判断依据是是否能够被2整除。
    函数返回值 如果是奇数返回0;如果不是奇数返回1
*/
int isOddNumber(unsigned int);

int main(void)
{
    unsigned a;
    printf("请输入一个正数：");
    scanf("%u\n", &a);
    while (isOddNumber(a))
    {
        printf("奇数\n");
        return 0;
    }
    printf("偶数\n");
    return 0;
}

int isOddNumber(unsigned int number)
{
    return (0 == number % 2) ? 0 : 1;
}
/*3.	钻石 or 玉石。
    钻石一颗20000，玉石一颗15000
    函数原型 int isEqual(int diamonds,int jade)
    函数功能 将diamonds颗数量的钻石的价值和jade颗玉石的价格进行比较
    函数返回值 如果钻石价值大则返回1  如果相等返回0 如果钻石价值小则返回-1
*/



/*4.  写1个函数 并且调用 输出运行结果。
    int getNumbers(int y1,int m1,int d1,int y2,int m2,int d2);
    函数功能: 获取出y1年m1月d1日到y2年m2月d2日之间有多少天？
    返回值:   返回两个日期之间所差的天数。
*/



/*5.  编写函数完成逆置UTF-8编码的汉字字符串的功能。<只需要在Linux上测试>
    input:我爱你886
    output:688你爱我
*/
