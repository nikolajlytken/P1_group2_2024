#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NODES 100 // Our number of nodes

void DFS(int node, int n, int adj_matrix[MAX_NODES][MAX_NODES], int visited[MAX_NODES]);
void BFS(int start_node, int num_nodes, int adjMatrix[MAX_NODES][MAX_NODES], int visited[MAX_NODES]);
int is_graph_connected(int n, int adj_matrix[MAX_NODES][MAX_NODES]);

// Depth-First-Search
void DFS(int node, int num_nodes, int adj_matrix[MAX_NODES][MAX_NODES], int visited[MAX_NODES]) {
    visited[node] = 1; // Mark current node as visited

    // Check every potential node that current node could have an edge to
    // If there exists an edge, and next node (after going through that edge) is not in visited,
    // we recursively go to that edge, and check for new nodes we can go to
    // If we hit a dead end, we go to prior function call and continue
    for (int i = 0; i < num_nodes; i++) {
        if (adj_matrix[node][i] == 1 && !visited[i]){
            DFS(i, num_nodes, adj_matrix, visited);
        }
    }
    // If every node has been visited during our recursion, the graph is connected
}

// Breatdh-First-Search
void BFS(int start_node, int num_nodes, int adj_matrix[MAX_NODES][MAX_NODES], int visited[MAX_NODES]) {
    int queue[MAX_NODES];
    // Variables that represents the index of our "front element" and "last element" in the queue
    int front = 0, back = 0;

    // Put start node in queue and mark as visited
    back++;
    queue[back] = start_node;
    visited[start_node] = 1;

    // Essentially the same as "while queue is not empty"
    while (front < back){
    	// Move to the next element in the queue, and make that the current node
    	front++;
        int node = queue[front];

        // Check every node current node connects to, put in queue and mark as visited, since it can be reached
        for (int i = 0; i < n; i++){
            if (adj_matrix[node][i] == 1 && !visited[i]) {
            	back++;
                queue[back] = i;
                visited[i] = 1;
            }
        }
    }
}

// Fucntion to abstract checking if graph is connected
int is_graph_connected(int num_nodes, int adj_matrix[MAX_NODES][MAX_NODES]) {
	// Initialize our array, where visited[i] = 1 if i node has been visited during our traversal trough the "graph"
	// We of course set every node to zero as we are yet to visit any
    int visited[MAX_NODES] = {0}; 

    // Call DFS (which node we choose actually doesnt matter since the graph is undirected)
    // Could swap with BFS()
    DFS(0, num_nodes, adj_matrix, visited);

    // Simply check every node in visited. If any has not been visited, graph is unconnected
    for (int i = 0; i < num_nodes; i++){
        if (!visited[i]) {
            return 0; 
        }
    }
    return 1;
}

int main(){

	return 0;
}
