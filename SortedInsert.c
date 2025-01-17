#include<stdio.h>
#include<stdlib.h>

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

void sortedInsert(Node **head,int data){
    Node* newNode = createNode(data);
    if(*head==NULL || (*head)->data>data){
        newNode->next=*head;
        *head=newNode;
        return;
    }
    Node* curr=*head;
    while(curr->next!=NULL && curr->next->data<data){
        curr=curr->next;
    }
    newNode->next=curr->next;
    curr->next=newNode;
}

void printList(Node** head){
    Node* curr=*head;
    while(curr!=NULL){
        printf("%d -> ",curr->data);
        curr=curr->next;
    }
    printf("NULL\n");
}

int main(){
    Node* head=NULL;
    while(1){
        int choice;
        printf("Choose 1 to add an item to linked list\n");
        printf("Choose 2 to exit the program\n");
        scanf("%d",&choice);
        int data;
        switch(choice){
            case 1:
            printf("Enter the value of data\n");
            scanf("%d",&data);
            sortedInsert(&head,data);
            printList(&head);
            break;
            case 2:
            printf("Exiting the program\n");
            exit(1);
            break;
            default:
            printf("Please choice 1 or 2\n");
            break;
        }
    }
}