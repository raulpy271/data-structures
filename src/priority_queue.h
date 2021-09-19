#include <stdbool.h>

typedef struct Node node_t;
typedef node_t* queue_t;

struct Node {
    void* element;
    node_t* next;
};


node_t* alloc_node();

bool is_empty(queue_t);

/* 
 * Return and remove from the queue the element with have most priority. 
 * 
 * The function `compare_priority_of` stablish a way to define the prioriry of elements. It should return true if the first element have most priority over the second.
 *
 */
void* pop(queue_t*, bool (* compare_priority_of)(void*, void*));

void insert(queue_t*, void*);


