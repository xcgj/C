#include <stdio.h>

int main()
{
    int arr[10] = { 2,34,7,6,432,27,6,9,45,76 };
    int i = 0;
    int j = 0;
    for (i = 0; i < 9; i++)
    {
        for (j = i + 1; j < 10; j++)
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
    }
    for (i = 0; i < 10; i++)
    {
        printf("%d\n", arr[i]);
    }
    return 0;
}

