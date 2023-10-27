
#ifndef GRAPH_H_
#define GRAPH_H_

#include <stdbool.h>
#include "dlist.h"
#define INF (unsigned int) -1

typedef struct vertex_t {
    unsigned int value;
    bool visited;
    struct vertex_t* pred;
    unsigned int distance;
    unsigned int finish;
    size_t adj_size;
    dlist_t* adj;
} vertex_t;

typedef struct graph_t {
    unsigned int size;
    vertex_t** adj;
} graph_t;

vertex_t* alloc_vertex(unsigned int vertex, size_t size, ...);

vertex_t* get_vertex(graph_t* graph, unsigned int vertex_value);

void print_graph(graph_t* graph);

void bfs(graph_t* graph, vertex_t* vrt);

void dfs(graph_t* graph);

dlist_t* topological_sort(graph_t* graph);

void dfs_visit(graph_t* graph, vertex_t* vertex, unsigned int* time);

void topological_sort_visit(graph_t* graph, vertex_t* vertex, unsigned int* time, dlist_t* list);

#endif // GRAPH_H_
