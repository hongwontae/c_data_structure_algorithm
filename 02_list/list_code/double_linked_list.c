#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    int age;
    char name [32];
    struct Node * next_node;
    struct Node * prev_node;
} Node;

Node * dll_create_node (int age, char * name) {

    Node * new_node = (Node *) malloc(sizeof(Node));

    new_node->age = age;
    strcpy(new_node->name, name);
    new_node->next_node = NULL;
    new_node->prev_node = NULL;

    return new_node;

}

void dll_destroy_node (Node * target_node) {
    free(target_node);
}

void dll_append_node (Node ** head, Node * new_node) {
    if (*head == NULL) {
        *head = new_node;
    } else {
        
        Node * tail_node = *head;

        while (tail_node->next_node != NULL) {
            tail_node = tail_node->next_node;
        }

        tail_node->next_node = new_node;
        new_node->prev_node = tail_node;

    }
}

Node * dll_get_node_at_straight (Node * head, char * search_name) {

    Node * current_node = head;

    while (current_node != NULL) {
        if (strcmp(current_node->name, search_name) == 0) {
            return current_node;
        }
        current_node = current_node->next_node;
    }

    return current_node;

}

void dll_remove_node (Node ** head, Node * remove_node) {

    if (*head == NULL) {
        return;
    } else if (*head == remove_node && (*head)->next_node == NULL) {
        *head = NULL;
        return;
    } else if (*head == remove_node) {
        *head = remove_node->next_node;
        (*head)->prev_node = NULL;
        return;
        
    } else {
        
        Node * temp = remove_node;

        if (remove_node->prev_node != NULL) {
            remove_node->prev_node->next_node = remove_node->next_node;
        }

        if (remove_node->next_node != NULL) {
            remove_node->next_node->prev_node = remove_node->prev_node;
        }

        remove_node->prev_node = NULL;
        remove_node->next_node = NULL;
        

    } 

}

int dll_get_node_count (Node * head) {
    unsigned int count = 0;
    Node * current = head;

    while (current != NULL) {
        count++;
        current = current->next_node;
    }

    return count;

}

void dll_all_node_clear(Node * head) {

    Node * clear_node = head;

    while (clear_node != NULL) {
        Node * temp = clear_node->next_node;
        free(clear_node);
        clear_node = temp;
    }


}   

void dll_all_print (Node * head) {

    Node * current = head;

    while (current != NULL) {
        printf("[%p] 이름 : %s, 나이 : %d\n", current, current->name, current->age);
        current = current->next_node;
    }

}

int main (void) {

    int count = 0;
    Node * list = NULL;


    dll_append_node(&list, dll_create_node(20, "Hong"));
    dll_append_node(&list, dll_create_node(30, "Kim"));
    dll_append_node(&list, dll_create_node(40, "Jae"));
    dll_append_node(&list, dll_create_node(50, "Hoon"));
    dll_append_node(&list, dll_create_node(60, "Look"));

    Node * search_node = dll_get_node_at_straight(list, "Hong");
    printf("search! [%p] %s %d\n", search_node, search_node->name, search_node->age);

    dll_all_print(list);


    dll_all_node_clear(list);


    return 0;
}