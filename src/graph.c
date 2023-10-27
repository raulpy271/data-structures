
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

#include "graph.h"

vertex_t* alloc_vertex(unsigned int vertex, size_t size, ...) {
    vertex_t* vrt = malloc(sizeof (vertex_t));
    vrt->value = vertex;
    vrt->visited = false;
    vrt->pred = NULL;
    vrt->distance = 0;
    vrt->finish = 0;
    vrt->adj_size = size;
    vrt->adj = alloc_dlist();
    va_list ap;
    va_start(ap, size);
    for (int i = 0; i < size; i++) {
        void* adj = va_arg(ap, void*);
        //printf("Setting %p as adj of %d\n", adj, vertex);
        append_right(vrt->adj, adj);
    }
    va_end(ap);
    return vrt;
}

vertex_t* get_vertex(graph_t* graph, unsigned int vertex_value) {
    for (int i = 0; i < graph->size; i++) {
        if (graph->adj[i]->value == vertex_value)
            return graph->adj[i];
    }
    return NULL;
}

void print_graph(graph_t* graph) {
    for (int i = 0; i < graph->size; i++) {
        vertex_t* vrt = graph->adj[i];
        unsigned int pred_value = 0;
        if (vrt->pred) pred_value = vrt->pred->value;
        printf(" - vertex: %d | visited: %d | pred: %d | dist: %d | finish: %d \n",
            vrt->value,
            vrt->visited,
            pred_value,
            vrt->distance,
            vrt->finish
        );
        printf("    - adjacents: [");
        for (int j = 0; j < vrt->adj_size; j++) {
            printf("%ld ", (long int) get(vrt->adj, j));
        }
        printf("]\n");
    }
}

void bfs(graph_t* graph, vertex_t* vrt) {
    dlist_t* queue = alloc_dlist();
    for (int i = 0; i < graph->size; i++) {
        if (graph->adj[i] != vrt) {
            graph->adj[i]->distance = INF;
        }
    }
    vrt->visited = true;
    append_right(queue, (void *) vrt);
    while (!is_empty(queue)) {
        vrt = (vertex_t*) pop_left(queue);
        for (int i = 0; i < vrt->adj_size; i++) {
            unsigned int neighbor_value = (unsigned int) (long unsigned int) get(vrt->adj, i);
            vertex_t* neighbor = get_vertex(graph, neighbor_value);
            if (!neighbor->visited) {
                neighbor->visited = true;
                neighbor->distance = vrt->distance + 1;
                neighbor->pred = vrt;
                append_right(queue, (void *) neighbor);
            }
        }
    }
}

void dfs(graph_t* graph) {
    unsigned int time = 0;
    for (int i = 0; i < graph->size; i++) {
        if (!(graph->adj[i]->visited))
            dfs_visit(graph, graph->adj[i], &time);
    }
}

dlist_t* topological_sort(graph_t* graph) {
    dlist_t* list = alloc_dlist();
    unsigned int time = 0;
    for (int i = 0; i < graph->size; i++) {
        if (!(graph->adj[i]->visited))
            topological_sort_visit(graph, graph->adj[i], &time, list);
    }
    return list;
}

void dfs_visit(graph_t* graph, vertex_t* vrt, unsigned int* time) {
    *time = *time + 1;
    vrt->distance = *time;
    vrt->visited = true;
    for (int i = 0; i < vrt->adj_size; i++) {
        unsigned int neighbor_value = (unsigned int) (long unsigned int) get(vrt->adj, i);
        vertex_t* neighbor = get_vertex(graph, neighbor_value);
        if (!neighbor->visited) {
            neighbor->pred = vrt;
            dfs_visit(graph, neighbor, time);
        }
    }
    *time = *time + 1;
    vrt->finish = *time;
}

void topological_sort_visit(graph_t* graph, vertex_t* vrt, unsigned int* time, dlist_t* list) {
    *time = *time + 1;
    vrt->distance = *time;
    vrt->visited = true;
    for (int i = 0; i < vrt->adj_size; i++) {
        unsigned int neighbor_value = (unsigned int) (long unsigned int) get(vrt->adj, i);
        vertex_t* neighbor = get_vertex(graph, neighbor_value);
        if (!neighbor->visited) {
            neighbor->pred = vrt;
            topological_sort_visit(graph, neighbor, time, list);
        }
    }
    *time = *time + 1;
    vrt->finish = *time;
    append_left(list, (void*) (long unsigned int) vrt->value);
}

