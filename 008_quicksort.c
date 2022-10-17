
#include <stdio.h>
#include <stdlib.h>


// it works by putting every element
// at its right position from call
// to partition function.
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// partition the array in a way so that every element
// right of pivot element will be greater than pivot
// and elements left of pivot will always be smaller
// than pivot element.
int partition(int *array, int start, int end)
{
    // fill will keep track of the element greater than
    // the pivot element so that it can be replaced later
    int fill = start;
    int pivot = array[end-1];

    // invariant: if i == fill -> array[i] < pivot
    // if i > fill -> array[fill] > pivot
    for (int i = start; i < end-1; i++)
    {
        if (array[i] < pivot) 
        {
            swap(&array[i], &array[fill]);
            fill += 1;
        }
    }
    swap(&array[fill], &array[end-1]);

    return fill;
}

void quicksort(int *array, int start, int end)
{
    if (end-start > 1)
    {
        int index = partition(array, start, end);
        quicksort(array, start, index);
        quicksort(array, index+1, end);
    }
}

int main(void)
{
    int array[] = {211, 184, 99, 155, 303, 192, 341, 235, 262, 119, 269, 228};
    quicksort(array, 0, 12);
    for (int i = 0; i < 12; i++) printf("%d ", array[i]);

    puts(" ");
    return 0;
}
