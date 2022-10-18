
#include <stdio.h>
#include <stdlib.h>
#include "headers/tools.h"

// this algorithms takes linear time to sort a
// given array but for this array we need U_bound
// and L_bound so that we can count the occurence 
// of each element in the range
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
}

int main(void) {
    int array[] = {3,6,2,5,7,8,6,6,8,9};
    count_sort(array, 2, 9, 10);
    printArray(array, 10);
}
