#include <stdio.h>

int main(void)
{
    int i = 9;
    int arr[i] = {0};
    int j = 0;
    for (j = 0; j < 9;j++)
        printf("arr[%d] = %d\n", j, arr[j]);
    return 0;
}

