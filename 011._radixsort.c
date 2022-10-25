
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "headers/tools.h"


// [17,3,6,7,21,5]

void countsort(int *array, int size, int div) {
    // array for values 0-9
    int *indeces = malloc(sizeof(*indeces) * 10);
    // array to store tmp res
    int *res = malloc(sizeof(*res) * size); 

    for (int i = 0; i < size; i++) {
        int index = (array[i] / div) % (div * 10);
        indeces[index] += 1;
    }

    for (int i = 1; i < 10; i++) {
        indeces[i] += indeces[i-1];
    }

    // place all the elements at right indeces
    for (int i = size-1; i >= 0; i--) {
        int index = (array[i] / div) % (10 * div);
        res[indeces[index]-1] = array[i];
        indeces[index] -= 1;
    }

    // fill all the values from result to actual array
    for (int i = 0; i < size; i++) {
        array[i] = res[i];
    }

    free(indeces);
    free(res);
}

void radixsort(int* array, int size, int max_dec) {
    for (int i = 0; i < max_dec; i++) {
        countsort(array, size, pow(10, i));
    } 
}

int main(void) {
    int array[] = {43,65,12,2,23, 12,35};
    radixsort(array, 7, 2);
    printArray(array, 7);
}
