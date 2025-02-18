#include<stdio.h>
#include<stdlib.h>

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

void decrementFreq(Map* map,int key){
    int index=hash(key,map->capacity);
    Node* node=map->buckets[index];
    Node* prev=NULL;
    while(node){
        if(node->key==key){
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
    printf("Enter size of array\n");
    int n;
    scanf("%d",&n);
    printf("Enter Elements\n");
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter value of k\n");
    int k;
    scanf("%d ",&k);

    Map* map = createMap();
    for(int i=0;i<k;i++){
        insert(map,arr[i]);
    }
    printf("%d",map->size);
    int left=0;
    int right=k;
    while(right<n){
        insert(map,arr[right]);
        decrementFreq(map,arr[left]);
        left++;
        right++;
        printf("%d ",map->size);
    }
    return 0;
}