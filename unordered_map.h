#ifndef UNORDERED_MAP_H
#define UNORDERED_MAP_H

typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

typedef struct UnorderedMap {
    int size;
    int capacity;
    Node** buckets;
} UnorderedMap;


UnorderedMap* create_map();
void insert(UnorderedMap* map, int key, int value);
int get(UnorderedMap* map, int key, int* value);
void remove_key(UnorderedMap* map, int key);
void print_map(UnorderedMap* map);
void free_map(UnorderedMap* map);

#endif
