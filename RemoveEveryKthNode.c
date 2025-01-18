#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

int isDigit(char ch){
    if(ch>='0' && ch<='9'){
        return 1;
    }
    return 0;
}

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
        printf("%d ",curr->data);
        curr=curr->next;
    }
}

void RemoveEveryKthNode(Node **head,int k){
    if(*head==NULL || k<=1){
        while(*head!=NULL){
            Node* temp=*head;
            *head=(*head)->next;
            free(temp);
        }
        return;
    }
    Node* curr=*head;
    Node* prev=NULL;
    int count=1;

    while(curr!=NULL){
        if(count%k==0){
            Node* temp=curr;
            prev->next=curr->next;
            curr=curr->next;
            free(temp);
        }
        else {
            prev=curr;
            curr=curr->next;
        }
        count++;
    }
}


int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
     Node* head = NULL;
    char str[1000];
    scanf("%[^\n]%*c",str);

    int i=0;
    while(str[i]!='\0'){
        if(str[i]==' '){
            i++;
            continue;
        }
        if(str[i]=='-'){
            i++;
            continue;
        }
        if(isDigit(str[i])==1){
            int num=0;
            int sign=1;
            if(i-1>=0){
                if(str[i-1]=='-'){
                    sign=-1;
                }
            }
            while(isDigit(str[i])==1){
                num=num*10 + (str[i]-'0');
                i++;
            }
            num=num*sign;
            insertAtEnd(&head,num);
        }
        i++;
    }
    int k;
    scanf("%d",&k);

    RemoveEveryKthNode(&head,k);
    printList(&head);

    return 0;
}