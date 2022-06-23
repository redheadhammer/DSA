
#include <stdio.h>
#include "headers/tools.h"
#include <stdlib.h>

int* factors(int value)
{
    int *values = malloc(sizeof(int)*100); 
    values[0] = 1;
    int index = 1;
    for (int i = 2; i*i < value; i++)
    {
        if (value % i == 0)
        {
            values[index++] = i;
            if (i != (value/i))
            {
                values[index++] = (value/i);
            }
        }
    }
    return values;
}

int main(void)
{
    int value = 22;
    int *array = factors(value);
    printArray(array, 10);
}
