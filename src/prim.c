
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include "prim.h"
#include "priority_queue.h"

vertex_t* alloc_weighted_vertex(unsigned int vertex, size_t size, ...) {
    vertex_t* vrt = malloc(sizeof (vertex_t));
    vrt->value = vertex;
    vrt->key = UINT_MAX;
    vrt->pred = NULL;
    vrt->adj_size = size;
    vrt->adj = alloc_dlist();
    va_list ap;
    va_start(ap, size);
    for (int i = 0; i < size; i++) {
        adj_member_t* member = malloc(sizeof(adj_member_t));
        member->adj_value = va_arg(ap, unsigned int);
        member->weight = va_arg(ap, unsigned int);
        append_right(vrt->adj, (void*) member);
    }
    va_end(ap);
    return vrt;
}

bool smallest_vertex(void* a, void* b) {
    return ((vertex_t*) a)->key < ((vertex_t*) b)->key;
}

edges_set_t* mst_prim(graph_t* graph, vertex_t* root) {
    for (int i = 0; i < graph->size; i++) {
        vertex_t* vrt = graph->adj[i];
        vrt->key = UINT_MAX;
        vrt->pred = NULL;
    }
    root->key = 0;
    node_t* queue = alloc_node();
    for (int i = 0; i < graph->size; i++) {
        vertex_t* vrt = graph->adj[i];
        insert(&queue, vrt);
    }
    while (!is_empty_queue(queue)) {
        vertex_t* vrt = pop(&queue, smallest_vertex);
        for (int i = 0; i < vrt->adj_size; i++) {
            adj_member_t* member = get(vrt->adj, i);
            vertex_t* vrt_adj = get_vertex(graph, member->adj_value);
            if (in_queue(queue, vrt_adj) && member->weight < vrt_adj->key) {
                vrt_adj->pred = vrt;
                vrt_adj->key = member->weight;
            }
        }
    }
    edges_set_t* set_a = alloc_empty_set(graph->size - 1);
    for (int i = 0; i < graph->size; i++) {
        vertex_t* vrt = graph->adj[i];
        if (vrt != root) {
            weighted_edge_t* edge = malloc(sizeof(weighted_edge_t));
            edge->u = vrt;
            edge->v = vrt->pred;
            edge->weight = vrt->key;
            union_edge(set_a, edge);
        }
    }

    return set_a;
}

edges_set_t* alloc_empty_set(size_t max_size) {
    edges_set_t* set = malloc(sizeof(edges_set_t));
    weighted_edge_t** edges = malloc(sizeof(weighted_edge_t*) * max_size);
    for (int i = 0; i < max_size; i++) {
        edges[i] = NULL;
    }
    set->edges = edges;
    set->max_size = max_size;
    return set;
}

void union_edge(edges_set_t* set, weighted_edge_t* edge) {
    int empty_index = -1;
    for (int i = 0; i < set->max_size; i++) {
        if (set->edges[i] == NULL) {
            empty_index = i;
        } else {
            if (set->edges[i] == edge) {
                return;
            }
        }
    }
    if (empty_index >= 0) {
        set->edges[empty_index] = edge;
    }
}

void free_vertices(vertex_t** adj, size_t size) {
    for (int i = 0; i < size; i++) {
        free_list(adj[i]->adj);
        free(adj[i]);
    }
}

vertex_t* get_vertex(graph_t* graph, unsigned int vertex_value) {
    for (int i = 0; i < graph->size; i++) {
        if (graph->adj[i]->value == vertex_value)
            return graph->adj[i];
    }
    return NULL;
}
