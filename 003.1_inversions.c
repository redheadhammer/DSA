
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int merge(int *array, int start, int mid, int end) {
    int *arrayL = malloc(sizeof(*arrayL) * (mid-start+1));
    int *arrayR = malloc(sizeof(*arrayR) * (end-mid+1));

    arrayL = memcpy(arrayL, &array[start], sizeof(*arrayL)*mid);
    arrayR = memcpy(arrayR, &array[mid], sizeof(*arrayR)*(end-mid));
    arrayL[mid-start] = INT_MAX;
    arrayR[end-mid] = INT_MAX;

    int count = 0;
    int indexL = 0, indexR = 0;
    for (int i = start; i < end; i++) {
        if (arrayL[indexL] <= arrayR[indexR]) {
            array[i] = arrayL[indexL++];
        } else {
            array[i] = arrayR[indexR++];
            if (arrayL[indexL] != INT_MAX)
                count += mid - start - indexL;
        }
    }

    return count;
}


int mergesort(int *array, int start, int end) {
    int count = 0;
    if (end-start == 1) return 0;

    int mid = (start+end)>>1;
    count += mergesort(array, start, mid);
    count += mergesort(array, mid, end);
    count += merge(array, start, mid ,end);
    return count;
}

int main(void) {
    int array[] = {2,3,8,6,1};  // 5
    printf("%d\n", mergesort(array, 0, 5));

    int brray[] = {8,4,2,1};    // 6
    printf("%d\n", mergesort(brray, 0, 4));

    int crray[] = {1,20,6,4,5};  // 5
    printf("%d\n", mergesort(crray, 0, 5));
}
