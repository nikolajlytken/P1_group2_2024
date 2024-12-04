#include "min_heap/min_heap.h"

int path_find_init(Station** stations, int source, int target, int num_nodes);
int compute_path(Station** stations, MinHeap* heap, int* path_sums, int source, int target);