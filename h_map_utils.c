#include <stdio.h>
#include <stdlib.h>
// Library for hash-mapping
#include <uthash.h>
#include "h_map_utils.h"

/*
Short explanation of uthash library:
Create a struct consisting of a key, and the value you want associated with each key.
Each structure that is to be stored in the hash table must include a special field of type UT_hash_handle. 
This field allows uthash to manage the hash table internally.
*/

/*
Parameters for functions in uthash.h:

HASH_ADD Parameters:
1. hh: The name of the UT_hash_handle field in your structure (commonly hh).
2. head: Pointer to the head of the hash table.
3. keyfield_name: The name of the field in your structure that contains the key.
4. keylen: Length of the key in bytes.
5. add_item_ptr: Pointer to the item to be added to the hash table.

HASH_FIND Parameters:
1. hh: The name of the UT_hash_handle field within your structure.
2. head: A pointer to the head of the hash table.
3. keyptr: A pointer to the key data used for hashing.
4. keylen_in: The length of the key in bytes.
5. out: A pointer to a variable where the found item will be stored.

HASH_ITER Parameters:
1. hh_name: The name of the UT_hash_handle field.
2. head: A pointer to the head of the hash table.
3. el: A pointer variable used as the loop iterator. 
During iteration el will point to each element in the hash table.
4. tmp: A temporary pointer variable used to store the next element in the hash table
example for safe deletion.

HASH_DEL Parameters:
1. head: Pointer to hash-table item should be deleted from.
2. delptr: Pointer to the element that you want to delete from the hash table.
*/

// Hash-table-struct mapping an array of two vertices (an edge) to a weight
typedef struct edgeWeight {
	int edge[2]; // Key
	int weight; // Value
	UT_hash_handle hh; // UT_hash_handle field for internal operations
} edgeWeight;

// Hash-table-struct mapping an integer (index in the adjacency matrix) to the name of the station
// the index represents
typedef struct indexToName {
	int index;
	char *name;
	UT_hash_handle hh;
} indexToName;

typedef struct nameToIndex {
    char *name;
    int index;
    UT_hash_handle hh;
} nameToIndex;

// Our global hash-tables
edgeWeight *edge_weights = NULL; 
indexToName *index_to_name = NULL;
nameToIndex *name_to_index = NULL;


/*
int main() {
    add_edge_weight(1, 2, 10);
    add_edge_weight(2, 3, 15);

    add_index_name(1, "Mexico City");
    add_index_name(2, "Ballerup");

    int weight = get_edge_weight(1, 2);
    if (weight != -1) {
        printf("Weight between node 1 and 2: %d\n", weight);
    } else {
        printf("Edge not found.\n");
    }

    char *name = get_station_name(1);
    if (name) {
        printf("Station name at index 1: %s\n", name);
    } else {
        printf("Station not found.\n");
    }

    free_edge_weights();
    free_index_names();

    return 0;
}
*/

void add_edge_weight(int vertex1, int vertex2, int weight) {
	// Allocate memory for new edge
    edgeWeight *ew = malloc(sizeof(edgeWeight));
    if (ew == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    // Initialize the edge with its corresponding weight
    ew->edge[0] = vertex1;
    ew->edge[1] = vertex2;
    ew->weight = weight;

    // Add new key-value pair to our global hash-table
    // hh: UT_hash_handle field in the struct, edge_weights: global table, 
    // edge: the key field in the struct,
    // sizeof(int) * 2: length of the key in bytes, ew: item to be added
    HASH_ADD(hh, edge_weights, edge, sizeof(int) * 2, ew);
}

// Same as add_edge_name
void add_index_name(int index, char *name) {
    indexToName *in = malloc(sizeof(indexToName));
    if (in == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    in->index = index;

    in->name = strdup(name); // Allocate memory and copy string
    if (in->name == NULL) {
        perror("Failed to allocate memory for name");
        free(in);
        exit(EXIT_FAILURE);
    }

    HASH_ADD(hh, index_to_name, index, sizeof(int), in);
}

// Same as above
void add_name_index(char *name, int index){
    nameToIndex *ni = malloc(sizeof(nameToIndex));
    if (ni == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    ni->name = strdup(name);
    if (ni->name == NULL) {
        perror("Failed to allocate memory for name");
        free(ni);
        exit(EXIT_FAILURE);
    }

    ni->index = index;

    HASH_ADD(hh, name_to_index, name, strlen(ni->name), ni);
}

int get_edge_weight(int vertex1, int vertex2) {
	// create temporary struct to hold the return val of HASH_FIND
    edgeWeight *ew = NULL;
    // edge we are looking for
    int edge[2] = {vertex1, vertex2};

    // hh: UT_hash_handle field, edge_weights: table we are searching, 
    // edge: key we are looking for (a pointer, which the function expects),
    // sizeof(int) * 2: lenght of key in bytes, ew: where found item will be stored
    HASH_FIND(hh, edge_weights, edge, sizeof(int) * 2, ew);

    // If key is found, return its value (weight), else return -1
    if (ew) {
        return ew->weight;
    } else {
        return -1;
    }
}

// Same as get_edge_weight. Remember, this returns a pointer to the start of the string
char* get_station_name(int index) {
    indexToName *in = NULL;

    HASH_FIND(hh, index_to_name, &index, sizeof(int), in);

    if (in) {
        return in->name;
    } else {
        return NULL;
    }
}

// Same as above
int get_station_index(char *name){
    nameToIndex *ni = NULL;

    HASH_FIND(hh, name_to_index, name, strlen(name), ni);

    if (ni) {
        return ni->index;
    } else {
        return -1;
    }
}


void free_index_names() {
	// variables to hold current element and next during iteration
    indexToName *current, *temp;

    // function for iteration through hash-table
    // hh: UT_hash_handle field, index_to_name: table we want to delete,
    // current,temp: explained above 
    HASH_ITER(hh, index_to_name, current, temp) {
    	// delete (or actually unlink) key-value struct (which current points to)
        HASH_DEL(index_to_name, current);
        // free memory
        free(current->name);
        free(current);
    }
}

// Same as free_index_names
void free_edge_weights() {
    edgeWeight *current, *temp;

    HASH_ITER(hh, edge_weights, current, temp) {
        HASH_DEL(edge_weights, current);
        free(current);
    }
}

void free_names_index(){
    nameToIndex *current, *temp;

    HASH_ITER(hh, name_to_index, current, temp) {
        HASH_DEL(name_to_index, current);
        free(current->name);
        free(current);
    }
}




