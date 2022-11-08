
#include <stdio.h>
#include <stdlib.h>


/**
 * 1. insert
 * 2. search
 * 3. delete
 * 4. successor
 * 5. predecessor
 * 6. min from node
 * 7. max from node
 */

struct tree_node {
    int value;
    struct tree_node *left;
    struct tree_node *right;
    struct tree_node *parent;
};

typedef struct tree_node node;

node* minTree(node *pointer) {
    while (pointer->left != NULL) {
        pointer = pointer->left;
    }

    return pointer; 
}

node *maxTree(node *pointer) {
    while (pointer->right != NULL) {
        pointer = pointer->right;
    }

    return pointer;
}

// This assumes that passed node does have a successor
node *successor(node *pointer) {
    // if node has a right child
    if (pointer->right != NULL) {
        return minTree(pointer->right);
    }

    node *parent = pointer->parent;
    while (parent != NULL && parent->left != pointer) {
        pointer = parent;
        parent = pointer->parent;
    }

    return parent;
}

// This assumes node does have a predecessor
node *predecessor(node *pointer) {
    if (pointer->left != NULL) {
        return maxTree(pointer->left);
    }

    node *parent = pointer->parent;
    while (parent != NULL && parent->right != pointer) {
        pointer = parent;
        parent = pointer->parent;
    }

    return parent;
}

node* search(node* head, int value) {
    while (head != NULL && head->value != value) {
        if (value > head->value) {
            head = head->right;
        } else {
            head = head->left;
        }
    }

    return head;
}

node* insert(node *head, int value) {
    node* parent = NULL;
    while (head != NULL) {
        parent = head;
        if (head->value > value) {
            head = head->left;
        } else {
            head = head->right;
        }
    }

    head = malloc(sizeof(node));

    head->value = value;
    head->parent = parent;

    if (parent == NULL) {
        return head;
    }
    else if (parent->value > value) {
        parent->left = head;
    } else {
        parent->right = head;
    } 

    return NULL;
}

void move_branch(node *root, node *to, node *with) {
    // if to is the root node
    if (to->parent == NULL) {
        *root = *with;
    } else if (to->parent->left == to) { // change parent's pointer
        to->parent->left = with;         // from old node to new node
    } else {
        to->parent->right = with;
    }

    // set new node's parent as old node's parent
    if (with != NULL) {
        with->parent = to->parent;
    }
}

// delete needs to shift 2 branches
void delete(node *root, node *pointer) {
    if (pointer->left == NULL) { // handle leaf node or node without left childs
        move_branch(root, pointer, pointer->right);
    } else if (pointer->right == NULL) {
        move_branch(root, pointer, pointer->left);
    } else {
        node *succ = successor(pointer);
        if (pointer->right != succ) {
            move_branch(root, succ, succ->right);
            succ->right = pointer->right;
            succ->right->parent = succ;
        }
        move_branch(root, pointer, succ);
        succ->left = pointer->left;
        succ->left->parent = succ;
    }
    
    if (pointer && pointer != root) free(pointer);
}

void inorder_walk(node *root) {
    if (root != NULL) {
        inorder_walk(root->left);
        printf("%d ", root->value);
        inorder_walk(root->right);
    }
}

void clear_memory(node *root) {
    if (root != NULL) {
        clear_memory(root->left);
        clear_memory(root->right);
        free(root);
    }
}

int main(void) {
    node *root = NULL;
    root = insert(root, 15);
    insert(root, 8);
    insert(root, 25);
    insert(root, 5);
    insert(root, 11);
    insert(root, 22);
    insert(root, 40);
    insert(root, 1);
    insert(root, 7);
    insert(root, 10);
    insert(root, 14);
    insert(root, 37);
    insert(root, 70);
    insert(root, 3);
    insert(root, 12);
    insert(root, 13);

    inorder_walk(root);
    printf("\n%d\n", maxTree(root)->value);
    node *found = search(root, 10);
    delete(root, found);
    inorder_walk(root);
    clear_memory(root);
}
