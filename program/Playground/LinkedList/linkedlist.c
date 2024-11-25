#include <stdio.h>
#include <stdlib.h>

/* Things i dont quite understand yet
    [] How do i keep the correct head?
    [] Pointers and how they related when used as inputs to functions.
    [] 
*/
struct Node{
    int value; 
    struct Node* next;
};typedef struct Node node_t;

void printlist(node_t *head){
    node_t *temp = head;
    int i = 0;
    while (temp != NULL){
        printf("index: %d  ",i);
        printf("value: %d\n",temp->value);
        temp = temp->next;
        i++;
    }
}   

void printnode(node_t *node){
    printf("%d",node->value);
}

node_t* travesal(int index,node_t *head){
    node_t *temp = head;
    for(int i=0; i < index;i++){
        if (temp->next != NULL){
            temp = temp->next;
        } else{
            printf("NULL pointer hit \n");
        };
    };
    return temp;
}

node_t* Searching(int search_Value, node_t *head){
    node_t *temp = head;

    while (temp != NULL) {
        if (temp->value == search_Value) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

int length(node_t *head){
    node_t *temp = head;
    int i = 0; 
    while(temp->next!=NULL){
        i++;
        temp = temp->next;
    }
    return i;
}

void deletion(node_t *d_node,node_t *head){
    node_t *temp = head; 
    int i =0;
    while(temp->next != d_node){
        temp = temp->next;
        i++;
    }
    temp->next = d_node->next;
}


node_t* insertion(int value, node_t *head, int place){ 
    node_t *newNode = (node_t*)malloc(sizeof(node_t));

    newNode->value = value;

    if (place == 0){
        newNode->next = head;
        return newNode;
    }

    node_t *temp = travesal(place-1,head);

    // if (temp == NULL) {
    //     free(newNode);
    //     return head;
    // }
    
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

int main(){
    node_t n1,n2,n3,n4,n5,n6;
    node_t *head;

    head = &n1;

    n1.value = 1; 
    n2.value = 2; 
    n3.value = 3; 
    n4.value = 4; 
    n5.value = 5; 
    n6.value = 6; 

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = NULL;

    printf("_____________________________________________\n");
    // Test of print list
    printf("This is the full list of elements:\n");
    printlist(head);
    printf("\n");
    
    printf("_____________________________________________\n");
    // Test of traversal
    head = &n1;
    printf("Printing the element with index 5: ");
    node_t *node = travesal(4, head);
    printnode(node);
    printf("\n");

    head = &n1;
    printf("Trying to traverse out of bounds: \n");
    node = travesal(6, head);
    printnode(node);
    printf("\n");
    printf("\n");

    printf("_____________________________________________\n");
    // Test of length
    head = &n1;
    int len = length(head);
    printf("Length of linkedlist: %d\n", len);
    printf("\n");

    printf("_____________________________________________\n");
    // Test of deletion
    head = &n1;
    deletion(&n4, head);
    printf("List after deleting node 4:\n");
    printlist(head);
    printf("\n");

    printf("_____________________________________________\n");
    // Test of insertion
    head = &n1;
    head = insertion(7, head, 2);
    printf("List after inserting 7 at position 2:\n");
    printlist(head);
    
    return 0;
}