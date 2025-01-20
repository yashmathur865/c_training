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

Node* reverseList(Node **head){
    Node* curr=*head;
    Node* prev=NULL;
    while(curr!=NULL){
        Node* next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

int checkPalindrome(Node** head){
    if(*head==NULL || (*head)->next==NULL){
        return 1;
    }
    Node* slow=*head;
    Node* fast=*head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node* temp=reverseList(&slow->next);
    slow->next=temp;
    Node* first=*head;
    Node* second=temp;
    while(second!=NULL){
        if(first->data!=second->data){
            return 0;
        }
        first=first->next;
        second=second->next;
    }
    return 1;
}

int main() {

    Node* head = NULL;
    int val;
    char c;
    while (1){
        if(scanf("%d",&val)==1){
            insertAtEnd(&head,val);
        }
        else{
            break;
        }
        c=getchar();
        if(c=='\n'){
            break;
        }
    }
    printList(&head);
    if(checkPalindrome(&head)){
        printf("This is a Palindromic Linked List\n");
    }
    else{
        printf("This is NOT a Palindromic Linked List\n");
    }
    return 0;
}