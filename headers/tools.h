#ifndef __print_h__
#define __print_h__

#include <stdio.h>

void printA(int array[],int size){
    for (int i = 0; i< size; i++){
        printf("%d ", array[i]);
    }
    puts("");
}

#endif
