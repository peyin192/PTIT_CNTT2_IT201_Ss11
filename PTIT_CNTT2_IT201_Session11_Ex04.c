#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;
Node*createNode(int value){
    Node*newNode=(Node*)malloc(sizeof(Node));
    newNode->data=value;//gán giá trị cho node
    newNode->next=NULL;//gán giá trị cho con trỏ next
    newNode->prev=NULL;//in giá trị cho con trỏ prev
    return newNode;
}
//Hàm đếm độ dài của danh sách
int countLength(Node* head) {
    int count=0;
    Node* temp=head;
    while (temp!=NULL) {
        count++;
        temp=temp->next;

    }
    return count;
}
//hàm in danh sách liên kết đôi
void printList(Node* head){
    int index=1;
    Node* temp=head;
    printf("Danh sach lien ket doi: \n");
    while(temp!=NULL){
        printf("Node %d :%d ",index++,temp->data);
        temp=temp->next;
        printf("\n");
    }

}
//hàm giải phóng bộ nhớ
void freeList(Node* head){
    Node* temp=head;
    while(head!=NULL){
        temp=head;
        head=head->next;//tr ến con trỏ tiếp theo
        free(temp);//giải phóng các node
    }

}
int main(){

    Node*node1=createNode(10);
    Node*node2=createNode(20);
    Node*node3=createNode(30);
    Node*node4=createNode(40);
    Node*node5=createNode(50);

    //Gán các node với nhau
    node1->next=node2;
    node2->prev=node1;
    node2->next=node3;
    node3->prev=node2;
    node3->next=node4;
    node4->prev=node3;
    node4->next=node5;
    node5->prev=node4;

    Node* head=node1;
    printList(head);
    int lenghth=countLength(head);

    printf("Danh sach lien ket co %d phan tu",lenghth);

    //giải phóng bộ nhớ
    freeList(head);
    return 0;
}