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
void sll_append_node_1 (Node ** head, Node * new_node) {

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

void sll_remove_node (Node ** head, Node * remove_node) {
    
    if (*head == remove_node) {
        *head = remove_node->next_node;
    } else {

        Node * current = *head;

        // head node가 삭제할 노드가 아니고 삭제할 노드가 null이 아니면 계속됩니다.
        // 삭제할 노드의 다음노드가 삭제할 노드가 아니면 계속합니다. -> 가장 중요한 규칙 -> 삭제할 노드의 전 노드를 찾습니다.
        while (current != NULL && current->next_node != remove_node) {
            current = current->next_node;
        }
        // current는 삭제할 노드의 전 노드
        if (current != NULL) {
            current->next_node = remove_node->next_node;
        }

    }

}

int sll_get_node_count (Node * head) {

    int count = 0;

    Node * current = head;

    while (current != NULL) {
        count++;
        current = current->next_node;
    }

    return count;

}

void all_node_clear (Node * head) {

    if (head == NULL) {
        return;
    } else {

        Node * current = head;

        while (current != NULL) {

            Node * store_node = current->next_node;

            printf("프로그램 종료 전체 노드 메모리 해제 중.. [%p], %s, %d\n", current, current->name, current->age);

            free(current);

            current = store_node;

        }

    }


}

int main (void) {


    Node * list = NULL;
    Node * my_node = NULL;

    sll_append_node_1(&list, sll_create_node(20, "hong"));
    sll_append_node_1(&list, sll_create_node(30, "park"));
    sll_append_node_1(&list, sll_create_node(40, "koala"));

    my_node = sll_search_node(list, "hong");

    printf("age = %d name = %s\n", my_node->age, my_node->name);
    int node_count = sll_get_node_count(list);
    printf("node_count = %d\n", node_count);

    sll_remove_node(&list, my_node);

    sll_destory_node(my_node);

    all_node_clear(list);



}