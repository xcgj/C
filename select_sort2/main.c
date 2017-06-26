#include <stdio.h>

int main(void)
{
    int array[10] = { 23, 45, 67, 14, 58, 89, 34, 16, 9, 37 };
    int index_start = 0;
    int index_end = 9;
    for (index_start = 0; index_start <= index_end; index_start++)//循环次数
    {
        int index_move = index_start;//每次移动时所在下标
        int index_record = index_start;//记录最小值的下标
        int array_min = array[index_start];//记录最小值
        for (index_move++; index_move <= index_end; index_move++)//循环遍历
            if (array_min > array[index_move])
            {
                array_min = array[index_move];
                index_record = index_move;
            }
        if (index_start != index_record)//循环结束，判断最小值的下标有没有发生变化
        {
            int swap = array[index_start];
            array[index_start] = array[index_record];
            array[index_record] = swap;
        }
    }

    int i = 0;
    for (; i < 10; i++)
        printf("array[%d] = %d\n", i ,array[i]);
    return 0;
}

