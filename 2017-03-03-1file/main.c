#include <stdio.h>
#include <string.h>

int arithmetic(int a, int b, char c)
{
    switch(c)
    {
    case '+':
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    case '*':
        return a * b;
        break;
    case '/':
        if (0 == b)
            return 0;
        return a / b;
    }
}

int cut(char s[])
{
    char buffer1[100] = { 0 };
    char operat = 0;
    char buffer2[100] = { 0 };
    int index_1 = 0;
    while(*s)//截取第一个数
    {
        if('+' == *s || '-' == *s || '*' == *s || '/' == *s)
            break;//此时，s指向符号位，index_1指向0；
        buffer1[index_1++] = *s;
        s++;
    }
    int a = atoi(buffer1);

    operat = *s++;//截取操作符

    int index_2 = 0;
    while(*s)//截取第二个数
    {
        if('=' == *s)
            break;//此时，s指向=，index_2指向0；
        buffer2[index_2++] = *s;
        s++;
    }
    int b = atoi(buffer2);
    return arithmetic(a, b, operat);
}

void tail(char *s)
{
    while(*s)
    {
        *s = ('\n' == *s) ? '\0' : *s;
        s++;
    }
}

void myitoa(char *s, int i)
{
    //计算整数长度
    int index = 0;
    int k = i;
    while (k)
    {
        k /= 10;
        index++;//位数
    }
    //最低开始依次加'0'，直到高位，逆序放入字符串数组
    int j = 0;
    for (j = index - 1; j >= 0; j--)
    {
        s[j] = (i % 10) + '0';
        i /= 10;
    }
}

int main(void)
{
    char buffer1[100] = { 0 };
    int buffer2 = 0;
    char buffer2_char [100] = { 0 };
    //打开文件1 2
    FILE *f1 = fopen("E:\\C_project\\file5.txt", "r");
    FILE *f2 = fopen("E:\\C_project\\file7.txt", "w");
    //清理缓存，获取每行字符!feof(), fgets(),
    while (!feof(f1))
    {
        memset(buffer1, 0, sizeof buffer1);
        memset(buffer2_char, 0, sizeof buffer2_char);
        //从文件1获得计算公式
        fgets(buffer1, sizeof buffer1, f1);
        if (strcmp(buffer1, "\n") == 0)
            goto W;
        //去掉buffer1每行结尾的'\n'
        tail(buffer1);
        //传给计算公式cut函数计算，结果放在int里
        buffer2 = cut(buffer1);
        //将int值转为buffer2_char数组
        myitoa(buffer2_char, buffer2);
        //fputs()将计算公式和结果字符传给文件2
        fputs(buffer1, f2);
        if(0 == buffer2)//如果计算公式是0，不会输出，因为是字符串
            fputs("0", f2);//所以加个判断，输出字符“0”
        fputs(buffer2_char, f2);
        W:fputs(NULL, f2);//这里想在空行的地方不输出任何字符，结果失败了
                          //文件结尾的0去不掉
        fputs("\n", f2);//加个换行，因为之前把换行符去掉了
    }
    //关闭文件1 2
    fclose(f1);
    fclose(f2);
    printf("Program succeed!\n");
    return 0;
}
