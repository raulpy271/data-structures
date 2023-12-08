
#include <stdlib.h>
#include <stdio.h>
#include "src/dijkstra.h"


int main() {
    vertex_t* vrts[] = {
        alloc_weighted_vertex(1, 2,
            3, 6.0,
            4, 3.0),
        alloc_weighted_vertex(2, 1,
            1, 3.0),
        alloc_weighted_vertex(3, 1,
            4, 2.0),
        alloc_weighted_vertex(4, 2,
            3, 1.0,
            2, 1.0),
        alloc_weighted_vertex(5, 2,
            2, 4.0,
            4, 2.0)
    };
    graph_t graph = {5, vrts};
    dijkstra(&graph, vrts[0]);
    for (int i = 0; i < graph.size; i++) {
        if (graph.adj[i]->pred) {
            printf("v: %d, p: %d, d: %g\n",
                graph.adj[i]->value,
                graph.adj[i]->pred->value,
                graph.adj[i]->distance
            );
        } else {
            printf("v: %d, p: null, d: %g\n",
                graph.adj[i]->value,
                graph.adj[i]->distance
            );
        }
    }
    free_vertices(vrts, graph.size);
    return 0;
}
