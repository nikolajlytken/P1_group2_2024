#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "h_map_utils.h"

// Should be stressed that i have tested program on my machine

int main(){
	// Hypothetical file where each station is listed one at a line
	FILE *stationFile = fopen("stations.txt", "r");
	char buffer[256];

	int index = 0;
	int len;

	while (fgets(buffer, sizeof(buffer), stationFile)){
		len = strlen(buffer);

		if (buffer[len - 1] == '\n'){
			buffer[len - 1] = '\0';
			len--;
		}

		add_index_name(index, buffer);
		add_name_index(buffer, index);
		index++;
	}
	fclose(stationFile);

	// Hypothetical file where every connection to corresponding station 
	// at same line in file above is listed and to the right the weight.
	// Example: 
	// line 1 (stations.txt): Berlin
	// line 1 (connects_to.txt): Paris,11,London,25
	FILE *stationEdges = fopen("connects_to.txt", "r");

	int adj_matrix[index + 1][index + 1];
	for (int i = 0; i <= index; i++){
		for (int j = 0; j <= index; j++){
			adj_matrix[i][j] = 0;
		}
	}

	index = 0;
	int flag = 1;

	while (fgets(buffer, sizeof(buffer), stationFile)){
		len = strlen(buffer);

		if (buffer[len - 1] == '\n'){
			buffer[len - 1] = '\0';
			len--;
		}
		char *curr = strtok(buffer, ",");
		char *prev;
		while (curr != NULL){
			if (flag){
				adj_matrix[index][get_station_index(curr)] = 1;
				adj_matrix[get_station_index(curr)][index] = 1;
				prev = curr;
				curr = strtok(NULL, ",");
				flag = 0;
			}
			else {
				add_edge_weight(index, get_station_index(prev), atoi(curr));
				curr = strtok(NULL, ",");
				flag = 1;
			}
		}
		index++;
	}
	fclose(stationEdges);

	free_names_index();
	free_index_names();
	free_edge_weights();

	return 0;
}