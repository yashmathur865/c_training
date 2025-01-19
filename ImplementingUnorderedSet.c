#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int key;
    struct Node* next;
}Node;

typedef struct UnorderedSet{
    int size;
    int capacity;
    Node** buckets;
}UnorderedSet;

UnorderedSet* create_set(){
    UnorderedSet* set=(UnorderedSet*)malloc(sizeof(UnorderedSet));
    set->size=0;
    set->capacity=20;
    set->buckets=(Node**)calloc(set->capacity,sizeof(Node*));
    return set;
}

Node* create_node(int key){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->key=key;
    newNode->next=NULL;
    return newNode;
}

int contains(UnorderedSet* set,int key){
    for(int i=0;i<20;i++){
        Node* node=set->buckets[i];
        while(node){
            if(node->key==key){
                return 1;
            }
            node=node->next;
        }
    }
    return 0;
}

int hash(int capacity,int key){
    if(key<0){
        key=key*-1;
    }
    return (unsigned int) key%capacity;
}

void insert(UnorderedSet* set,int key){
    if(contains(set,key)){
        return;
    }
    Node* newNode = create_node(key);
    unsigned int index=hash(set->capacity,key);
    newNode->next=set->buckets[index];
    set->buckets[index]=newNode;
    set->size++;
}

void print_set(UnorderedSet* set){
    for(int i=0;i<20;i++){
        Node* node=set->buckets[i];
        if(node){
            while(node){
            printf("%d ",node->key);
            node=node->next;
        }
        printf("\n");
        }
    }
}

void delete(UnorderedSet* set,int key){
    int index=hash(set->capacity,key);
    Node* node=set->buckets[index];
    Node* prev=NULL;
    while(node){
        if(node->key==key){
            if(prev){
                prev->next=node->next;
            }
            else{
                set->buckets[index]=node->next;
            }
            free(node);
            set->size--;
            return;
        }
        prev=node;
        node=node->next;
    }
}

void free_set(UnorderedSet* set){
    for(int i=0;i<20;i++){
        Node* node=set->buckets[i];
        while(node){
            Node* temp = node;
            node=node->next;
            free(temp);
        }
    }
    free(set->buckets);
    free(set);
}

int main(){
    UnorderedSet* set=create_set();
    insert(set,10);
    insert(set,20);
    insert(set,30);
    print_set(set);

    delete(set,20);
    print_set(set);

    free_set(set);
    return 0;
}