
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME 20
#define SIZE 10

typedef struct {
    char name[NAME];
    int age;
} person;

unsigned int hash(char *name){
    int length = strnlen(name, NAME);
    unsigned int sum = 0;
    for (int i = 0; i < length; i++){
        sum += (name[i]);
        sum *= (name[i]);
    }
    return (sum)%SIZE;
}

int main(void){
    char *array[7] = {"Values", "Karma", "Verma", "Hell", "Hound", "Dark", "Killings"};

    for (int i = 0; i < 7; i++) printf("%s => %d\n", array[i], hash(array[i]));
    return 0;
}
