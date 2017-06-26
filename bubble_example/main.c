#include <stdio.h>

int main(void)
{
    int array[10] = { 23, 45, 67, 14, 58, 89, 34, 16, 9, 37 };
    int array_length = 10;
    int i = 0;
    int j = 0;


    #if 0
    //写法一
    for (i = 0; i < array_length; i++)
        for (j = 1; j < array_length; j++)
            if (array[j] < array[j - 1])
            {
                int swap = array[j];
                array[j] = array[j - 1];
                array[j - 1] = swap;
            }
    #endif

    //写法二
    for (i = 0; i < array_length; i++)
        for (j = 0; j < array_length - 1; j++)
            if (array[j] > array[j + 1])
            {
                int swap = array[j];
                array[j] = array[j + 1];
                array[j + 1] = swap;
            }



    for (i = 0; i < 10; i++)
        printf("array[%d] = %d\n", i ,array[i]);
    return 0;
}

