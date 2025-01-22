#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
}Node;

Node* head=NULL;

Node* createNode(int data){
    Node* newNode=(Node*)malloc(sizeof(Node));
    if(!newNode){
        printf("Memory Allocation Failed\n");
    }
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}

void insertAtBeginning(int data){
    Node* newNode=createNode(data);
    if(head!=NULL){
        head->prev=newNode;
    }
    newNode->next=head;
    head=newNode;
}

void removeEveryAlternateElementFromFront(){
    Node*curr=head;
    while(curr!=NULL){
        Node*temp=curr;
        Node* next=curr->next;
        if(temp->prev!=NULL){
            temp->prev->next=next;
        }
        if(next!=NULL){
            next->prev=temp->prev;
        }
        if(curr->next!=NULL){
            curr=curr->next->next;
        }
        else{
            curr=NULL;
        }
        free(temp);
    }
    if(head->next!=NULL){
        head=head->next;
    }
}

void removeEveryAlternateElementFromBack(){
    if (head == NULL || head->next == NULL) return;
    Node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node*curr=temp;
    while(curr!=NULL){
        Node* ptr=curr;
        Node* prev=ptr->prev;
        if(prev!=NULL){
            prev->next=ptr->next;
        }
        if(ptr->next!=NULL){
            ptr->next->prev=prev;
        }
        if(curr->prev!=NULL){
            curr=curr->prev->prev;
            if(curr==head && prev!=NULL) {
            head=curr->next;
        }
        }
        else{
            curr=NULL;
        }
        free(ptr);
    }
}

void printList(){
    if(head==NULL){
        return;
    }
    Node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    scanf("%d",&n);
    for(int i=n;i>=1;i--){
        insertAtBeginning(i);
    }
    while(head->next!=NULL){
        removeEveryAlternateElementFromFront();
        if(head->next!=NULL){
        removeEveryAlternateElementFromBack();
        }
    }
    printList();
    return 0;
}