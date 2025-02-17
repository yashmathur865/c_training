#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct item{
    char task[100];
    int status;
}item;

typedef struct Queue{
    item arr[100];
    int front;
    int rear;
    int size;
}Queue;

void init(Queue* q){
    q->front=0;
    q->size=0;
    q->rear=-1;
}

void add(Queue* q,char* task){
    if(q->size==100){
        printf("Queue is full\n");
        return;
    }
    q->rear=(q->rear+1)%100;
    item item;
    item.status=1;
    strcpy(item.task,task);
    q->arr[q->rear]=item;
    q->size++;
}

void complete(Queue* q,char* task){
    int i=q->front;
    while(i!=q->rear){
        if(strcmp(q->arr[i].task,task)==0){
            q->arr[i].status=0;
            return;
        }
        i=(i+1)%100;
    }
    if (strcmp(q->arr[i].task, task) == 0) {
        q->arr[i].status = 0;
    }
}

void pending(Queue* q){
    if(q->size==0){
        printf("No Pending Tasks\n");
    }
    int i=q->front;
    while(i!=q->rear){
        if(q->arr[i].status==1){
            printf("%s\n",q->arr[i].task);
        }
        i=(i+1)%100;
    }
    if (q->arr[i].status == 1) {
        printf("%s\n", q->arr[i].task);
    }
}

int main(){
    Queue q;
    init(&q);
    int commands;
    scanf("%d",&commands);
    while(commands--){
        char com[100];
        scanf("%s",com);
        if(strcmp("ADD",com)==0){
            char task[100];
            scanf(" %[^\n]",task);
            add(&q,task);
        }
        if(strcmp("COMPLETE",com)==0){
            char task[100];
            scanf(" %[^\n]",task);
            complete(&q,task);
        }
        if(strcmp("PENDING",com)==0){
            pending(&q);
        }
    }
}

