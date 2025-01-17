#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode==NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

void insertAtEnd(Node **head,int data){
    Node *newNode = createNode(data);
    if(*head==NULL){
        *head=newNode;
        return;
    }
    Node* temp = *head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
}

void printList(Node** head){
    Node* curr = *head;
    while(curr!=NULL){
        printf("%d->",curr->data);
        curr=curr->next;
    }
    printf("NULL\n");
}

void insertAtBeginning(Node **head,int data){
    Node *newNode = createNode(data);
    newNode->next=*head;
    *head=newNode;
}

void deleteNode(Node **head,int key){
    Node* temp=*head;
    Node* prev=NULL;

    if(temp!=NULL && temp->data==key){
        *head=temp->next;
        free(temp);
        return;
    }

    while(temp!=NULL && temp->data!=key){
        prev=temp;
        temp=temp->next;
    }

    if (temp == NULL) {
        printf("Key not found\n");
        return;
    }

    prev->next=temp->next;
    free(temp);
}

void freeList(Node **head){
    Node* curr = *head;
    Node* next;
    while(curr!=NULL){
        next=curr->next;
        free(curr);
        curr=next;
    }
    *head=NULL;
}

int main() {
    Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    printf("Linked list after inserting at the end: ");
    printList(&head);

    insertAtBeginning(&head, 5);
    printf("Linked list after inserting at the beginning: ");
    printList(&head);

    deleteNode(&head, 20);
    printf("Linked list after deleting 20: ");
    printList(&head);

    freeList(&head);
    printf("Linked list after freeing all nodes: ");
    printList(&head);

    return 0;
}