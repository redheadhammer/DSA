
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "./headers/tools.h"

#define SIZE 11

int linearprobe(int key, int probeval) {
    return (key + probeval) % SIZE;
}

int quadraticprobe(int key, int probeval) {
    return (key + (int)pow(probeval, 2)) % SIZE;
}

// double hash function
int doublehashing(int key) {
    return 8 - (key % 8);
}

// hashfunction for double hashing
int hashfunction0(int *T, int key) {
    int index = key % SIZE; // SIZE and value in doublehashing should
                            // be prime with respect to each 
                            // for example we are using 8, 11 here.
    int probe = 0;
    while (T[index] != 0) {
        probe++;
        index = (probe * doublehashing(key)) % SIZE;
    }

    return index;
}

int hashfunction(int* T, int key) {
    int index = key % SIZE;
    int probe = 0;
    while (T[index] != 0) {
        probe++;
        // one can use linearprobe or quadraticprobe below.
        index = linearprobe(key, probe);
    }

    T[index] = key;
    return index;
}

int main(void) {
}

