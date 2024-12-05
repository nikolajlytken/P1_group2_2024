#pragma once

typedef struct ListNode {
    int idx_in_arr;
    int weight;
    int edge_id;
    int times_visited;
    struct ListNode* next;
} ListNode;

typedef struct Station {
    char name[50];
    ListNode* list_head;
} Station;

typedef struct Graph {
    int num_stations;
    Station** stations;
} Graph;

Graph* create_graph(char* filename, int num_stations);
Station* create_station(char name[]);
void create_linked_list_head(Station* station_head, int index);
void free_adj_list(ListNode* head);
int get_idx(Station** stations, int len, char* name);
void print_adj_list(Graph* network);
ListNode* find_edge_by_id(Graph* network, int edge_id);