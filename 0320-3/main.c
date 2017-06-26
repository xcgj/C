//找出文件中身高/体重比最小的人，行数未知。
//文件格式:

//name=xxx1,high=xxxx,weight=xxxxx
//name=xxx2,high=xxxx,weight=xxxxx
//name=xxx3,high=xxxx,weight=xxxxx

//题解：
//定义结构体，身高/体重初始化时大一点
//读一行，身高/体重和结构体的比较，如果小，求出名字赋值结构体

#include <stdio.h>
#include <string.h>
typedef struct
{
    char name[100];
    int high;
    int weight;
}HW;

int write(char *fp)
{
    FILE *p = fopen(fp, "wb");
    while (1)
    {
        char cmd[10];
        printf("please input cmd: ");
        scanf("%s", cmd);
        if (strncmp(cmd, "exit", 4) == 0)
            break;
        if (strncmp(cmd, "add", 3) == 0)
        {
            HW hw;
            printf("please input name&hight&weight: \n");
            scanf("%s", hw.name);
            scanf("%d", &hw.high);
            scanf("%d", &hw.weight);
            fwrite(&hw, sizeof(HW), 1, p);
        }
    }
    fclose(p);
    return 0;
}

int read(char *fp, HW *pmin)
{
    FILE *p = fopen(fp, "rb");
    HW min_t;
    fread(&min_t, sizeof(HW), 1, p);
    HW temp;
    while (fread(&temp, sizeof(HW), 1, p))
        if (temp.high / temp.weight < min_t.high / min_t.weight)
            min_t = temp;
    *pmin = min_t;
    fclose(p);
    return 0;
}

int main(void)
{
    char *f = "E:/hw.dat";
    HW min;
    write(f);
    read(f, &min);
    printf("身高/体重比最小的人是：%s\n身高：%d\n体重：%d\n", min.name, min.high, min.weight);
    return 0;
}

