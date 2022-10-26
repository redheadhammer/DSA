
#include <stdio.h>
#include <stdlib.h>

/*
 * 1. create node: to create a node with given value
 * 2. length: to get the length of the list
 * 3. printlist: to print the linked list.
 * 4. inserthead: insert an element at head.
 * 5. searchnode: search for a node in list.
 * 6. delete a node from linked list
 */


struct node {
    int value;
    struct node *next;
};

typedef struct node Node;

unsigned length = 0;

Node* create(int k) {
    length++;
    Node *mNode = malloc(sizeof(Node));
    mNode->value = k;
    mNode->next = NULL;
    return mNode;
}

Node* inserthead(Node **h, int val) {
    Node *mNode = create(val);
    mNode->next = *h;
    *h = mNode;
    length++;
    return mNode;
}

Node *findnode(Node *h, int val) {
    Node *tmp = h;
    while (tmp != NULL) {
        if (tmp->value == val) return tmp;
        tmp = tmp->next;
    }
    return NULL;
}

// not handled if val belong to tail
int delete(Node** head, int val) {
    // if we are removing head
    if ((*head)->value == val) {
        Node *tmp = (*head)->next;
        *head = tmp;
        return 0;
    }

    if ((*head)->next == NULL) {
        printf("Value not found\n");
        return -1;
    }
    Node *cur = *head;
    Node *next = (*head)->next;

    while (next != NULL && next->value != val) {
        cur = next;
        next = next->next;
    }

    if (next == NULL) {
        printf("Value not found\n");
        return -1;
    }

    cur->next = next->next;
    return 0;
}

void printlist(Node *head) {
    Node *tmp = head;
    while (tmp != NULL) {
        printf("%d ", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
}

int main(void) {
    Node *head = create(100);
    Node *tail = head;
    for (int i = 1; i < 25; i++) {
        Node *tmp = create(i);
        tail->next = tmp;
        tail = tail->next;
    }
    inserthead(&head, 999);
    printlist(head);
    Node* search = findnode(head, 23);
    printf("%d \n", search->value);

    delete(&head, 5);
    printlist(head);
    delete(&head, 999);
    printlist(head);
    delete(&head, 23);
    printlist(head);
}
