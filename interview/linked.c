#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct Node {
    uint32_t data;    
    Node *next;
    Node *prev;
} Node;

typedef struct {
    Node *head;
    Node *tail; 
    uint32_t size;
} LinkedList;

void insert(LinkedList *ll, uint32_t data) {
    
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;

    if (ll->size == 0) {
        ll->head = new_node;
        ll->tail = new_node;
        ll->size = 1;
        return;     
    }

    Node *cur_node = ll->head;
    while (cur_node->data < data && cur_node->next != NULL) {
        cur_node = cur_node->next;
    }

    if (data < cur_node->data && cur_node == ll->head) {
        // insert left 
        cur_node->prev = new_node;
        new_node->next = cur_node;
        ll->head = new_node;
        ll->size++;
    } else if (data > cur_node->data && cur_node == ll->tail) {
        // insert right of tail
        cur_node->next = new_node;
        new_node->prev = cur_node;
        ll->tail = new_node;
        ll->size++;
    } else {
        // insert in the middle
        Node *prev = cur_node->prev;

        prev->next = new_node;
        cur_node->prev = new_node;     
        new_node->next = cur_node;
        new_node->prev = prev;

        ll->size++;
    } 
}

void print_ll(LinkedList *ll) {
    Node *cur_node = ll->head;
    while (cur_node != NULL) {
        printf("%u, ", cur_node->data);
        cur_node = cur_node->next;
    }
    printf("\n");
}

void print_ll_tail(LinkedList *ll) {
    Node *cur_node = ll->tail;
    while (cur_node != NULL) {
        printf("%u, ", cur_node->data);
        cur_node = cur_node->prev;
    }
    printf("\n");
}

int main() {

    LinkedList *ll = (LinkedList*)malloc(sizeof(LinkedList));

    insert(ll, 8);
    print_ll(ll);
    insert(ll, 20);
    print_ll(ll);
    insert(ll, 3);
    print_ll(ll);
    insert(ll, 40);
    print_ll(ll);
    print_ll_tail(ll);
    insert(ll, 39);
    print_ll(ll);
    
    return 0;
}