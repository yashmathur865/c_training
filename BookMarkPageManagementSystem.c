#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

typedef struct stack{
    int arr[1000];
    int top;
    int size;
}Stack;

void init(Stack* s){
    s->top=-1;
    s->size=0;
}

void push(Stack* s,int value){
    if(s->size==1000){
        printf("Cannot push.Stack is full");
        return;
    }
    s->arr[++s->top]=value;
    s->size++;
}

int pop(Stack* s){
    if(s->top==-1){
        printf("No bookmarks to delete\n");
        return -1;
    }
    int value=s->arr[s->top];
    s->top--;
    s->size--;
   return value;
}

void printStack(Stack* s){
    if(s->top==-1){
        printf("No active bookmarks\n");
        return;
    }
    int size = s->size;
    int arr[size];
    for(int i=0;i<size;i++){
        arr[i]=s->arr[i];
    }
    for(int i=0;i<size;i++){
        int swapped=0;
        for(int j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
                swapped=1;
            }
        }
        if(swapped==0){
            break;
        }
    }

    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    Stack s;
    init(&s);
    int commands;
    printf("Enter Number of commands\n");
    scanf("%d",&commands);
    while(commands--){
        char com[100];
        scanf("%s",com);
        if(strcmp("BOOKMARK",com)==0){
            int pageNo;
            scanf("%d",&pageNo);
            push(&s,pageNo);
        }
        if(strcmp("DELETE",com)==0){
            pop(&s);
        }
        if(strcmp("LIST",com)==0){
            printStack(&s);
        }
    }
    return 0;
}