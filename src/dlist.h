
#ifndef DLIST_H_
#define DLIST_H_

#include <stdbool.h>

typedef struct DoublyEndedList dlist_t;
typedef struct DoublyEndedNode dnode_t;

struct DoublyEndedList {
    dnode_t* front;
    dnode_t* rear;
};

struct DoublyEndedNode {
    dnode_t* left;
    void* element;
    dnode_t* right;
};

dlist_t* alloc_dlist();

dnode_t* alloc_dnode();

void free_node(dnode_t* node);

void free_list(dlist_t* list);

bool is_empty(dlist_t* list);

void append_right(dlist_t* list, void* element);

void append_left(dlist_t* list, void* element);

void set(dlist_t* list, int index, void* element);

void* pop_right(dlist_t* list);

void* pop_left(dlist_t* list);

void* get(dlist_t* list, int index);

#endif // DLIST_H_
