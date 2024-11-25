#define MAX_SIZE 100
#define NUM_STATIONS 8

typedef struct {
    int node;
    int distance;
} HeapNode;

typedef struct {
    HeapNode data[MAX_SIZE];
    int positions[MAX_SIZE];
    int size;
} MinHeap;

void swap(MinHeap *heap, int index1, int index2, int *positions);
MinHeap* initialize_heap(int source, int num_nodes);
void heapify_down(MinHeap* heap, int index);
HeapNode extract_min(MinHeap *heap);
void heapify_up(MinHeap* heap, int index, int* positions);
void insert_element(MinHeap* heap, HeapNode value, int* positions);
void decrease_node_val(MinHeap* heap, int node_index, int new_distance, int* positions);
