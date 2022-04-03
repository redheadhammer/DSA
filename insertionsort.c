
#include <stdio.h>

#define debug(M,...) fprintf(stderr, "[DEBUG] %s:%d:%s:  " M "\n", __FILE__, __LINE__, __FUNCTION__);

// Time complexity: B-> O(n), A-> O(n^2), W-> O(n^2)

void print(int array[],int size){
    for (int i = 0; i< size; i++){
        printf("%d ", array[i]);
    }
    puts("");
}

int insertionsort(int array[], int size){
    for (int i = 0; i < size-1; i++){
        for (int j = i+1; j < size; j++){
            if (array[i] > array[j]){
                int tmp = array[j];
                array[j] = array[i];
                array[i] = tmp;
            }
        }
    }
    return 0;
}



int insertion(int array[], int size){
    // loop invariant: array[i] is always sorted.
    for (int i = 1; i < size; i++){
        int key = array[i];
        int index = i - 1;
        while (key > array[index] && index >= 0){
            array[index + 1] = array[index];
            index--;
        }
        array[index + 1] = key;
    }
    return 0;
}

int main(){

    int array[] = {6,8,7,3,5,4,9,2,1};
    insertion(array,9);

    int brray[] = {6,8,7,3,5,4,9,2,1};
    insertionsort(brray,9);
    print(array, 9);

    return 0;
}

