
#include <stdio.h>
#include <stdlib.h>

// INSERT(S,x), MAXIMUM(S) -> return maximum value in priority queue
// EXTRACT-MAX(S) remove and returns the element with largest key
// INCREASE-KEY(S,x,k) update the key from x to k 

int QUEUE_SIZE = 0;
int ARRAY_SIZE = 0;

// function to swap values
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// max-heapify
void max_heapify(int *array, int index)
{
    int left = (index<<1) + 1;
    int right = left+1;
    int largest = index;

    if (left < QUEUE_SIZE && array[left] > array[index])
        largest = left;

    if (right < QUEUE_SIZE && array[right] > array[largest])
        largest = right;

    if (index != largest)
    {
        swap(&array[index], &array[largest]);
        max_heapify(array, largest);
    }
}

int build_max_heap(int *array, int size, int queue_size)
{
    if (queue_size > size)
    {
        printf("ERROR: queue_size is greater than array size\n");
        return EXIT_FAILURE;
    }

    // set current queue size and available array space
    ARRAY_SIZE = size;
    QUEUE_SIZE = queue_size;

    for (int i = (size>>1)-1; i >= 0; i--)
        max_heapify(array, i);

    return 0;
}

// check the largest element in the heap
int heap_maximum(int *array)
{
    return array[0];
}

// extract max-element from the heap
int extract_max(int *array)
{
    // check if heap has enough values
    if (QUEUE_SIZE < 1)
    {
        printf("Heap doesn't have enough values");
        return EXIT_FAILURE;
    }

    swap(array, &array[QUEUE_SIZE-1]);
    QUEUE_SIZE -= 1;
    max_heapify(array, 0);

    return array[QUEUE_SIZE];
}

// insert will take 
int insert(int *array, int value)
{
    if (QUEUE_SIZE >= ARRAY_SIZE)
    {
        // realloc can also be used to create a dynamic array instead of returning error.
        printf("ERROR: There is not enough space available for a new entry\n");
        return EXIT_FAILURE;
    }

    array[QUEUE_SIZE] = value;
    int index = QUEUE_SIZE;
    int parent = (QUEUE_SIZE-1)>>1;

    // check if inserted element is smaller than parent element if not swap 
    // the parent element and keep doing it until found right place 
    while (array[parent] < array[index])
    {
        swap(&array[parent], &array[index]);
        index = parent;
        parent = (index-1)>>1;
    }

    QUEUE_SIZE++;

    return 0;
}

int main(void)
{
    int array[15] = {233, 517, 233, 163, 464, 516, 215, 354, 293, 107, 322};
    build_max_heap(array, 15, 11);

    return 0;
}


