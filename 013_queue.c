
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

#define SIZE 4

/*
 * 1. enqueue: adding elements to queue
 * 2. dequeue: removing elements from start
 * 3. pop: to remove element from end of queue
 * 4. isempty
 * 5. front: will return the element at front of the queue
 */


int head = -1;
int tail = -1;
int queue[SIZE];


int enqueue(int ele) {
    if (head == (tail + 1) % SIZE) {
        printf("Overflow: Queue is already full\n");
        return INT_MIN;
    }

    if (head == -1) head = 0;
    ++tail;
    tail %= SIZE;
    queue[tail] = ele;
    return 0;
}

int dequeue(void) {
    if (head == -1 && tail == -1) {
        printf("Underflow: Queue is empty\n");
        return -1;
    }
    int val = queue[head];
    if (head == tail) {
        head = -1;
        tail = -1;
    } else {
        ++head;
        head %= SIZE;
    }
    return val;
}

int isempty(void) {
    return head == -1 && tail == -1;
}

int pop(void) {
    if (isempty()) {
        printf("queue is already empty\n");
        return INT_MIN;
    }
    if (tail == -1) {
        tail = SIZE-1;
    } 
    return queue[tail--];
}

int front(void) {
    return queue[head];
}

void printqueue(void) {
    int t = tail, h = head;
    while (h != t) {
        printf("%d ", queue[h++]);
        if (h == SIZE) h = 0;
    }
    printf("%d\n", queue[h]);
}

int main(void) {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    dequeue();
    enqueue(3);
    enqueue(5);
    printqueue();
    dequeue();
    printqueue();
    enqueue(4);
    printqueue();
    return 0;
}
