
#ifndef KRUSKAL_H_
#define KRUSKAL_H_

#include <stdlib.h>
#include "dsets.h"

typedef struct weighted_edge_t {
    dset_member_t* u;
    dset_member_t* v;
    unsigned int weight;
} weighted_edge_t;

typedef struct weighted_graph_t {
    dset_member_t** vertices;
    size_t vertices_len;
    weighted_edge_t* edges;
    size_t edges_len;
} weighted_graph_t;

typedef struct edges_set_t {
    weighted_edge_t** edges;
    size_t max_size;
} edges_set_t;

weighted_graph_t* alloc_weighted_graph();
void free_weighted_graph(weighted_graph_t* graph);
void alloc_vertices(weighted_graph_t* graph, size_t vertices_len, ...);
void alloc_edges(weighted_graph_t* graph, size_t edges_len, ...);
edges_set_t* mst_kruskal(weighted_graph_t* graph);

edges_set_t* alloc_empty_set(size_t max_size);
void union_edge(edges_set_t* set, weighted_edge_t* edge);

#endif // KRUSKAL_H_
