
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int bin_search (int *array, int size, int target){
    // edge case when there is only 1 element in array
    if (size == 1 && array[0] == target) return 0;
    else if (size == 1) return -1;

    // case if target is smaller than 0th element in array or it is greater than greatest element in array.
    if (array[size-1] < target || array[0] > target) return -1;

    int left = 0, mid;
    int right = size-1;

    while (left <= right) {
        mid = (left+right)>>1;
        if (array[mid] < target) left = mid+1;
        else if (array[mid] == target) return mid;
        else right = mid-1;
    }
    return (array[mid] == target)? mid :-1;
}


int main(void) {
    int array[] = {1, 5, 6, 14, 16, 20, 24};
    qsort(array, 7, sizeof(int), cmp); // {-13, -11, -9, -6, -5, -4, -3, -2}
    printf("%d\n", bin_search(array, 7 , 15));  // should return -1
    int brray[] = {-2, -9, -11, -4, -6, -5, -3, -13, -31};
    qsort(brray, 9, sizeof(int), cmp); // {-31, -13, -11, -9, -6, -5, -4, -3, -2}
    printf("%d\n", bin_search(brray, 9 , -4)); // should return 6

    return 0;
}
