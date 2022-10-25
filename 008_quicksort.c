
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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


// worst case time complexity of quicksort will be O(n^2)
// and will occure when array is already in increasing order
// or all the elements in array are same. this can be
// avoided by selecting pivot randomly in partition function.
void quicksort(int *array, int start, int end)
{
    if (end-start > 1)
    {
        int index = partition(array, start, end);
        quicksort(array, start, index);
        quicksort(array, index+1, end);
    }
}

int random_part(int *array, int start, int end) {
    int rand_ind = (rand() % (end-start)) + start;
    swap(&array[end-1], &array[rand_ind]);
    return partition(array, start, end);
}

void random_qsort(int *array, int start, int end) {
    if (end-start > 0) {
        int ind = random_part(array, start, end);
        random_qsort(array, start, ind);
        random_qsort(array, ind+1, end);
    }
}

int hoare_partition(int *array, int start, int end) {
    int pivot = array[start];
    int i = start+1;
    int j = end-1;

    while(true) {
        // left pointer should have a value less
        // than pivot otherwise move left pointer
        while (array[i] <= pivot) {
            i++;
        }

        // right pointer should have a value more
        // than pivot otherwise move right pointer
        while (array[j] >= pivot) {
            j--;
        }

        if (i < j) {
            swap(&array[i], &array[j]);
        } else {
            swap(&array[i], &array[start]);
            return i;
        }
    }
}

int main(void)
{
    int array[] = {211, 184, 99, 155, 303, 192, 341, 235, 262, 119, 269, 228};
    random_qsort(array, 0, 12);
//    quicksort(array, 0, 12);
    for (int i = 0; i < 12; i++) printf("%d ", array[i]);

    puts(" ");
    return 0;
}
