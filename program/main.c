#include "data_to_graph.h"
#include "traverse.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
	printf("Reading data and initializing graph..\n");
	Graph* network = create_graph(argv[1], atoi(argv[2]));
	printf("...\n");
	printf("Graph visually as adjacency-list: \n");
	print_adj_list(network);

	int source_node = get_idx(network->stations, network->num_stations, argv[3]);
	int target_node = get_idx(network->stations, network->num_stations, argv[4]);
	Station* source_station = network->stations[source_node];
	Station* target_station = network->stations[target_node];

	int visited_dfs[network->num_stations];
	int visited_bfs[network->num_stations];
	int path_dfs[network->num_stations];
	int path_bfs[network->num_stations];

	for (int j = 0; j < network->num_stations; j++){
		visited_dfs[j] = 0;
		visited_bfs[j] = 0;
		path_dfs[j] = -1;
		path_bfs[j] = -1;
	}

	char temp;

	scanf(" %c", &temp);

	printf("Finding path from %s to %s with DFS..\n\n", source_station->name, target_station->name);
	printf("DFS found path below:\n");
	int dfs_index = dfs(network->stations, source_node, target_node, visited_dfs, path_dfs, 0);
	for (int j = 0; j <= dfs_index; j++){
		printf(" %s", network->stations[path_dfs[j]]->name);
		if (j < dfs_index){
			printf(", ");
		}
	}
	printf("\nOf length: %d", dfs_index + 1);

	printf("\n\n");

	scanf(" %c", &temp);

	printf("Finding path from %s to %s with BFS..\n\n", source_station->name, target_station->name);
	printf("BFS found path below:\n");
	int bfs_len = bfs(network->stations, visited_bfs, source_node, target_node, path_bfs, network->num_stations);
	for (int i = bfs_len - 1; i >= 0; i--){
		printf(" %s", network->stations[path_bfs[i]]->name);
		if (i > 0){
			printf(", ");
		}
	}
	printf("\nOf length: %d", bfs_len);
	printf("\n");

	for (int i = 0; i < network->num_stations; i++){
		free_adj_list(network->stations[i]->list_head);
		free(network->stations[i]);
	}
	free(network);
}




