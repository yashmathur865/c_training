#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* head=NULL;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

void insertAtEnd(int data){
    Node* newNode = createNode(data);
    if(head==NULL){
        head=newNode;
        return;
    }
    Node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
}

void printList(){
    Node *curr = head;
    while(curr!=NULL){
        printf("%d -> ",curr->data);
        curr=curr->next;
    }
    printf("NULL\n");
}

void reverseInGroupK(int k){
    Node* curr=head;
    Node* prevFirst=NULL;
    int firstPass=1;
    while(curr!=NULL){
        Node* first=curr;
        Node* prev=NULL;
        int count=0;
        while(curr!=NULL && count<k){
            Node* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }
        if(firstPass==1){
            head=prev;
            firstPass=0;
        }
        else{
            prevFirst->next=prev;
        }
        prevFirst=first;
    }
}

int main(){
    int value;
    char c;
    while(1){
        if(scanf("%d",&value)>0){
            insertAtEnd(value);
        }
        else{
            break;
        }
        c=getchar();
        if(c=='\n'){
            break;
        }
    }
    int k;
    printf("Enter Value of K\n");
    scanf("%d",&k);
    printList();
    reverseInGroupK(k);
    printList();
    return 0;
}