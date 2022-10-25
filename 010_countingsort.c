
#include <stdio.h>
#include <stdlib.h>
#include "headers/tools.h"

// this algorithms takes linear time to sort a
// given array but for this array we need U_bound
// and L_bound so that we can count the occurence 
// of each element in the range
// In this version of countsort we don't use extra
// space for saving the resulting array.
void count_sort(int *array, int lower_bound, int upper_bound, int size) {
    int *count = malloc(sizeof(*count)*(upper_bound - lower_bound+1));
    // save the count of all the element in count array.
    for (int i = 0; i < size; i++) {
        int index = array[i] - lower_bound;
        count[index] += 1;
    }
    
    int ind = 0;
    
    // start filling the array with values.
    for (int i = 0; i < size; i++) {
        // if count[ind] is 0 than increase the ind.
        while (count[ind] == 0) ind++; 
        array[i] = ind + lower_bound;
        count[ind] -= 1;
    }

    free(count);
}

// another count sort. To make things easy
// we will assume lower bound for elements 
// to be 0.
int* count_sort2(int *array, int upper_bound, int size) {
    int *result = malloc(sizeof(*result) * size);
    int *count = malloc(sizeof(*count) * upper_bound + 1);
    // count the number of occurences of elements of array
    for (int i = 0; i < size; i++) {
        count[array[i]] += 1;
    }

    // get output indeces of resulting array.
    for (int i = 1; i <= upper_bound; i++) {
        count[i] += count[i-1];
    }
    printf("Element indeces:- \n");
    printArray(count, 10);

    // place the elements in result array.
    for (int i = size-1; i >= 0; i--) {
        result[count[array[i]] - 1] = array[i];
        // if array has some values repeating more than once,
        // reducing the resulting index will place the element
        // at the previous index.
        count[array[i]] -= 1;
    }

    free(count);
    return result;
}

int main(void) {
    int array[] = {3,6,2,5,7,8,6,6,8,9};
    printArray(array, 10);
    int *hold = malloc(sizeof(int) * 10);
    hold = count_sort2(array, 9, 10);
    printArray(hold, 10);
    count_sort(array, 2, 9, 10);
    printArray(array, 10);
    return 0;
}
