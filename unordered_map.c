#include <stdio.h>
#include <stdlib.h>
#include "unordered_map.h"

int hash(int capacity, int key) {
    if (key < 0) {
        key = -key;
    }
    return key % capacity;
}

Node* create_map_node(int key, int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->value = value;
    node->next = NULL;
    return node;
}

UnorderedMap* create_map() {
    UnorderedMap* map = (UnorderedMap*)malloc(sizeof(UnorderedMap));
    map->size = 0;
    map->capacity = 20;
    map->buckets = (Node**)calloc(map->capacity, sizeof(Node*));
    return map;
}

void insert(UnorderedMap* map, int key, int value) {
    int index = hash(map->capacity, key);

    Node* node = map->buckets[index];
    while (node) {
        if (node->key == key) {
            node->value = value;
            return;
        }
        node = node->next;
    }

    Node* newNode = create_map_node(key, value);
    newNode->next = map->buckets[index];
    map->buckets[index] = newNode;
    map->size++;
}

int get(UnorderedMap* map, int key, int* value) {
    int index = hash(map->capacity, key);

    Node* node = map->buckets[index];
    while (node) {
        if (node->key == key) {
            *value = node->value;
            return 1;
        }
        node = node->next;
    }
    return 0;
}

void remove_key(UnorderedMap* map, int key) {
    int index = hash(map->capacity, key);

    Node* node = map->buckets[index];
    Node* prev = NULL;
    while (node) {
        if (node->key == key) {
            if (prev) {
                prev->next = node->next;
            } else {
                map->buckets[index] = node->next;
            }
            free(node);
            map->size--;
            return;
        }
        prev = node;
        node = node->next;
    }
}

void print_map(UnorderedMap* map) {
    for (int i = 0; i < map->capacity; i++) {
        Node* node = map->buckets[i];
        if (node) {
            printf("Bucket %d: ", i);
            while (node) {
                printf("(%d -> %d) ", node->key, node->value);
                node = node->next;
            }
            printf("\n");
        }
    }
}

void free_map(UnorderedMap* map) {
    for (int i = 0; i < map->capacity; i++) {
        Node* node = map->buckets[i];
        while (node) {
            Node* temp = node;
            node = node->next;
            free(temp);
        }
    }
    free(map->buckets);
    free(map);
}
