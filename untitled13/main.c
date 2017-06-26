#include <stdio.h>
void sort(int *a, int i)
{
    if (i <= 1)
        printf("最小的值为%d\n第二小的值为%d\n", a[0], a[0]);
    else
    {
        int min = (a[0] < a[1]) ? a[0] : a[1];
        int smin = (a[0] > a[1]) ? a[0] : a[1];
        int j = 0;
        for (j = 2; j < i; j++)
        {
            if (min > a[j])
            {
                smin = min;
                min = a[j];
            }
            else if (smin > a[j])
            {
                smin = a[j];
            }
        }
        printf("最小的值为%d\n第二小的值为%d\n", min, smin);
    }
}

int main(void)
{
    int n = 0;
    int i = 0;
    printf("请输入n的值:");
    scanf("%d", &n);
    int array[n];
    printf("请输入%d个整数:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &array[i]);
    sort(array, n);
    return 0;
}
