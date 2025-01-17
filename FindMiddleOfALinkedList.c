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

void printMiddle(Node **head){
    if(*head==NULL){
        printf("Linked List is empty\n");
        return;
    }
    Node* slow=*head,*fast=*head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    printf("The middle Element of Linked List is %d\n",slow->data);
}

int main(){
    Node* head=NULL;
    while(1){
        int choice;
        printf("Choose 1 to add an item to linked list\n");
        printf("Choose 2 find middle of this Linked List\n");
        printf("Choose 3 to exit the program\n");
        scanf("%d",&choice);
        int data;
        switch(choice){
            case 1:
            printf("Enter the value of data\n");
            scanf("%d",&data);
            insertAtBeginning(&head,data);
            printList(&head);
            break;
            case 2:
            printMiddle(&head);
            break;
            case 3:
            printf("Exiting The program\n");
            exit(1);
            default:
            printf("Please choose between 1 to 3\n");
            break;
        }
    }
}