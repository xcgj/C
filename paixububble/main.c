#include <stdio.h>

int main(void)
{
    int a[10] = {25,6,7,2,23,1,98,65,34,21};
    int i = 0;
    int j = 0;
    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < (9 - i); j++)
        {
            if(a[j] > a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    for(i = 0; i < 10; i++)
        printf("a[%d] = %d\n", i, a[i]);
    return 0;
}

