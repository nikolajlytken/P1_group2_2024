#include <stdio.h>
#include <stdlib.h>
#define V 10 
#define E 14
#define MAX_VERTICES 200

typedef struct Node {
    int dest;
    struct Node* next; 
}node_t;


typedef struct{
    node_t* head;
} adjlist_t;

node_t* createNode(int dest) {
    node_t* newNode =
      (node_t*)malloc(sizeof(node_t));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}
void printlist(node_t *head){
    node_t *temp = head;
    int i = 0;
    while (temp != NULL){
        printf("%d ",temp->dest);
        temp = temp->next;
        i++;
    }
}   
void printAdjList(adjlist_t adj[], int size){
    for(int i = 0; i<size;i++){
        printf("Node %d connects to: ",i);
        printlist(adj[i].head);
        printf("\n");
    }
}
/*
1. step: init queue
2. step: Mark source node in visited queue, and enqueue it
3. step: While loop 1 While(front!=rear)
4. step: Init curr to store current from que. 
5. step: Get enqueue all adjacent matrices
*/
void bfs(adjlist_t adj[],int source, int visited[]){
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    visited[source] = 1; 
    queue[rear++] = source; 
    printf("rear first: %d",rear);
    
    while(front<rear){
        printf("\n front: %d rear:%d \n ",front,rear);
        int curr = queue[front++];
        printf("curr: %d ",curr);
        
        node_t* temp = adj[curr].head;
        while (temp != NULL){
            int nabo = temp->dest;
            if (!visited[nabo]){
                visited[nabo]= 1;
                queue[rear++] = nabo;
            }
            temp = temp->next;
        }

        printf("queue: ");
        for(int i=front;i<rear;i++){
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
}


void bfs_init(adjlist_t adj[]){
    int visited[V]; 
    for (int i=0;i<V;i++){
        visited[i] = 0;
    }
    for(int i = 0; i < V;i++){
        if(!visited[i]){
            bfs(adj,i,visited);
        }
    }
}

// Adds edge to the adjlist_t from s to t. 
void addEdge(adjlist_t adj[], int source, int to){
    //Creating an edges from source -> to 
    node_t* newNode = createNode(to);
    newNode->next = adj[source].head;
    adj[source].head = newNode;

    //Since undirected graph this connection from to -> source is also needed. 
    newNode = createNode(source);
    newNode->next = adj[to].head;
    adj[to].head = newNode;
}   


int main(){
    //init the adjacency list 
    adjlist_t adj[V];

    // Create edges array with random connections
    int edges[][2] = {
        {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5},  // Basic path
        {5, 6}, {6, 7}, {7, 8}, {8, 9},          // Complete the circle
        {0, 5}, {1, 6}, {2, 7}, {3, 8}, {4, 9}   // Cross connections
    };


    //init adj to empty
    for(int i=0; i<V; i++){
        adj[i].head = NULL;
    }

    // Populate the adjacency list with edges
    for (int i = 0; i < E; i++) {
        addEdge(adj, edges[i][0], edges[i][1]);
    }

    printAdjList(adj,V);
    printf("\n\n\n\n");

    printf("Printing out BFS on a connected graph above:\n");
    bfs_init(adj);

    return 0;
}