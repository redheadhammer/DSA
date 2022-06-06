
#include <stdio.h>
#include <stdlib.h>

#include "./headers/tools.h"

int merge(int* arrayL, int sizeL, int* arrayR, int sizeR, int* array){
    int indexL = 0, indexR = 0;
    
    // add sorted elements from both array to main array
    // loop invariant: array[indexL+indexR] will always be sorted and will hold 
    // true for all the 3 while loops below
    while (indexL < sizeL && indexR < sizeR) {
        if (arrayL[indexL] < arrayR[indexR]) {
            array[indexL+indexR] = arrayL[indexL];
            indexL++;
        } else {
            array[indexL + indexR] = arrayR[indexR];
            indexR++;
            }
    }

    // add remaining elements from Left array to main array
    while (indexL < sizeL) {
        array[indexL+indexR] = arrayL[indexL];
        indexL ++;
    }

    // add remaining elements from Right array to main array
    while (indexR < sizeR) {
        array[indexL+indexR] = arrayR[indexR];
        indexR++;
    }

    // free memory allocated for both left and right arrays
    if (arrayL) free(arrayL);
    if (arrayR) free(arrayR);

    return 0;
}

int mergeSort(int *array, int size){
    // break if below condition is true
    if (size < 2) return 0;
    
    // calculate the mid point
    int mid = size >> 1;

    // create left and right array
    int *arrayL = malloc(mid * sizeof(*arrayL));
    int *arrayR = malloc((size-mid) * sizeof(*arrayR));

    // fill both arrays
    for (int i = 0; i < mid; i++) {
        arrayL[i] = array[i];
    }

    for (int i = 0; i < (size-mid); i++) {
        arrayR[i] = array[mid+i];
    }

    //give recursive call to mergeSort function
    mergeSort(arrayL, mid);
    mergeSort(arrayR, (size-mid));
    merge(arrayL, mid, arrayR, (size-mid), array);

    return 0;
}

int MERGE(int *array, int start, int mid, int end) {
    int *arrayL = malloc(sizeof(*arrayL) * (mid-start));
    int *arrayR = malloc(sizeof(*arrayR) * (end-mid));

    // fill left array
    for (int i = 0; i < (mid-start); i++) {
        arrayL[i] = array[start+i];
    }
    

    // fill right array
    for (int i = 0; i < (end-mid); i++) {
        arrayR[i] = array[mid+i];
    }

    int indexR = 0, indexL = 0;
    
    // fill array with sorted values from arrayR and arrayL
    // loop invariant: array[start+indexL+indexR] will always be sorted and will hold 
    // true for all the 3 while loops below
    while (indexL < (mid-start) && indexR < end-mid) {
        if (arrayL[indexL] < arrayR[indexR]) {
            array[start + indexL + indexR] = arrayL[indexL];
            indexL++;
        }
        else {
            array[start + indexR + indexL] = arrayR[indexR];
            indexR++;
        }
    }


    // fill remaining elements of arrayL to main array
    while (indexL < (mid-start)) {
        array[start+indexL+indexR] = arrayL[indexL];
        indexL++;
    }

    // fill remaining elements of arrayR to main array
    while (indexR < (end-mid)) {
        array[start+indexL+indexR] = arrayR[indexR];
        indexR++;
    }

    return 0;
}

int MERGESORT(int *array, int start, int end) {
    if ((end - start) < 2) return 0;

    int mid = (start + end) >> 1;

    MERGESORT(array, start, mid);
    MERGESORT(array, mid, end);
    MERGE(array, start, mid, end);

    return 0;
}

int main(void)
{
    int array[] = {8,6,7,4,3,5,9,2,1}; // size 9
    int brray[] = {47,63,64,75,42,8,1}; // size 7 
                                        //
    // 1st mergeSort where array is created in mergesort
    mergeSort(array, 9);
    puts("1st MergeSort");
    printArray(array, 9);


    // 2nd MergeSort where array is created in merge function 
    MERGESORT(brray, 0, 7);
    puts("2nd MergeSort");
    printArray(brray, 7);
}
