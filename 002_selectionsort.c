
#include <stdio.h>
#include "./headers/tools.h"

// Time complexity will be O(n^2)
int selection_sort(int array[], int size){
    // invariant: array[index-1] is always sorted
    for (int i = 0; i < size-1; i++){
        int min = i;
        int index = i+1;
        // find the minimum index 
        while (index < size){
            // change the condition to (array[index] > array[min]) to get reverse sorted array
            if (array[index] < array[min]) min = index;
            index++;
        }
        int tmp = array[min];
        array[min] = array[i];
        array[i] = tmp;
    }

    return 0;
}

int main(){
    int brray[] = {6,8,7,3,5,4,9,2,1};
    selection_sort(brray,9);
    printArray(brray, 9);
}
