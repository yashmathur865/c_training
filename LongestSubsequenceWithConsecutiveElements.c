#include<stdio.h>
#include<stdlib.h>

int max(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}

typedef struct Node{
    int key;
    int freq;
    struct Node* next;
}Node;

typedef struct Map{
    int capacity;
    int size;
    Node** buckets;
}Map;

int hash(int key,int capacity){
    if(key<0){
        key*=-1;
    }
    return (key%capacity);
}

Map* createMap(){
    Map* map=(Map*)malloc(sizeof(Map));
    map->capacity=20;
    map->size=0;
    map->buckets=(Node**)calloc(map->capacity,sizeof(Node*));
    return map;
}

Node* createNode(int key){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->key=key;
    newNode->freq=1;
    newNode->next=NULL;
    return newNode;
}

void insert(Map* map,int key){
    int index=hash(key,map->capacity);
    Node* node=map->buckets[index];
    while(node){
        if(node->key==key){
            node->freq++;
            return;
        }
        node=node->next;
    }

    Node* newNode=createNode(key);
    newNode->next=map->buckets[index];
    map->buckets[index]=newNode;
    map->size++;
}

int contains(Map* map,int key){
    int index=hash(key,map->capacity);
    Node* node=map->buckets[index];
    while(node){
        if(node->key==key){
            return 1;
        }
        node=node->next;
    }
    return 0;
}

int main(){

    printf("Enter size of array\n");
    int n;
    scanf("%d",&n);

    printf("Enter Elements\n");
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    Map* map=createMap();
    for(int i=0;i<n;i++){
        insert(map,arr[i]);
    }

    int res=0;
    for(int i=0;i<n;i++){
    if(!contains(map,arr[i]-1)){
        int curr=1;
        int value=arr[i];
        while(contains(map,value+1)){
            value++;
            curr++;
        }
        res=max(res,curr);
    }
    }

    printf("%d",res);
    return 0;
}