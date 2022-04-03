
#include <stdio.h>



int selection_sort(int array[], int size){
    // invariant: array[index-1] is always sorted
    for (int i = 0; i < size-1; i++){
        int min = i;
        int index = i+1;
        while (index < size){
            if (array[index] < array[min]) min = index;
            index++;
        }
        int tmp = array[min];
        array[min] = array[i];
        array[i] = tmp;
    }
    return 0;
}

void print(int array[],int size){
    for (int i = 0; i< size; i++){
        printf("%d ", array[i]);
    }
    puts("");
}

int main(){
    int brray[] = {6,8,7,3,5,4,9,2,1};
    selection_sort(brray,9);
    print(brray, 9);
}
