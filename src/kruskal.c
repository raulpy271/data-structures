
#include <stdlib.h>
#include <stdarg.h>
#include "kruskal.h"
#include "dsets.h"


weighted_graph_t* alloc_weighted_graph() {
    weighted_graph_t* graph = malloc(sizeof(weighted_graph_t));
    graph->vertices = NULL;
    graph->vertices_len = 0;
    graph->edges = NULL;
    graph->edges_len = 0;
    return graph;
}

void alloc_vertices(weighted_graph_t* graph, size_t vertices_len, ...) {
    dset_member_t** vertices = malloc(sizeof(dset_member_t*) * vertices_len);
    graph->vertices = vertices;
    graph->vertices_len = vertices_len;
    va_list ap;
    va_start(ap, vertices_len);
    for (int i = 0; i < vertices_len; i++) {
        dset_member_t* vertex = va_arg(ap, dset_member_t*);
        graph->vertices[i] = vertex;
    }
    va_end(ap);
}

void alloc_edges(weighted_graph_t* graph, size_t edges_len, ...) {
    weighted_edge_t* edges = malloc(sizeof(weighted_edge_t) * edges_len);
    graph->edges = edges;
    graph->edges_len = edges_len;
    va_list ap;
    va_start(ap, edges_len);
    for (int i = 0; i < edges_len; i++) {
        dset_member_t* u = va_arg(ap, dset_member_t*);
        dset_member_t* v = va_arg(ap, dset_member_t*);
        unsigned int weight = va_arg(ap, unsigned int);
        graph->edges[i].u = u;
        graph->edges[i].v = v;
        graph->edges[i].weight = weight;
    }
    va_end(ap);
}

void free_weighted_graph(weighted_graph_t* graph) {
    free(graph->edges);
    for (int i = 0; i < graph->vertices_len; i++) {
        free(graph->vertices[i]);
    }
    free(graph);
}

int cmp_edge(const void* e1, const void* e2) {
    long unsigned int v1 = (((weighted_edge_t*)e1))->weight;
    long unsigned int v2 = (((weighted_edge_t*)e2))->weight;
    if (v1 < v2) {
        return -1;
    }
    if (v1 > v2) {
        return 1;
    }
    return 0;
}

edges_set_t* mst_kruskal(weighted_graph_t* graph) {
    dsets_t* dsets = alloc_dsets();
    edges_set_t* set_a = alloc_empty_set(graph->vertices_len - 1);
    for (int i = 0; i < graph->vertices_len; i++) {
        make_set(dsets, graph->vertices[i]);
    }
    qsort(graph->edges, graph->edges_len, sizeof(graph->edges[0]), &cmp_edge);
    for (int i = 0; i < graph->edges_len; i++) {
        weighted_edge_t* edge = &(graph->edges[i]);
        if (find_set(edge->u) != find_set(edge->v)) {
            union_edge(set_a, edge);
            union_set(&dsets, edge->u, edge->v);
        }
    }
    free(dsets);
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

