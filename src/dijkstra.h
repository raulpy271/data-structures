
#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_

#include <stddef.h>
#include "dlist.h"

typedef struct adj_member_t {
    unsigned int adj_value;
    double weight;
} adj_member_t;

typedef struct vertex_t {
    unsigned int value;
    double distance;
    struct vertex_t* pred;
    size_t adj_size;
    dlist_t* adj;
} vertex_t;

typedef struct graph_t {
    size_t size;
    vertex_t** adj;
} graph_t;

typedef struct vertex_set_t {
    vertex_t** vertex;
    size_t max_size;
} vertex_set_t;



vertex_t* alloc_weighted_vertex(unsigned int vertex, size_t size, ...);
void free_vertices(vertex_t** adj, size_t size);
void initialize_single_source(graph_t* graph, vertex_t* source);
void relax(vertex_t* u, vertex_t* v, double weight);
void dijkstra(graph_t* graph, vertex_t* source);
vertex_t* get_vertex(graph_t* graph, unsigned int vertex_value);

vertex_set_t* alloc_empty_set(size_t max_size);
void union_vertex(vertex_set_t* set, vertex_t* vertex);
void free_vertex_set(vertex_set_t* set);

#endif // DIJKSTRA_H_
