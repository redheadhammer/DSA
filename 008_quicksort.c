
#include <stdio.h>
#include <stdlib.h>


void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int *array, int start, int end)
{
    int fill = start-1;
    int pivot = array[end-1];
    for (int i = start; i < end-1; i++)
    {
        if (array[i] < pivot) 
        {
            fill += 1;
            swap(&array[i], &array[fill]);
        }
    }
    swap(&array[fill+1], &array[end-1]);

    return fill+1;
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
