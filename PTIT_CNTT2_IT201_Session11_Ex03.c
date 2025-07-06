#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Node {
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
//hàm tìm kiếm phần tử bất kì trong danh sách
bool search(Node* head,int searchTarget) {
     Node* current=head;
     while(current!=NULL) {
         //lấy giá trị trong từng node đi so sánh với searchtarget
         if (current->data==searchTarget){
             return true;
         }
             current=current->next;//tr đến các node tiếp theo
     }
     return false;
}
int main() {
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
    int searchValue;
    printf("Nhap mot gia tri bat ki: ");
    scanf("%d",&searchValue);
    bool resultSearch=search(head,searchValue);
    if(resultSearch) {
        printf("True\n");
    }else {
        printf("False\n");
    }
    freeList(head);
    return 0;
}
