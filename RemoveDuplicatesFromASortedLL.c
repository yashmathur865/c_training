#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* createNode(int data){
    Node* newNode=(Node*)malloc(sizeof(Node));
    if(!newNode){
        printf("Memory Allocation Failed\n");
        exit(1);
    }
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

void insertAtEnd(Node **head,int data){
    Node* newNode=createNode(data);
    if(*head==NULL){
        *head=newNode;
        return;
    }
    Node*curr = *head;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=newNode;
}

void printList(Node **head){
    Node* curr = *head;
    while(curr!=NULL){
        printf("%d -> ",curr->data);
        curr=curr->next;
    }
    printf("NULL\n");
}

void removeDuplicates(Node** head){
    Node* curr=*head;
    while(curr!=NULL && curr->next!=NULL){
        if(curr->data==curr->next->data){
            curr->next=curr->next->next;
        }
        else{
            curr=curr->next;
        }
    }
}

int main(){
    Node* head=NULL;
    insertAtEnd(&head,10);
    insertAtEnd(&head,10);
    insertAtEnd(&head,20);
    insertAtEnd(&head,30);
    insertAtEnd(&head,30);
    insertAtEnd(&head,30);
    insertAtEnd(&head,40);
    insertAtEnd(&head,50);
    insertAtEnd(&head,50);
    insertAtEnd(&head,50);
    insertAtEnd(&head,50);
    printList(&head);
    printf("Linked List After Removing Duplicates\n");
    removeDuplicates(&head);
    printList(&head);
    return 0;
}