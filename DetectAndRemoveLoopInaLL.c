#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
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

void insertAtEnd(Node **head,int data){
    Node* newNode = createNode(data);
    if(*head==NULL){
        *head=newNode;
        return;
    }
    Node*temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
}

void printList(Node** head){
    Node* curr=*head;
    while(curr!=NULL){
        printf("%d ",curr->data);
        curr=curr->next;
    }
    printf("\n");
}

void detectAndRemoveLoop(Node **head){
    Node* slow=*head,*fast=*head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            break;
        }
    }
    if(slow!=fast){
        return;
    }
    slow=*head;
    while(slow->next!=fast->next){
        slow=slow->next;
        fast=fast->next;
    }
    fast->next=NULL;
}

int main(){
    Node* head=NULL;
    insertAtEnd(&head,10);
    insertAtEnd(&head,20);
    insertAtEnd(&head,30);
    insertAtEnd(&head,40);
    insertAtEnd(&head,50);
    insertAtEnd(&head,60);
    insertAtEnd(&head,70);
    printList(&head);
    Node* temp = head;
    temp=temp->next;
    temp=temp->next;
    Node* curr=head;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=temp;
    detectAndRemoveLoop(&head);
    printList(&head);
    return 0;
}