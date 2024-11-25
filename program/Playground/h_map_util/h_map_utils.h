// Functions to abstract adding key-value pairs, looking up in tables, and freeing memory.
void add_edge_weight(int vertex1, int vertex2, int weight);
void add_index_name(int index, char *name);
void add_name_index(char *name, int index);
int get_edge_weight(int vertex1, int vertex2);
char* get_station_name(int index);
int get_station_index(char *name);
void free_names_index();
void free_index_names();
void free_edge_weights();
