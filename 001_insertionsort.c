
#include <stdio.h>
#include "./headers/tools.h"

// Recursive insertionSort
void insertionsort(int array[], int size) {
    // base condition
    if (size <= 1) return;

    // dividing the array by recursive calls
    insertionsort(array, size-1); // give n-1 total calls

    // Solving the recursion relation
    int key = array[size-1];
    int index = size-2;
    // inserting the element
    while (index >= 0 && array[index] > key) {
        array[index+1] = array[index];
        index--;
    }
    array[index+1] = key;
}


// time complexity will be O(n^2)
int insertionSort(int array[], int size){
    // loop invariant: array[i] is always sorted.
    for (int i = 1; i < size; i++){
        int key = array[i];
        int index = i - 1;
        // change condition to (key > array[index] ..) for reversed values
        // lessons for me: always check value range (for overflows)
        while (key < array[index] && index >= 0){
            array[index + 1] = array[index];
            index--;
        }
        array[index + 1] = key;
    }
    return 0;
}

// over-all time complexity of this algorithm is O(logn)
int bin_search (int *array, int size, int target){

    int left = 0, mid;
    int right = size-1;

    while (left <= right) {
        mid = (left+right)>>1;
        if (array[mid] < target) left = mid+1;
        else if (array[mid] == target) return mid;
        else right = mid-1;
    }
    
    return (array[mid] == target)? mid : left;
}

// This insertionsort uses binary search so it will take less time as compared with forms of insertionSort
int insertionSORT(int array[], int size){
    int index, j, key;
    for (int i = 1; i < size; i++)
    {
        key = array[i];
        index = bin_search(array, i, array[i]);
        j = i-1;
        while (j >= index) 
        {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }

    return 0;
}

int main(){

    int array[] = {6,8,7,3,5,4,9,2,1};
    insertionSORT(array, 9);
//    insertionSort(array,9);
    printArray(array, 9);

    return 0;
}

