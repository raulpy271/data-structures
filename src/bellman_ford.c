
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>
#include "bellman_ford.h"


vertex_t* alloc_vertex(unsigned int value) {
    vertex_t* vrt = malloc(sizeof(vertex_t));
    vrt->value = value;
    vrt->distance = INFINITY;
    vrt->pred = NULL;
    return vrt;
}

weighted_graph_t* alloc_weighted_graph() {
    weighted_graph_t* graph = malloc(sizeof(weighted_graph_t));
    graph->vertices = NULL;
    graph->vertices_len = 0;
    graph->edges = NULL;
    graph->edges_len = 0;
    return graph;
}

void alloc_vertices(weighted_graph_t* graph, size_t vertices_len, ...) {
    vertex_t** vertices = malloc(sizeof(vertex_t*) * vertices_len);
    graph->vertices = vertices;
    graph->vertices_len = vertices_len;
    va_list ap;
    va_start(ap, vertices_len);
    for (int i = 0; i < vertices_len; i++) {
        vertex_t* vertex = va_arg(ap, vertex_t*);
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
        vertex_t* u = va_arg(ap, vertex_t*);
        vertex_t* v = va_arg(ap, vertex_t*);
        double weight = va_arg(ap, double);
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

void initialize_single_source(weighted_graph_t* graph, vertex_t* source) {
    for (int i = 0; i < graph->vertices_len; i++) {
        graph->vertices[i]->distance = INFINITY;
        graph->vertices[i]->pred = NULL;
    }
    source->distance = 0;
}

void relax(weighted_edge_t* edge) {
    if (isinf(edge->u->distance) && isinf(edge->v->distance)) {
        return;
    }
    if (edge->v->distance > (edge->u->distance + edge->weight)) {
        edge->v->distance = edge->u->distance + edge->weight;
        edge->v->pred = edge->u;
    }
}

bool bellman_ford(weighted_graph_t* graph, vertex_t* source) {
    initialize_single_source(graph, source);
    for (int i = 0; i < graph->vertices_len; i++) {
        for (int j = 0; j < graph->edges_len; j++) {
            relax(&(graph->edges[j]));
        }
    }
    for (int j = 0; j < graph->edges_len; j++) {
        weighted_edge_t* edge = &(graph->edges[j]);
        if (edge->v->distance > (edge->u->distance + edge->weight)) {
            return false;
        }
    }
    return true;
}

