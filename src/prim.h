
#ifndef PRIM_H_
#define PRIM_H_

#include <stddef.h>
#include "dlist.h"

typedef struct adj_member_t {
    unsigned int adj_value;
    unsigned int weight;
} adj_member_t;

typedef struct vertex_t {
    unsigned int value;
    unsigned int key;
    struct vertex_t* pred;
    size_t adj_size;
    dlist_t* adj;
} vertex_t;

typedef struct graph_t {
    size_t size;
    vertex_t** adj;
} graph_t;

typedef struct weighted_edge_t {
    vertex_t* u;
    vertex_t* v;
    unsigned int weight;
} weighted_edge_t;

typedef struct edges_set_t {
    weighted_edge_t** edges;
    size_t max_size;
} edges_set_t;


vertex_t* alloc_weighted_vertex(unsigned int vertex, size_t size, ...);
edges_set_t* mst_prim(graph_t* graph, vertex_t* root);
edges_set_t* alloc_empty_set(size_t max_size);
void union_edge(edges_set_t* set, weighted_edge_t* edge);
void free_vertices(vertex_t** adj, size_t size);
vertex_t* get_vertex(graph_t* graph, unsigned int vertex_value);

#endif // PRIM_H_
