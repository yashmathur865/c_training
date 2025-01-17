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

void printNthValueFromEnd(Node **head,int n){
    if(n<=0){
        printf("Invalid value of N\n");
        return;
    }
    if(*head==NULL){
        printf("Linked List is empty\n");
        return;
    }
    Node* first=*head;
    for(int i=0;i<n;i++){
        if(first==NULL){
            printf("Not Enough Elements In Linked List\n");
            return;
        }
        first=first->next;
    }
    Node* second=*head;
    while(first!=NULL){
        second=second->next;
        first=first->next;
    }
    printf("The value of Nth Node from end is %d\n",second->data);
}

int main(){
    Node* head=NULL;
    while(1){
        int choice;
        printf("Choose 1 to add an item to linked list\n");
        printf("Choose 2 to print Nth value from end\n");
        printf("Choose 3 to exit the program\n");
        scanf("%d",&choice);
        int data;
        int n;
        switch(choice){
            case 1:
            printf("Enter the value of data\n");
            scanf("%d",&data);
            insertAtBeginning(&head,data);
            printList(&head);
            break;
            case 2:
            printf("Enter the value of N\n");
            scanf("%d",&n);
            printNthValueFromEnd(&head,n);
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