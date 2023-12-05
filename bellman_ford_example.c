
#include <stdio.h>
#include "src/bellman_ford.h"

int main() {
    vertex_t* v1 = alloc_vertex(1);
    vertex_t* v2 = alloc_vertex(2);
    vertex_t* v3 = alloc_vertex(3);
    vertex_t* v4 = alloc_vertex(4);
    vertex_t* v5 = alloc_vertex(5);
    weighted_graph_t* graph = alloc_weighted_graph();
    alloc_vertices(graph, 5, v1, v2, v3, v4, v5);
    alloc_edges(graph, 8,
        v1, v3, 6.0,
        v1, v4, 3.0,
        v3, v4, 2.0,
        v4, v3, 1.0,
        v4, v2, 1.0,
        v2, v1, 3.0,
        v5, v2, 4.0,
        v5, v4, 2.0
    );
    bool result = bellman_ford(graph, v1);
    printf("bellman ford result: %d\n", result);
    for (int i = 0; i < graph->vertices_len; i++) {
        if (graph->vertices[i]->pred) {
            printf("v: %d, p: %d, d: %g\n",
                graph->vertices[i]->value,
                graph->vertices[i]->pred->value,
                graph->vertices[i]->distance
            );
        } else {
            printf("v: %d, p: null, d: %g\n",
                graph->vertices[i]->value,
                graph->vertices[i]->distance
            );
        }
    }
    free_weighted_graph(graph);
    return 0;
}

