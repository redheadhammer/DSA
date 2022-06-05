
#include <stdio.h>
#include "./headers/tools.h"

int MERGE(int array[], int start, int newS, int end){
    int i=0, j=0, k=0;
    int L[newS-start];
    int R[end-newS];

    for (int i=0; i < (newS-start); i++){
        L[i] = array[start+i];
    }

    for (int i=0; i < (end-newS); i++){
        R[i] = array[newS+i];
    }


    // invariant: array[k] holds the smaller values of L[k] and R[k]
    // in sorted order.
    for (int k = start; k < end; k++){
        if (L[i] < R[j]){
            array[k] = L[i];
            i++;
        } else{
            array[k] = R[j];
            j++;
        }
    }


    while ((i < newS-start) && (j < end-newS)) {
        if (L[i] < R[j]){
            array[start+k] = L[i];
            i++;
        } else {
            array[start+k] = R[j];
            j++;
        }
        k++;
    }
    while (i < newS-start){
        array[start + k] = L[i];
        i++;
        k++;
    }

    while (j < end-newS){
        array[start + k] = R[j];
        j++;
        k++;
    }

    return 0;
}

int MERGESORT(int array[], int start, int end){
    if (end-start < 2){
        return 0;
    }
    int newS = (start+end)/2;
    MERGESORT(array, start, newS);
    MERGESORT(array, newS, end);
    MERGE(array, start, newS, end);
}

int merge(int A[], int sizeA, int B[], int sizeB, int array[]){
    int i = 0, j = 0, k = 0;

    while (i < sizeA && j < sizeB){
        if (A[i] < B[j]){
            array[k] = A[i];
            i++;
        } else {
            array[k] = B[j];
            j++;
        }
        k++;
    }
    while (i < sizeA){
        array[k] = A[i];
        i++;
        k++;
    }
    while (j < sizeB){
        array[k] = B[j];
        j++;
        k++;
    }

    return 0;
}

int mergeSort(int array[], int size){
    if (size < 2) return 0;
    int newS = size/2;

    int L[newS], R[size-newS];

    for (int i = 0; i < newS; i++){
        L[i] = array[i];
    }

    for (int i = 0; i < size-newS; i++){
        R[i] = array[newS+i];
    }

    mergeSort(L, newS);
    mergeSort(R, size-newS);
    merge(L, newS, R, size-newS, array);

    return 0;
}

int main(void)
{
    int array[] = {6,8,7,3,5,4,9,2,1};
    // 1st mergeSort where array is created in mergesort
    mergeSort(array, 9);
    puts("1st MergeSort");
    printA(array, 9);

    int brray[] = {6,8,7,3,5,4,9,2,1};
    // 2nd mergeSort where array is created in MERGE
    MERGESORT(brray, 0, 9);
    puts("2nd MergeSort");
    printA(brray, 9);
}



