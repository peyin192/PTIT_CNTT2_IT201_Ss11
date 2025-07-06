#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void printList(Node* head) {
    int index = 1;
    Node* temp = head;
    printf("Danh sach lien ket doi: \n");
    while (temp != NULL) {
        printf("Node %d :%d ", index++, temp->data);
        temp = temp->next;
        printf("\n");
    }
}

void freeList(Node* head) {
    Node* temp = head;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void insertToHead(Node** head, int value) {
    Node* newNode = createNode(value);
    newNode->next = *head;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

int main() {
    Node* node1 = createNode(10);
    Node* node2 = createNode(20);
    Node* node3 = createNode(30);
    Node* node4 = createNode(40);
    Node* node5 = createNode(50);

    node1->next = node2;
    node2->prev = node1;
    node2->next = node3;
    node3->prev = node2;
    node3->next = node4;
    node4->prev = node3;
    node4->next = node5;
    node5->prev = node4;

    Node* head = node1;
    printList(head);

    int value;
    printf("Nhap mot so bat ki:");
    scanf("%d", &value);

    if (value <= 0) {
        printf("Khong hop le");
    } else {
        insertToHead(&head, value);
        printf("Danh sach lien ket doi sau khi them la:\n");
        printList(head);
    }

    freeList(head);
    return 0;
}
