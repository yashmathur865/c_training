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
    Node* temp = *head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
}

void printList(Node **head){
    Node *curr = *head;
    while(curr!=NULL){
        printf("%d -> ",curr->data);
        curr=curr->next;
    }
    printf("NULL\n");
}

void rotateLLKTimes(Node** head,int k){
    Node* tail=*head;
    int len=1;
    while(tail->next!=NULL){
        tail=tail->next;
        len++;
    }
    k=k%len;
    if(k==0){
        return;
    }
    Node* temp=*head;
    int i=0;
    while(i<k-1){
       temp=temp->next;
       i++;
    }
    tail->next=*head;
    *head=temp->next;
    temp->next=NULL;
}

int main(){
    Node* head=NULL;
    insertAtEnd(&head,10);
    insertAtEnd(&head,20);
    insertAtEnd(&head,30);
    insertAtEnd(&head,40);
    printList(&head);
    int k;
    printf("Enter the value of k\n");
    scanf("%d",&k);
    rotateLLKTimes(&head,k);
    printList(&head);
    return 0;
}