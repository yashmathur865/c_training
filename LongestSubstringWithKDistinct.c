#include<stdio.h>
#include<stdlib.h>

int max(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}

typedef struct Node{
    char ch;
    int freq;
    struct Node* next;
}Node;

typedef struct Map{
    int capacity;
    int size;
    Node** buckets;
}Map;

Map* createMap(){
    Map* map=(Map*)malloc(sizeof(Map));
    map->capacity=15;
    map->size=0;
    map->buckets=(Node**)calloc(map->capacity,sizeof(Node*));
    return map;
}

int hash(char key,int capacity){
    int value=key - 'a';
    return (value%capacity);
}

Node* createNode(char ch){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->ch=ch;
    newNode->freq=1;
    newNode->next=NULL;
    return newNode;
}

void insert(Map* map,char ch){
    int index=hash(ch,map->capacity);
    Node* node=map->buckets[index];
    while(node){
        if(node->ch==ch){
            node->freq++;
            return;
        }
        node=node->next;
    }

    Node* newNode=createNode(ch);
    newNode->next=map->buckets[index];
    map->buckets[index]=newNode;
    map->size++;
}

void decreaseFreq(Map* map,char ch){
    int index=hash(ch,map->capacity);
    Node* node=map->buckets[index];
    Node* prev=NULL;
    while(node){
        if(node->ch==ch){
            node->freq--;
            if(node->freq==0){
                if(prev) prev->next=node->next;
                else map->buckets[index]=node->next;
                free(node);
                map->size--;
            }
            return;
        }
        prev=node;
        node=node->next;
    }
}

int main(){
    printf("Enter a string\n");
    char str[100];
    scanf("%s",str);
    printf("Enter value of k");
    int k;
    scanf("%d",&k);

    Map* map = createMap();
    int res=-1;
    int left=0;
    int right=0;
    for(int i=0;str[i]!='\0';i++){
        insert(map,str[i]);
        while(map->size>k){
            decreaseFreq(map,str[left]);
            left++;
        }
        if(map->size==k){
            res=max(res,right-left+1);
        }
        right++;
    }

    printf("%d",res);
    return 0;
}