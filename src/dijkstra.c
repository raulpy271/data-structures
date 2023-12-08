
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>
#include "dlist.h"
#include "priority_queue.h"
#include "dijkstra.h"


vertex_t* alloc_weighted_vertex(unsigned int vertex, size_t size, ...) {
    vertex_t* vrt = malloc(sizeof (vertex_t));
    vrt->value = vertex;
    vrt->distance = INFINITY;
    vrt->pred = NULL;
    vrt->adj_size = size;
    vrt->adj = alloc_dlist();
    va_list ap;
    va_start(ap, size);
    for (int i = 0; i < size; i++) {
        adj_member_t* member = malloc(sizeof(adj_member_t));
        member->adj_value = va_arg(ap, unsigned int);
        member->weight = va_arg(ap, double);
        append_right(vrt->adj, (void*) member);
    }
    va_end(ap);
    return vrt;
}

void free_vertices(vertex_t** adj, size_t size) {
    for (int i = 0; i < size; i++) {
        free_list(adj[i]->adj);
        free(adj[i]);
    }
}

void initialize_single_source(graph_t* graph, vertex_t* source) {
    for (int i = 0; i < graph->size; i++) {
        graph->adj[i]->distance = INFINITY;
        graph->adj[i]->pred = NULL;
    }
    source->distance = 0;
}

void relax(vertex_t* u, vertex_t* v, double weight) {
    if (isinf(u->distance) && isinf(v->distance)) {
        return;
    }
    if (v->distance > (u->distance + weight)) {
        v->distance = u->distance + weight;
        v->pred = u;
    }
}

bool smallest_vertex(void* a, void* b) {
    return ((vertex_t*) a)->distance < ((vertex_t*) b)->distance;
}

void dijkstra(graph_t* graph, vertex_t* source) {
    initialize_single_source(graph, source);
    vertex_set_t* set = alloc_empty_set(graph->size);
    node_t* queue = alloc_node();
    for (int i = 0; i < graph->size; i++) {
        vertex_t* vrt = graph->adj[i];
        insert(&queue, vrt);
    }
    while (!is_empty_queue(queue)) {
        vertex_t* vrt = pop(&queue, smallest_vertex);
        union_vertex(set, vrt);
        for (int i = 0; i < vrt->adj_size; i++) {
            adj_member_t* member = get(vrt->adj, i);
            vertex_t* vrt_adj = get_vertex(graph, member->adj_value);
            relax(vrt, vrt_adj, member->weight);
        }
    }
    free_vertex_set(set);
}

vertex_t* get_vertex(graph_t* graph, unsigned int vertex_value) {
    for (int i = 0; i < graph->size; i++) {
        if (graph->adj[i]->value == vertex_value)
            return graph->adj[i];
    }
    return NULL;
}

vertex_set_t* alloc_empty_set(size_t max_size) {
    vertex_set_t* set = malloc(sizeof(vertex_set_t));
    vertex_t** vertex = malloc(sizeof(vertex_t*) * max_size);
    for (int i = 0; i < max_size; i++) {
        vertex[i] = NULL;
    }
    set->vertex = vertex;
    set->max_size = max_size;
    return set;
}

void union_vertex(vertex_set_t* set, vertex_t* vertex) {
    int empty_index = -1;
    for (int i = 0; i < set->max_size; i++) {
        if (set->vertex[i] == NULL) {
            empty_index = i;
        } else {
            if (set->vertex[i] == vertex) {
                return;
            }
        }
    }
    if (empty_index >= 0) {
        set->vertex[empty_index] = vertex;
    }
}

void free_vertex_set(vertex_set_t* set) {
    free(set->vertex);
    free(set);
}

