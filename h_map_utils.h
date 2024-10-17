// Functions to abstract adding, retrieving and freeing memory of hash_tables
void add_edge_weight(int vertex1, int vertex2, int weight);
void add_index_name(int index, char *name);
void add_name_index(char *name, int index);
int get_edge_weight(int vertex1, int vertex2);
char* get_station_name(int index);
int get_station_index(char *name);
void free_names_index();
void free_index_names();
void free_edge_weights();