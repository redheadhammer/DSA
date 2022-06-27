
#include <stdio.h>
#include "headers/tools.h"
#include <stdlib.h>

int factors(int value)
{
    for (int i = 1; i*i <= value; i++)
    {
        if (value % i == 0)
        {
            printf("%d ", i);
            if (i != (value/i))
                printf("%d ", (value/i));
        }
    }
    printf("\n");
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("USAGE: ./factors <integer value>");
        return 1;
    }

    int value;
    if (sscanf(argv[1], "%d", &value) == EOF) return 1;
    factors(value);

    return 0;
}
