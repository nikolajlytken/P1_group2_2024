#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int dest;
    struct Node* next;
} node_t;

// Used to define an array on of adjacencyList
typedef struct Adjlist{
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

// Recursive function, that is called by the dfs function. 
// step 1: It marks vertex as visited, 
// step 2: It prints the current vertex
// step 3: Calls it self recursively with the next vertex. 
void dfsRec(adjlist_t adj[],int visited[], int pre[],int post[],int s,int* vi){
    
    // Sets the current vertex to visted
    ++*vi; 
    pre[s] = *vi;

    // prints the curret vertex
    visited[s] = 1;
    printf("%d ",s);

    //inits a current pointer to the head
    node_t* current = adj[s].head;

    //While current is not NULL iterate through the adjacency list. 
    while (current!= NULL ) {
        int dest = current->dest;
        //If the vertex has been visited the vertex will be skip at the next vertex in the linked"Sub"list
        if(!visited[dest]){
            dfsRec(adj,visited,pre,post,dest,vi);
        }
        //Sets the current vertex to the next in line. 
        current = current->next;
    }
    ++*vi;
    post[s] = *vi;
}

void topological_sort(adjlist_t adj[],int pre[],int post[]){
    /* */
}


// This function init's DFS
// V is the starting Vertex. 
void dfs_init(adjlist_t adj[], int V,int s){
    int visited[V];
    int pre[V];
    int post[V];
    int visited_index = 0;

    for(int i =0;i<10;i++){
        visited[i] = 0;
        pre[i] = 0;
        post[i] = 0; 
    }
    dfsRec(adj,visited,pre,post,s,&visited_index);
    printf("\n");
    for(int i = 0; i<V;i++){
        printf("Element %d was first visited %d, and finished %d \n",i,pre[i],post[i]);
    }
}


// Adds edge to the adjlist_t from s to t. 
void addEdge(adjlist_t adj[], int source, int to){
    //Creating an edges from source -> to 
    node_t* newNode = createNode(to);
    newNode->next = adj[source].head;
    adj[source].head = newNode;

    // Since undirected graph this connection from to -> source is also needed. 
    // newNode = createNode(source);
    // newNode->next = adj[to].head;
    // adj[to].head = newNode;
}


void deleteEdge(adjlist_t adj[],int from, int to){
	node_t *temp = adj[from].head;
    node_t *temp2 = adj[from].head;

	temp2 = temp2->next;
	while(temp2->dest != to){
		temp = temp->next;
        temp2 = temp2->next;
	}
	temp->next = temp2->next;

    temp = adj[to].head;
    temp2 = adj[to].head;

	temp2 = temp2->next;
	while(temp2->dest != from){
		temp = temp->next;
        temp2 = temp2->next;
	}
	temp->next = temp2->next;
}

int main(){
    // Increase nodes to 10
    int V = 10, E = 14;
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

    printf("Printing out DFS starting from 0: \n ");
    dfs_init(adj,V,0);

    printf("Printing out DFS starting from 3: \n ");
    dfs_init(adj,V,3);

    printf("\n\n\n\n");
    printf("deleting edge 5,6 and printing it out\n");
    deleteEdge(adj,5,6);

    printAdjList(adj,V);
    printf("\n\n\n\n");

    return 0;
}