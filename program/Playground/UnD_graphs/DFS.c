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
void dfsRec(adjlist_t adj[], int visited[],int source){
    
    // Sets the current vertex to visted
    visited[source] = 1; 

    // prints the curret vertex
    printf("%d ",source);

    //inits a current pointer to the head
    node_t* current = adj[source].head;

    //While current is not NULL iterate through the adjacency list. 
    while (current!= NULL ) {
        int dest = current->dest;
        //If the vertex has been visited the vertex will be skip at the next vertex in the linked"Sub"list
        if(!visited[dest]){
            dfsRec(adj,visited,dest);
        }
        //Sets the current vertex to the next in line. 
        current = current->next;
    }

}

int search(adjlist_t adj[], int visited[],int source,int target){
    // Sets the current vertex to visted
    visited[source] = 1; 
    // prints the curret vertex
    printf("%d ",source);
    if(source==target){
        return target;
    }
    //inits a current pointer to the head
    node_t* current = adj[source].head;
    int t = -1;
    //While current is not NULL iterate through the adjacency list. 
    while (current!= NULL ) {
        int dest = current->dest;
        //If the vertex has been visited the vertex will be skip at the next vertex in the linked"Sub"list
        if(!visited[dest]){
            t = search(adj,visited,dest,target);
            if (t == target){
                return t;
            }
            else {
                continue;
            }
        }
        //Sets the current vertex to the next in line. 
        current = current->next;
    }
    return -1;
}

// This function init's DFS
// V is the starting Vertex. 
void dfsRec_start(adjlist_t adj[], int V,int s,int to){
    int visited[V];

    for(int i =0;i<10;i++){
        visited[i] = 0; 
    }
    //dfsRec(adj,visited,s);
    search(adj,visited,s,to);
}

// How can it be done non recursively? 
void dfs_NonRec(adjlist_t adj[],int s){
 /* Insert Code*/
}

void dfsNonRec_start(adjlist_t adj[],int V,int s){
    /* Insert Code*/
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

// void insert(node_t* temp1, node_t* temp2,node_t* newNode,int to){
//     if(temp1 == NULL){
//         newNode = 
//     }

//     while(index < to){
//         if (temp2 == NULL){
//             temp1->next=newNode;
//             newNode->next = NULL;
//             return;
//         }
//         temp1 = temp1->next;
//         temp2 = temp2->next;
        
//     }
//     newNode->next = temp2;
// 	temp1->next = newNode;
// }   


// void addEdge_sorted(adjlist_t adj[],int from, int to){
// 	// Adds edge to the adjlist_t from s to t.
// 	// Creating an edges from -> to

// 	node_t* temp = adj[from].head;
//     node_t* temp2 = temp->next;
// 	node_t* newNode = createNode(to);

//     insert(temp,temp2,newNode,to);

// 	//Since undirected graph this connection from to -> source is also needed.
// 	newNode = createNode(from);
// 	newNode->next = adj[to].head;
// 	adj[to].head = newNode;

// }

// 
//
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

    printf("Printing out DFS on a connected graph above:\n ");
    dfsRec_start(adj,V,0,8);

    printf("\n\n\n\n");
    printf("deleting edge 5,6 and printing it out\n");
    deleteEdge(adj,5,6);

    printAdjList(adj,V);
    printf("\n\n\n\n");

    return 0;
}