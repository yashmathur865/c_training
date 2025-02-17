#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    int quantity;
    char item[100];
    struct Node* next;
}Node;

typedef struct Map{
    int capacity;
    int size;
    Node** buckets;
}Map;

int hash(char* str,int capacity){
    unsigned int key=0;
    while(*str){
        key=(key+*str)%capacity;
        str++;
    }
    return key;
}

Node* createNode(char* item,int quantity){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->quantity=quantity;
    strcpy(newNode->item,item);
    newNode->next=NULL;
    return newNode;
}

void add(Map* map,char* item,int quantity){
    int index=hash(item,map->capacity);
    Node* node = map->buckets[index];
    while(node){
        if(strcmp(node->item,item)==0){
            node->quantity++;
            return;
        }
        node=node->next;
    }

    Node* newNode=createNode(item,quantity);
    newNode->next=map->buckets[index];
    map->buckets[index]=newNode;
    map->size++;
}

Map* createMap(){
    Map* map=(Map*)malloc(sizeof(Map));
    map->size=0;
    map->capacity=20;
    map->buckets=(Node**)calloc(map->capacity,sizeof(Node*));
    return map;
}

void update(Map* map,char* item,int quantity){
    int index=hash(item,map->capacity);
    Node* node=map->buckets[index];
    while(node){
        if(strcmp(node->item,item)==0){
            node->quantity=quantity;
            return;
        }
        node=node->next;
    }

    printf("Item Not Found\n");
}

void query(Map* map,char* item){
    int index=hash(item,map->capacity);
    Node* node=map->buckets[index];
    int quantity;
    while(node){
        if(strcmp(node->item,item)==0){
            quantity=node->quantity;
            printf("%d\n",quantity);
            return;
        }
        node=node->next;
    }

    printf("Item Not Found\n");
}

int main(){
    Map* map=createMap();
    int commands;
    scanf("%d",&commands);
    while(commands--){
        char com[1000];
        scanf("%s",com);
        if(strcmp("ADD",com)==0){
            char item[100];
            scanf(" %[^\n]", item);
            int quantity;
            scanf("%d",&quantity);
            add(map,item,quantity);
        }
        if(strcmp("UPDATE",com)==0){
            char item[100];
            scanf(" %[^\n]", item);
            int quantity;
            scanf("%d",&quantity);
            update(map,item,quantity);
        }
        if(strcmp("QUERY",com)==0){
            char item[100];
            scanf(" %[^\n]", item);
            query(map,item);
        }
    }
    return 0;
}