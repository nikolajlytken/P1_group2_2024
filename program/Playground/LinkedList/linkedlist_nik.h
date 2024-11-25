#ifndef LINKEDLIST_NIK_H
#define LINKEDLIST_NIK_H

typedef struct Node{
    int key;
    struct Node* next;
} Node;

typedef struct LinkedList{
    Node* head;
} LinkedList;

void init_list(LinkedList* list);
int is_empty(LinkedList* list);
void append(LinkedList* list, int key);
void prepend(LinkedList* list, int key);
Node* pop(LinkedList* list);
Node* pop_first(LinkedList* list);
Node* remove_node(LinkedList* list, int key);
Node* tail(LinkedList* list);
void print_list(LinkedList* list);
int contains(LinkedList* list, int key);
void free_list(LinkedList* list);

#endif