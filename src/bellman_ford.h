
#ifndef BELLMAN_FORD_H_
#define BELLMAN_FORD_H_

#include <stdbool.h>
#include <stdlib.h>

typedef struct vertex_t {
    unsigned int value;
    double distance;
    struct vertex_t* pred;
} vertex_t;

typedef struct weighted_edge_t {
    vertex_t* u;
    vertex_t* v;
    double weight;
} weighted_edge_t;

typedef struct weighted_graph_t {
    vertex_t** vertices;
    size_t vertices_len;
    weighted_edge_t* edges;
    size_t edges_len;
} weighted_graph_t;

vertex_t* alloc_vertex(unsigned int value);
weighted_graph_t* alloc_weighted_graph();
void free_weighted_graph(weighted_graph_t* graph);
void alloc_vertices(weighted_graph_t* graph, size_t vertices_len, ...);
void alloc_edges(weighted_graph_t* graph, size_t edges_len, ...);
void initialize_single_source(weighted_graph_t* graph, vertex_t* source);
void relax(weighted_edge_t* edge);
bool bellman_ford(weighted_graph_t* graph, vertex_t* source);

#endif // BELLMAN_FORD_H_
