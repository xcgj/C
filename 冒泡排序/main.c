#include <stdio.h>

struct car
{
    int speed;
    int sits;
    char color[8];
};

void swap(struct car *, struct car *);

int main()
{
    struct car as[5] =
    {
        { 500, 4, "red" },
        { 500, 6, "white" },
        { 500, 8, "black" },
        { 600, 8, "silk" },
        { 300, 4, "golden" }
    };
    int i = 0;
    int j = 0;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 4 - i; j++)
        {
            if (as[j].speed < as[j + 1].speed)
            //判断速度
                swap(&as[j], &as[j + 1]);
            else if (as[j].speed == as[j + 1].speed)
            {
                if (as[j].sits < as[j + 1].sits)
                //速度相同判断座位
                    swap(&as[j], &as[j + 1]);
            }
        }
    }
    for (i = 0; i < 5; i++)//遍历
        printf("as[%d].speed = %d\tas[%d].sits = %d\t"
               "as[%d].color = %d\n",
                i, as[i].speed, i, as[i].sits, i,
               as[i].color);
    return 0;
}

void swap(struct car *p, struct car *q)//类型和实参相同
//交换值
{
    struct car a = *p;//类型一致
    *p = *q;
    *q = a;
}
