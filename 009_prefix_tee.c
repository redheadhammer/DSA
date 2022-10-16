
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define CHARS 256

typedef struct trienode {
    struct trienode *children[CHARS];
    bool isword;
} trienode;

trienode *createnode() {
    trienode *newnode = malloc(sizeof(*newnode));

    // set all the nodes to NULL
    for (unsigned i = 0; i < CHARS; i++) {
        newnode->children[i] = NULL;
    }

    newnode->isword = false;

    return newnode;
}

bool insert(trienode **root, char *string) {
    if (*root == NULL) {
        *root = createnode();
    }

    trienode *tmp = *root;

    unsigned length = strlen(string);
    for (unsigned i = 0; i < length; i++) {
        if (tmp->children[(int)string[i]] == NULL) {
            tmp->children[(int)string[i]] = createnode();
        }
        tmp = tmp->children[(int)string[i]];
    }

    if (tmp->isword) {
        return false;
    } else {
        tmp->isword = true;
        return true;
    }
}


void print_rec(trienode *root, char *prefix, unsigned len) {
    if (root->isword) {
        printf("%s\n", prefix);
    }

    char newprefix[len + 2];
    memcpy(newprefix, prefix, len);
    newprefix[len+1] = '\0';

    for (unsigned i = 0; i < CHARS; i++) {
        if (root->children[i] != NULL) {
            newprefix[len] = i;
            print_rec(root->children[i], newprefix, len+1);
        }
    }
}

void printtrie(trienode *root) {
    if (root == NULL) return;
    
    print_rec(root, NULL, 0);
}

int main(void) {
    trienode *root;

    insert(&root, "myvalue");
    insert(&root, "myhero");
    insert(&root, "myvalous");
    insert(&root, "shaktimaan");

    printtrie(root);
}
