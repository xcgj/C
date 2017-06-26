#include <stdio.h>

int findmin(int *, int, int);
int select_sort(int *, int);

int main(void)
{
    //思路：
    //1 每次循环找出最小的数，放在最前面
    //1-1 利用下标进行定位数值，交换数值
    //2 每次循环之后前面，前面排好的数不用管了，只需要循环后面没有排的数
    //总的循环次数比数组长度小1，即循环次数 == 数组最大下标
    int array[10] = { 23, 45, 67, 14, 58, 89, 34, 16, 9, 37 };
    select_sort(array, 10);
    int i = 0;
    for (i = 0; i < 10; i++)
        printf("array[%d] = %d\n", i ,array[i]);
    return 0;
}

int findmin(int *array, int index_move, int index_max)//1
{
    int index_min = index_move;//将第一位数的下标当作最小值的下标，存在最小值下标存储器里面
    int value_min = array[index_move];//将第一位数当作最小值，存在最小值存储器里面
    for (index_move++ ; index_move < index_max; index_move++)//把未排序的数值遍历一遍
    {
        if (value_min > array[index_move])//如果在遍历过程中最小值存储器遇到更小的数，两个存储器都需要更换变量
        {
            value_min = array[index_move];
            index_min = index_move;
        }
    }
    return index_min;
}

int select_sort(int *array, int index_max)
{
    int i = 0;
    for (i = 0; i <= index_max; i++)//循环次数//2
    {
        int index_min = findmin(array, i, index_max);//找出 最小值 的下标
        if (i != index_min)//判断找出 最小值 的下标是否和起始下标 i 相等
        {
            int swap = array[i];//不相等就交换数值
            array[i] = array[index_min];
            array[index_min] = swap;
        }
    }
}
