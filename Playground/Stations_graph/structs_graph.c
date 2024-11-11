#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_STATIONS 8

typedef struct ListNode {
    int dest;
    int weight;
    struct ListNode* next;
} ListNode;

typedef struct Station {
    char name[50];
    ListNode* adj_list_head;
} Station;

typedef struct Graph {
    int num_stations;
    Station** stations;
} Graph;

Station* create_station(char name[]);
void create_linked_list_head(Station* station_head, int index);
void free_adj_list(ListNode* head);
int get_dest(Station** stations, int len, char* name);
void print_adj_list(Graph* network);
ListNode* find_middle_node(ListNode* head);
ListNode* find_least_weight(ListNode* head);

/*
stations.txt ser således ud (den er lavet som simpel test-case):

Aarhus,Randers,30,Aalborg,50,Viborg,129,Haderslev,121,Esbjerg,12,Odense,140,Copenhagen,117
Viborg,Randers,40,Aalborg,80,Aarhus,129,Haderslev,69,Esbjerg,149,Odense,99,Copenhagen,68
Haderslev,Randers,100,Aarhus,121,Viborg,69,Aalborg,57,Esbjerg,89,Odense,92,Copenhagen,123
Randers,Aarhus,30,Viborg,40,Haderslev,100,Aalborg,33,Esbjerg,130,Odense,46,Copenhagen,11
Aalborg,Aarhus,50,Viborg,80,Randers,33,Haderslev,57,Esbjerg,46,Odense,78,Copenhagen,84
Esbjerg,Randers,130,Aarhus,12,Viborg,149,Aalborg,46,Haderslev,89,Odense,91,Copenhagen,48
Odense,Randers,46,Aarhus,140,Viborg,99,Aalborg,78,Haderslev,92,Esbjerg,91,Copenhagen,59
Copenhagen,Randers,11,Aarhus,117,Viborg,68,Aalborg,84,Haderslev,123,Esbjerg,48,Odense,59


Første by på værd linje er hovedet, og efterfølgende er de byer, som hovedet har en edge til samt deres vægte.
*/

int main() {
    Graph* network = (Graph*)malloc(sizeof(Graph));
    network->num_stations = NUM_STATIONS;

    network->stations = (Station**)malloc(sizeof(Station*) * network->num_stations);

    FILE* pF = fopen("fully_connected_graph.txt", "r");

    if (pF == NULL) {
        exit(EXIT_FAILURE);
    }

    char buffer[256];
    int index = 0;

    // Læs stationer ind i vores network->stations array
    while (fgets(buffer, sizeof(buffer), pF)) {
        int len = strlen(buffer);

        if (buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }

        // strtok() samler input indtil første komma
        char* station_name = strtok(buffer, ",");

        network->stations[index] = create_station(station_name);

        index++;
    }

    rewind(pF);

    // Indlæs og lav vores linked lists for hver af stationerne i network->stations
    index = 0;
    while (fgets(buffer, sizeof(buffer), pF)){
        int len = strlen(buffer);
        if (buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }

        // Læg mærke til, hvordan vi håndterer linjen i filen. Vi skal jo gøre noget forskelligt alt efter
        // om det er en vægt eller en station der skal indlæses
        int numeric = 0;
        int curr_dest = -1;
        char* curr;

        // Start med at lave hovedet på listen
        curr = strtok(buffer, ",");
        create_linked_list_head(network->stations[index], index);
        ListNode* last_node = network->stations[index]->adj_list_head;

        // Gennemgå linje i filen og lav den linkede liste
        // strtok() samler input indtil næste komma, og placerer NULL på dets plads, som den starter ved igen
        // ved næste kald (da vi fortæller den, at det skal den gøre)

        // Logikken bliver lang at forklare her, så det bliver når vi gennemgår koden, men prøv at regne det ud!
        while ((curr = strtok(NULL, ",")) != NULL) {
            if (numeric == 0) {
                curr_dest = get_dest(network->stations, NUM_STATIONS, curr);
                if (curr_dest == -1) {
                    fprintf(stderr, "Station '%s' not found.\n", curr);
                    break;
                }
                numeric = 1;
            } 
            else {
                ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
                new_node->dest = curr_dest;
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

    print_adj_list(network);

    /*
    Output:
    Randers [Randers (Weight: 0) -> Aarhus (Weight: 30) (Dest: 1) -> Viborg (Weight: 40) (Dest: 2) -> Haderslev (Weight: 100) (Dest: 4)]
    Aarhus [Aarhus (Weight: 0) -> Aalborg (Weight: 50) (Dest: 3) -> Randers (Weight: 30) (Dest: 0)]
    Viborg [Viborg (Weight: 0) -> Randers (Weight: 40) (Dest: 0) -> Aalborg (Weight: 80) (Dest: 3)]
    Aalborg [Aalborg (Weight: 0) -> Aarhus (Weight: 50) (Dest: 1) -> Viborg (Weight: 80) (Dest: 2)]
    Haderslev [Haderslev (Weight: 0) -> Randers (Weight: 100) (Dest: 0)]
    */

   

    for (int i = 0; i < NUM_STATIONS; i++) {
        free_adj_list(network->stations[i]->adj_list_head);
        free(network->stations[i]);
    }

    free(network->stations);
    free(network);

    return 0;
}

Station* create_station(char name[]){
    Station* new_station = (Station*)malloc(sizeof(Station));
    strcpy(new_station->name, name);
    new_station->adj_list_head = NULL;

    return new_station;
}

void create_linked_list_head(Station *station_head, int index){
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    head->next = NULL;
    head->weight = 0;
    head->dest = index;
    station_head->adj_list_head = head;
}

void free_adj_list(ListNode* head){
    ListNode* temp;
    while (head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
}

int get_dest(Station** stations, int len, char* name){
    for (int i = 0; i < len; i++) {
        if (strcmp(stations[i]->name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void print_adj_list(Graph* network){
    for (int i = 0; i < network->num_stations; i++) {
        Station* station = network->stations[i];
        printf("%s", station->name);
        printf(" [");
        printf("%s (Weight: %d)", station->name, 0);
        ListNode *current = station->adj_list_head->next;
        while (current != NULL){
            printf(" -> %s (Weight: %d) (Dest: %d)", network->stations[current->dest]->name, current->weight, current->dest);
            current = current->next;
        }
        printf("]");
        printf("\n");
    }
}

ListNode* find_middle_node(ListNode* head){
    ListNode* slow = head,* fast = head;

    while (fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

ListNode* find_least_weight(ListNode* head){
    ListNode* min = head->next;
    head = head->next;

    if (min == NULL){
        return NULL;
    }

    while (head->next){
        if (min->weight > head->next->weight){
            min = head->next;
        }
        head = head->next;
    }
    return min;
}