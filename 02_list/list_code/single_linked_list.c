#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    int age;
    char name [32];
    struct Node * next_node;
} Node;

// 새로운 노드 자체를 생성
Node * sll_create_node (int age, char * name) {
    Node * new_node = (Node *) malloc (sizeof(Node));

    new_node->age = age;
    strcpy(new_node->name, name);
    new_node->next_node = NULL;

    return new_node;
}

// 매개변수로 노드를 받아서 메모리 해제
void sll_destory_node (void * node) {
    free(node);
}


// 노드 추가 연산 (이중 포인터 사용)
void sll_append_node (Node ** head, Node * new_node) {

    if (*head == NULL) {
        *head = new_node;
    } else {

        Node * tail = *head;

        while (tail->next_node != NULL) {
            tail = tail->next_node;
        };


        tail->next_node = new_node;
    }
}

// 노드 추가 연산 실패 코드 (이중 포인터 사용 x)
// head는 구조체 주소값을 복사해서 전달받습니다.
// head = &node_1;
// 그렇다면 head의 값이 변경되면? node_1에 변화가 존재? -> 그렇지 않고 head의 주소값이 변경되는 것입니다.
// 즉, * 역참조를 해야 정확한 메모리 공간을 target합니다. -> 단일 포인터의 역참조는 데이터 그 자체입니다.
// 그래서 이중 포인터를 사용해서 정확한 메모리 공간을 target 하도록 합니다.
void sll_append_node_2 (Node * head, Node * new_node) {

    if (head == NULL) {
        head = new_node;
    } else {

        Node * tail = head;

        while (tail->next_node != NULL) {
            tail = tail->next_node;
        };


        tail->next_node = new_node;
    }
}

Node * sll_search_node (Node * head, char * name) {

    Node * search_node = head;

    while (search_node != NULL) {

        if (strcmp(search_node->name, name) == 0) {
            return search_node;
        }

        search_node = search_node->next_node;
    }

    return search_node;

}

void ssl_remove_node (Node ** head, Node * remove_node) {
    
    

}

int main (void) {




}