#include "data_to_graph.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Graph* create_graph(char* filename, int num_stations){
	Graph* network = (Graph*)malloc(sizeof(Graph));
    network->num_stations = num_stations;

    network->stations = (Station**)malloc(sizeof(Station*) * network->num_stations);

    FILE* pF = fopen(filename, "r");

    if (pF == NULL) {
        exit(EXIT_FAILURE);
    }

    char buffer[256];
    int index = 0;

    while (fgets(buffer, sizeof(buffer), pF)) {
        int len = strlen(buffer);

        if (buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }

        if (index >= num_stations) {
            printf("Number of stations in file does not match expected amount. Program will now exit.\n");
            for (int i = 0; i < index; i++){
                free(network->stations[i]);
            }
            free(network);
            exit(EXIT_FAILURE);
        }
        char* station_name = strtok(buffer, ",");
        network->stations[index] = create_station(station_name);

        index++;
    }

    if (index < num_stations - 1) {
            printf("Number of stations in file does not match expected amount. Program will now exit.\n");
            for (int i = 0; i < index; i++){
                free(network->stations[i]);
            }
            free(network);
            exit(EXIT_FAILURE);
        }

    rewind(pF);

    index = 0;
    while (fgets(buffer, sizeof(buffer), pF)){
        int len = strlen(buffer);
        if (buffer[len - 1] == '\n'){
            buffer[len - 1] = '\0';
        }
        int numeric = 0;
        int curr_idx = -1;
        char* curr;

        curr = strtok(buffer, ",");
        create_linked_list_head(network->stations[index], index);
        ListNode* last_node = network->stations[index]->list_head;

        while ((curr = strtok(NULL, ",")) != NULL) {
            if (numeric == 0) {
                curr_idx = get_idx(network->stations, network->num_stations, curr);
                if (curr_idx == -1) {
                    printf("Station '%s' not found.\n", curr);
                    break;
                }
                numeric = 1;
            } 
            else {
                ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
                new_node->idx_in_arr = curr_idx;
                new_node->weight = atoi(curr);
                new_node->next = NULL;
                last_node->next = new_node;
                last_node = new_node;
                numeric = 0;
            }
        }
        index++;
    }
    fclose(pF);

    return network;
}

Station* create_station(char name[]){
    Station* new_station = (Station*)malloc(sizeof(Station));
    strcpy(new_station->name, name);
    new_station->list_head = NULL;

    return new_station;
}

void create_linked_list_head(Station *station_head, int index){
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    head->next = NULL;
    head->weight = 0;
    head->idx_in_arr = index;
    station_head->list_head = head;
}

void free_adj_list(ListNode* head){
    ListNode* temp;
    while (head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
}

int get_idx(Station** stations, int len, char* name){
    for (int i = 0; i < len; i++) {
        if (strcmp(stations[i]->name, name) == 0){
            return i;
        }
    }
    return -1;
}

void print_adj_list(Graph* network){
    for (int i = 0; i < network->num_stations; i++){
        Station* station = network->stations[i];
        printf("%s", station->name);
        printf(" [");
        printf("%s (Weight: %d)", station->name, 0);
        ListNode *current = station->list_head->next;
        while (current != NULL){
            printf(" -> %s (weight: %d) (idx_in_arr: %d)", network->stations[current->idx_in_arr]->name, current->weight, current->idx_in_arr);
            current = current->next;
        }
        printf("]");
        printf("\n\n");
    }
}




