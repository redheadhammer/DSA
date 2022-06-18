
#include <stdio.h>
#include <stdlib.h>

// Recursive version of binary_search
int binary_search(int *array, int start, int end, int target) {
    if (start >= end) {
        return -1;
    }

    int mid = (start+end)>>1;
    if (array[mid] < target) {
        return binary_search(array, mid+1, end, target);
    } else if (array[mid] == target) return mid;
    else {
        return binary_search(array, start, mid-1, target);
    }
}

// over-all time complexity of this algorithm is O(logn)
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
    
    // both below condition will only work when target element is not present in the array
    // right will return the index of the element which is just less than the target element
    // left will return the index of the element which is just greater than target element
    return (array[mid] == target)? mid :-1;
}

// compare function to be used for sorting the array itself
int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main(void) {
    int array[] = {1, 5, 6, 14, 16, 20, 24};
    qsort(array, 7, sizeof(int), cmp); // {-13, -11, -9, -6, -5, -4, -3, -2}
    // binary_search with a while loop
    printf("%d\n", binary_search(array, 0, 7 , 15));  // should return -1

    int brray[] = {-2, -9, -11, -4, 90, -6, -5, -3, -13, -31};
    qsort(brray, 10, sizeof(int), cmp); // {-31, -13, -11, -9, -6, -5, -4, -3, -2, 90}
    // recursive binary search
    printf("%d\n", binary_search(brray,0, 10 , -4)); // should return 6
    

    return 0;
}
