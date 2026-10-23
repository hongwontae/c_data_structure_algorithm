#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    int age;
    char name [32];
    struct Node * next_node;
    struct Node * prev_node;
} Node;

Node global_head_node = {0, "Dummy_head", NULL, NULL};
Node global_tail_node = {0, "Dummy_tail", NULL, NULL};

// 완전히 연결해야 함
void cll_connect_node() {
    global_head_node.next_node = &global_tail_node;
    global_head_node.prev_node = &global_tail_node;

    global_tail_node.prev_node = &global_head_node;
    global_tail_node.next_node = &global_head_node;
}

Node * cll_create_new_node (int age, char * name) {

    Node * new_node = malloc (sizeof(Node));
    new_node->age = age;
    strcpy(new_node->name, name);

    return new_node;
}

void cll_destroy_node (Node * node) {
    free(node);
}

// 새로운 노드는 테일 뒤에 추가합니다.
void cll_append_node (Node * new_node) {

    Node * non_change_prev_node = (&global_tail_node)->prev_node;

    global_tail_node.prev_node = new_node;
    new_node->next_node = &global_tail_node;

    non_change_prev_node->next_node = new_node;
    new_node->prev_node = non_change_prev_node;

}

Node * cll_remove_node_one (Node * target) {

    if (target == NULL) {
        return NULL;
    } else if (&global_head_node == target || &global_tail_node == target) {
        return NULL;
    }

    
    Node * forward = target->next_node;
    Node * backward = target->prev_node;

    forward->prev_node = backward;
    backward->next_node = forward;

    target->next_node = NULL;
    target->prev_node = NULL;

    return target;

}


void all_print_node () {
    
    Node * head = &global_head_node;

    while (head != &global_tail_node) {
        printf("[%p] 이름 : %s, 나이 : %d \n", head, head->name, head->age);
        head = head->next_node;
    }

}

void all_clear_node () {

    Node * real_head = (&global_head_node)->next_node;

    while (real_head != &global_tail_node) {
        Node * temp = real_head->next_node;
        free(real_head);
        real_head = temp;
    }

}



int main () {
    cll_connect_node();

    cll_append_node(cll_create_new_node(10, "Hong"));
    cll_append_node(cll_create_new_node(10, "Kim"));
    cll_append_node(cll_create_new_node(10, "Kong"));
    cll_append_node(cll_create_new_node(10, "Jang"));
    cll_append_node(cll_create_new_node(10, "Sang"));

    all_print_node();

    all_clear_node();
}   