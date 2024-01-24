#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    void *left;
    void *right;
    uint32_t key;
} Node;

typedef struct {
    Node *root;
    uint32_t capacity;
    uint32_t h;
} BST;

BST *create_bst() {
    BST *bst = (BST*)malloc(sizeof(BST));
    bst->capacity = 0;
    bst->h = 0;

    return bst;
}

Node *create_node(uint32_t data) {

    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->key = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node *insert(Node *root, uint32_t key) {
    if (root == NULL) {
        return create_node(key);
    }
    if (key < root->key) {
        root->left = insert((Node*)root->left, key);
    }
    else if (key > root->key) {
        root->right = insert((Node*)root->right, key);
    }
    return root;
}

// void print_b
void print_bst(Node *root)
{
    if (root == NULL) {
        return;
    }
    print_bst((Node*)root->left);
    printf(" [%u] ", root->key);
    print_bst((Node*)root->right);
}

int main() {

    int keys[10] = {30, 50, 40, 10, 80, 90, 70, 20, 100, 60};
    
    Node *root = NULL;
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 6);

    print_bst(root);
    return 0;
}