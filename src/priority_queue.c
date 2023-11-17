#include <stdlib.h>

#include "priority_queue.h"

node_t* alloc_node() {
    queue_t node = malloc(sizeof (node_t));
    node->element = NULL;
    node->next = NULL;
    return node;
}

bool is_empty_queue(queue_t queue) {
    return queue->element == NULL;
}

void pop_current(node_t* node) {
    node_t* next = node->next;
    node->element = next->element;
    node->next = next->next;
    free(next);
}

void* pop(queue_t* queue, bool (* compare_priority_of)(void*, void*)) {
    node_t* higher_priority = *queue;
    node_t* next = (*queue)->next;
    void* popped_element = NULL;
    while (!is_empty_queue(next)) {
        if (!compare_priority_of(higher_priority->element, next->element)) {
            higher_priority = next;
        }
        next = next->next;
    }
    popped_element = higher_priority->element;
    pop_current(higher_priority);
    return popped_element;
}

void insert(queue_t* queue, void* element) {
    node_t* node = alloc_node();
    node->element = element;
    node->next = *queue;
    *queue = node;
};

bool in_queue(queue_t queue, void* element) {
    while(!is_empty_queue(queue)) {
        if (queue->element == element) {
            return true;
        }
        queue = queue->next;
    }
    return false;
}

