// Implementation of a HEAP
// A heap basically is just an array with values order in a very specific way
// like a binray tree (heap is used to create priority queues)

// TO CALCULATE A PARENT OR CHILD USE BELOW CODE FOR 0 INDEXED ARRAY
// PARENT = floor(i/2)-1
// LEFT CHILD = (2i+1)
// RIGHT CHILD = (2i+2)

// MAX-HEAP always follows the Max-heap property that is A[PARENT(i)] >= A[i]
// MIN-HEAP always follows the Min-heap property that is A[PARENT(i)] <= A[i]

// MINIMUN AND MAXIMUM ELEMENTS IN A HEAP OF HEIGHT h is 2^h - 2^(h+1)-1
// non-leaf nodes range : 0 to floor(n/2)-1
// leaf nodes range : floor(n/2) to n-1

// most nodes at a certain level: ceil(n/2^(h+1)) h is height


#include <stdio.h>
#include "headers/tools.h"


// Array -> Heap(using heapify) -> heapSort

int HEAP_SIZE;

// time complexity for this recursive approach is O(log(n)) and space complexity is O(log(n))
void max_heapify(int *array, int node)
{
    int left = (node<<1)+1;
    int right = left + 1;
    int maximum = node;

    // check if there exist a left child and set larger element
    if (left < HEAP_SIZE && array[left] > array[node])
        maximum = left;

    // check if there exist a right child and set larger element
    if (right < HEAP_SIZE && array[right] > array[maximum])
        maximum = right;

    // recurse if parent is not the largest element
    if (maximum != node)
    {
        // swap node with largest element
        int tmp = array[node];
        array[node] = array[maximum];
        array[maximum] = tmp;
        max_heapify(array, maximum);
    }
}

void min_heapify(int *array, int node)
{
    // set right and left node
    int left = (node << 1) + 1;
    int right = left + 1;
    int smallest;

    // check if left child exist, than set the smallest element
    if (left < HEAP_SIZE && array[left] < array[node])
        smallest = left;
    else
        smallest = node;

    // check if right child exist, than set the smallest element
    if (right < HEAP_SIZE && array[right] < array[smallest])
        smallest = right;

    if (node != smallest)
    {
        // swap the smallest element with node
        int tmp = array[node];
        array[node] = array[smallest];
        array[smallest] = tmp;
        min_heapify(array, smallest);
    }
}


void MAX_HEAPIFY(int *array, int node)
{
    do {
        int left = (node << 1)+1;
        int right = left + 1;
        int largest = node;
        
        if (left < HEAP_SIZE && array[left] > array[node])
            largest = left;

        if (right < HEAP_SIZE && array[right] > array[largest])
            largest = right;

        if (node != largest)
        {
            int tmp = array[node];
            array[node] = array[largest];
            array[largest] = tmp;
            node = largest;
        } else 
            break;

    } while (node < (HEAP_SIZE>>1));
}

// heapify can be used in bottom up manner to create a heap
// average time complexity for build_max_heap is O(n) (linear time)
void build_max_heap(int *array, int size)
{
    // LOOP INVARIANT: i+1, i+2 .... n are already root of a max-heap
    for (int i = (size-1)>>1; i >= 0; i--)
        max_heapify(array, i);
}

void build_min_heap(int *array, int size)
{
    // LOOP INVARIANT: i+1, i+2 .... n are already root of a min-heap
    for (int i = (size-1)>>1; i >= 0; i--)
    {
        min_heapify(array, i);
    }
}


void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// to get the values in decreasing order replace build_max_heap with build_min_heap
// than replace max_heapify with min_heapify in for loop
void heapsort(int *array, int size)
{
    HEAP_SIZE = size;
    build_max_heap(array, size);
    // LOOP INVARIANT: Array[0 to i] is a max heap and Array[i+1 to n] 
    // is already sorted and contains n-(i+1) largest elements from Array
    for (int i = size-1; i >= 1; i--)
    {
        swap(array, &array[i]);
        HEAP_SIZE -= 1;
        max_heapify(array, 0);
    }
}

int main(void)
{
    int array[] = {59, 10, 64, 82, 103, 45, 31, 92, 81, 61};
    heapsort(array, 10);
    printArray(array, 10);
}
