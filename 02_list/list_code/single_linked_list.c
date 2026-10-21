#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node * node;
} Node;

Node * sll_create_node (int data) {
    Node * new_node = (Node *) malloc (sizeof(Node));

    new_node->data = data;
    new_node->node = NULL;

    return new_node;
}


void sll_destory_node (void * node) {
    free(node);
}



int main (void) {




}