#include <stdio.h>

int dichotomy_recursion(int array[], int index_min, int index_max, int search)
{
    //递归终止条件：index_min > index_max || 找到search
    int index_middle = (index_min + index_max) / 2;
    if (index_min > index_max)
        return -1;
    else if (search == array[index_middle])
        return index_middle;
    //递归时参数变成 index_middle +(-) 1
    else if (search > array[index_middle])
        return dichotomy_recursion(array, index_middle + 1, index_max, search);
    else
        return dichotomy_recursion(array, index_min, index_middle - 1, search);
}

int main(void)
{
    int array[10] = { 12, 23, 35, 45, 46, 56, 59, 60, 65, 90 };
    int index_find = dichotomy_recursion(array, 0, 9, 35);
    printf("%d\n", index_find);
    return 0;
}
