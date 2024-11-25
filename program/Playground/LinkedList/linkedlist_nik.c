#include <stdio.h>
#include <stdlib.h>
#include "linkedlist_nik.h"

// Creates new node
Node* create_node(int key) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->key = key;
    new_node->next = NULL;
    return new_node;
}

// Initializes the linked list
void init_list(LinkedList* list){
    list->head = NULL;
}

// Checks if linked list is empty
int is_empty(LinkedList* list){
    return list->head == NULL;
}

// Traverses the linked list (if not empty) and append a new node at the end
void append(LinkedList* list, int key){
    Node* new_node = create_node(key);
    if (is_empty(list)){
        list->head = new_node;
    } else {
        Node* last_node = list->head;
        while (last_node->next != NULL) {
            last_node = last_node->next;
        }
        last_node->next = new_node;
    }
}

// "Pushes" the linked list one node ahead, and implement a new node on the empty spot
void prepend(LinkedList* list, int key){
    Node* new_node = create_node(key);
    new_node->next = list->head;
    list->head = new_node;
}

// Removes and returns the last node, by making a "previous" node, that sets next to NULL
Node* pop(LinkedList* list){
    if (is_empty(list)){
        return NULL;
    }

    Node* current_node = list->head;
    Node* previous_node = NULL;

    while (current_node->next != NULL){
        previous_node = current_node;
        current_node = current_node->next;
    }

    if (previous_node == NULL){
        list->head = NULL;
    } else {
        previous_node->next = NULL;
    }

    return current_node;
}

// Removes and returns (pop) the first element of the linked list
Node* pop_first(LinkedList* list){
    if (is_empty(list)){
        return NULL;
    }

    Node* first_node = list->head;
    list->head = first_node->next;
    return first_node;
}

// Search for a node with a specific key, and removes the node when found
Node* remove_node(LinkedList* list, int key){
    Node* current_node = list->head;
    Node* previous_node = NULL;

    while (current_node != NULL){
        if (current_node->key == key){
            if (previous_node == NULL){
                list->head = current_node->next;
            } else {
                previous_node->next = current_node->next;
            }
            return current_node;
        }
        previous_node = current_node;
        current_node = current_node->next;
    }

    return NULL;
}

// Finds the tail (last_node)
Node* tail(LinkedList* list){
    Node* last_node = list->head;
    while (last_node != NULL && last_node->next != NULL){
        last_node = last_node->next;
    }
    return last_node;
}

// Prints the linked list
void print_list(LinkedList* list){
    Node* current_node = list->head;
    while (current_node != NULL){
        printf("%d -> ", current_node->key);
        current_node = current_node->next;
    }
    printf("NULL\n");
}

// Returns 1 if linked list contains item that is searched for
int contains(LinkedList* list, int key){
    Node* current_node = list->head;
    while (current_node != NULL){
        if (current_node->key == key){
            return 1;
        }
        current_node = current_node->next;
    }
    return 0;
}

// Frees the list
void free_list(LinkedList* list){
    Node* current_node = list->head;
    while (current_node != NULL){
        Node* temp = current_node;
        current_node = current_node->next;
        free(temp);
    }
    list->head = NULL;
}