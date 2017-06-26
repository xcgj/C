#include <stdio.h>

struct car
{
    int speed;
    int sits;
    char color[8];
};

int main()
{
    struct car as[5] =
    {
    {500, 4, "red"},
    {500, 6, "white"},
    {500, 8, "black"},
    {600, 8, "silk"},
    {300, 4, "golden"}
    };
    int i = 0;
    int j = 0;
    for(i = 0; i < 5; i++)
    //先按车速排序
    {
        for(j = 1; j < 5 - i; j++)
        {
            if(as[j].speed > as[j - 1].speed)
            //相邻比较，车速高的排前面
            {
                struct car temp = as[j - 1];
                as[j - 1] = as[j];
                as[j] = temp;
            }
        }
    }

    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 4 - i; j++)
        {
            if(as[j].sits < as[j + 1].sits)
            {
                struct car temp = as[j];
                as[j] = as[j + 1];
                as[j + 1] = temp;
            }
        }
    }

    for(i = 0; i < 5; i++)
        printf("as[%d].speed = %d\tas[%d].sits = %d\tas[%d].color = %s\n",
               i, as[i].speed, i, as[i].sits, i, as[i].color);
    return 0;
}

