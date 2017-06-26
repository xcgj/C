#include <stdio.h>

int sequential_search(int *array, int array_length, int search)
{
    int i = 0;
    for (i = 0; i < array_length; i++)
        if (search == array[i])
            return i;//找到了就返回对应下标
    return -1;
}

int main(void)
{
    int array[10] = { 23, 45, 67, 14, 58, 89, 34, 16, 9, 37 };
    int wantted = sequential_search(array, 10, 16);
    printf("index = %d\n", wantted);
    return 0;
}

