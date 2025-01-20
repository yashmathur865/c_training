#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    int identity;
    struct Node *next;
}Node;

Node* createNode(int data,int** identity){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(!newNode){
        printf("Memory Allocation Failed\n");
        exit(1);
    }
    newNode->data=data;
    newNode->next=NULL;
    newNode->identity=**identity;
    **identity=**identity+1;
    return newNode;
}

void insertAtEnd(Node **head,int data,int* identity){
    Node* newNode = createNode(data,&identity);
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

int LLLength(Node** head){
    int len=0;
    Node* curr=*head;
    while(curr!=NULL){
        len++;
        curr=curr->next;
    }
    return len;
}

void removeHead(Node*** head){
    if(**head==NULL){
        return;
    }
    Node* temp = **head;
    **head=(**head)->next;
    free(temp);
}

void removeFrontAppendBack(Node*** head){
    if(**head==NULL || (**head)->next==NULL){
        return;
    }
    Node *first=**head;
    Node* curr=**head;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    **head=(**head)->next;
    first->next=NULL;
    curr->next=first;
}

void printIndividualCompletionTime(Node** head,int timeQuanta,int len){
    int time=0;
    int arr[len];
    while(*head!=NULL){
        int completed=0;
        for(int i=0;i<timeQuanta;i++){
            (*head)->data--;
            time++;
            if((*head)->data==0){
                arr[((*head)->identity)-1]=time;
                removeHead(&head);
                completed=1;
                break;
            }
        }
        if(!completed){
            removeFrontAppendBack(&head);
        }
    }
    for(int i=0;i<len;i++){
        printf("Completion time of Process %d is %d\n",(i+1),arr[i]);
    }
}

int main(){
    int identity=1;
    Node* head = NULL;
    int len=0;
    printf("Enter the execution time of processes: ");
    int val;
    char c;
    while(1){
        if(scanf("%d",&val)==1){
            len++;
            insertAtEnd(&head,val,&identity);
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
    printf("Enter the value of Time quanta: ");
    int timeQuanta;
    scanf("%d",&timeQuanta);

    printIndividualCompletionTime(&head,timeQuanta,len);

    return 0;
}