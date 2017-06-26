#include <stdio.h>

void ergodic_1(int *a, int n)
{
    int i = 0;
    for (i = 0; i < n; i++)
        printf ("arr[%d] = %d\n", i, a[i]);
    printf ("--------------\n");
}

void ergodic_2(int *a, int n)
{
    int i = 0;
    int *p = a;
    for (i = 0; i < n; i++)
        printf ("arr[%d] = %d\n", i, p[i]);
    printf ("--------------\n");
}

void ergodic_3(int *a, int n)
{
    int i = 0;
    int *p = a;
    for (i = 0; i < n; i++)
    {
        printf ("arr[%d] = %d\n", i, *p);
        p++;
    }
    printf ("--------------\n");
}

void ergodic_4(int *a, int n)
{
    int i = 0;
    for (i = 0; i < n; i++)
        printf ("arr[%d] = %d\n", i, *(a + i));
    printf ("--------------\n");
}

int main(void)
{
    int arr[] = {10,20,30,40,50,60,70,80,90,100};
    int i = sizeof(arr) / sizeof (int);
    ergodic_1(arr, i);
    ergodic_2(arr, i);
    ergodic_3(arr, i);
    ergodic_4(arr, i);
    return 0;
}

