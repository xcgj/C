#include <stdio.h>

int main(void)
{
    int n = 0;
    printf("ÐÐÊý£º");
    scanf("%d", &n);
    int m = n;
    int i, j;
    int a[n][m];
    for (i = 0, j = 1; i < n; i++)
    {
        a[0][i] = j++;
        printf("%-10d", a[0][i]);
    }
    printf("\n");
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < m - i; j++)
        {
            a[i][j] = a[i - 1][j] + a[i - 1][j + 1];
            printf("%-10d", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}

