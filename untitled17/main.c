#include <stdio.h>
#include <stdlib.h>

int main(int argc, int **argv)
{
    if (argc < 2)
    {

    }
    int i = 0;
    int sum = 0;
    for (i = 1; i < argc - 1; i++)
    {
        sum += atoi(argv);
    }
    printf("Hello World!\n");
    return 0;
}

