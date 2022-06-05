
#include <stdio.h>
#include "./headers/tools.h"

// time complexity will be O(n^2)
int insertionSort(int array[], int size){
    // loop invariant: array[i] is always sorted.
    for (int i = 1; i < size; i++){
        int key = array[i];
        int index = i - 1;
        // change condition to (key > array[index] ..) for reversed values
        // lessons for me: always check value range i.e. for index here in loop
        while (key < array[index] && index >= 0){
            array[index + 1] = array[index];
            index--;
        }
        array[index + 1] = key;
    }
    return 0;
}

int main(){

    int array[] = {6,8,7,3,5,4,9,2,1};
    insertionSort(array,9);
    printArray(array, 9);

    return 0;
}

