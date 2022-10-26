
#include <stdlib.h>
#include <limits.h>
#include "./headers/tools.h"

/* 1. Add an element to stack
 * 2. Overflow when adding to stack when all the places are filled
 * 3. Underflow when stack is empty but we try to remove element
 * 4. peek to show the element on stack top
 * 5. check if stack is empty
 */

// global variables to be accessed later
#define STACK_LENGTH 10

int stack[STACK_LENGTH];
int cur = 0;

int push(int ele) {
    if (cur == STACK_LENGTH) {
        printf("Overflow: Stack already full\n");
        return -1;
    }
    stack[cur] = ele;
    cur++;
    return 0;
} 

int isempty(void) {
    return cur == 0;
}

int peek(void) {
    if (isempty()) {
        printf("Underflow: Stack is empty\n");
        return INT_MIN;
    }
    return stack[cur-1];
}

int pop(void) {
    if (isempty()) {
        printf("Underflow: Stack is empty\n");
        return INT_MIN;
    }
    return stack[cur--];
}

void printstack(void) {
    printArray(stack, cur);
}

int main(void) {
    pop();
    push(12);
    push(22);
    printstack();
    pop();
    printstack();
    push(12);
    push(61);
    push(19);
    push(92);
    printstack();
}
