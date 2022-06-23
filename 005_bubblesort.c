
#include <stdio.h>
#include <stdlib.h>

#include "headers/tools.h"


// This will take overall time complexity of O(n^2)
int bubblesort(int array[], int size)
{
    // this loop is just a wrapper for iterating each element
    for (int i = 0; i < size; i++) 
    {
        // this loop will be used to make swap for the 1st iteration
        // LOOP INVARIANT: array[i] will always be sorted
        for (int j = size-1; j > i; j--)
        {
            // swap if array[j] is smaller than array[j-1]
            if (array[j] < array[j-1])
            {
                int tmp = array[j];
                array[j] = array[j-1];
                array[j-1] = tmp;
            }
        }
    }
    return 0;
}

int main(void)
{
    int array[] = {123,54,6,54,31,9,27,19};
    bubblesort(array, 8);
    printArray(array, 8);
}
