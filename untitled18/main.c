#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int * all(int * a, int b);
int main(){
    int a[5] = { 124,86,11,6,4 };
    int * b = all(a, 5);
    printf("max=%d\nmin=%d\nave=%d\nsum=%d\n", *b, *(b + 1), *(b + 2), *(b + 3));
    return 0;
}
int * all(int * a, int b)
{
    int max, min;
    int count;
    int ave;
    int sum=0;
    for (count = 1; count < b; count++)
    {
        if (a[0] < a[count])
        {
            max = a[0];
            a[0] = a[count];
            a[count] = max;
        }
        max = a[0];
    }
    for (count = 1; count < b; count++)
    {
        if (a[0] > a[count])
        {
            min = a[0];
            a[0] = a[count];
            a[count] = min;
        }
        min = a[0];
    }
    for (count = 0; count < 5; count++)
        sum += a[count];
    ave = sum / b;
    int c[4] = { max,min,ave,sum };
    int * p = c;
    return p;
}
