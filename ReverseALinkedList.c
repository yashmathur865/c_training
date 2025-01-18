#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(!newNode){
        printf("Memory Allocation Failed\n");
        exit(1);
    }
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

void insertAtBeginning(Node** head,int data){
    Node* newNode = createNode(data);
    newNode->next=*head;
    *head=newNode;
}

void printList(Node **head){
    Node *curr = *head;
    while(curr!=NULL){
        printf("%d -> ",curr->data);
        curr=curr->next;
    }
    printf("NULL\n");
}

void reverseList(Node** head){
   Node* curr =*head;
   Node* prev = NULL;
   while(curr!=NULL){
    Node* next = curr->next;
    curr->next=prev;
    prev=curr;
    curr=next;
   }
   *head=prev;
}

int main(){
    Node* head=NULL;
    insertAtBeginning(&head,10);
    insertAtBeginning(&head,20);
    insertAtBeginning(&head,30);
    insertAtBeginning(&head,40);
    insertAtBeginning(&head,50);
    insertAtBeginning(&head,60);
    insertAtBeginning(&head,70);
    insertAtBeginning(&head,80);
    printList(&head);

    reverseList(&head);
    printList(&head);
    return 0;
}