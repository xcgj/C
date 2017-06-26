#include <stdio.h>

int dichotomy(int *array, int length, int search)
{
    //将数组下标一半一半进行查找
    //可用 (最大下标+最小下标)/2 定位到中间的下表(和是奇数就定位到中间偏前一位)
    //比较中间下标对应的数和要找的数的大小
    //根据结果将中间下标的值赋值给最大或者最小下标
    //直到最大下标和最小下标相等（最大下标<最小下标也行）
    int index_min = 0;
    int index_max = length - 1;
    while(index_min <= index_max)
    {
        int index_middle = (index_min + index_max) / 2;
        if (search == array[index_middle])
            return index_middle;
        else if (search > array[index_middle])
            index_min = index_middle + 1;//一定要注意加减1否则死循环
            //array[index_middle]已经比较过，放心加减1
        else
            index_max = index_middle - 1;
    }
    return -1;//没找到，返回-1
}

int main(void)
{
    int array[10] = { 12, 23, 35, 45, 46, 56, 59, 60, 65, 90 };
    int index_find = dichotomy(array, 10, 1);
    printf("%d\n", index_find);
    return 0;
}

