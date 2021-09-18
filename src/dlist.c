#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#include "dlist.h"

bool is_empty(dlist_t* list) {
    return list->front == NULL && list->rear == NULL;
}

void free_node(dnode_t* node) {
    free(node);
}

void free_list(dlist_t* list) {
    dnode_t* next = NULL;
    dnode_t* current_node = list->front;
    while (current_node != NULL) {
        next = current_node->right;
        free_node(current_node);
        current_node = next;
    }
}

dnode_t* alloc_dnode() {
    dnode_t* new_node = malloc(sizeof (dnode_t));
    new_node->left = NULL;
    new_node->element = NULL;
    new_node->right = NULL;
    return new_node;
}

dlist_t* alloc_dlist() {
    dlist_t* new_list = malloc(sizeof (dlist_t));
    new_list->front = NULL;
    new_list->rear = NULL;
    return new_list;
}

void append_right(dlist_t* list, void* element) {
    dnode_t* new_node = alloc_dnode();
    new_node->element = element;
    new_node->right = NULL;
    if (is_empty(list)) {
        new_node->left = NULL;
        list->front = new_node;
    } else {
        new_node->left = list->rear;
        list->rear->right = new_node;
    }
    list->rear = new_node;
}

void append_left(dlist_t* list, void* element) {
    dnode_t* new_node = alloc_dnode();
    new_node->element = element;
    new_node->left = NULL;
    if (is_empty(list)) {
        new_node->right = NULL;
        list->rear = new_node;
    } else {
        new_node->right = list->front;
        list->front->left = new_node;
    }
    list->front = new_node;
}

void* get(dlist_t* list, int index) {
    dnode_t* current_node = list->front;
    while (index > 0) {
        if (current_node->right == NULL) {
            return NULL;
        }
        current_node = current_node->right;
        index--;
    }
    return current_node->element;
}

void set(dlist_t* list, int index, void* new_element) {
    dnode_t* current_node = list->front;
    while (index > 0) {
        if (current_node->right == NULL) {
            return;
        }
        current_node = current_node->right;
        index--;
    }
    current_node->element = new_element;
}

void* pop_right(dlist_t* list) {
    dnode_t* last = list->rear;
    void* element = last->element;
    list->rear = last->left;
    if (list->rear != NULL) {
        list->rear->right = NULL;
    } else {
        list->front = NULL;
    }
    free_node(last);
    return element;
}

void* pop_left(dlist_t* list) {
    dnode_t* first = list->front;
    void* element = first->element;
    list->front = first->right;
    if (list->front != NULL) {
        list->front->left = NULL;
    } else {
        list->rear = NULL;
    }
    free_node(first);
    return element;
}

