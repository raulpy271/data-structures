
#include <stdlib.h>
#include <stdio.h>
#include "src/prim.h"


int main() {
    vertex_t* vrts[] = {
        alloc_weighted_vertex(1, 2,
            3, 5,
            2, 3),
        alloc_weighted_vertex(2, 2,
            1, 3,
            4, 4),
        alloc_weighted_vertex(3, 2,
            1, 5,
            4, 12),
        alloc_weighted_vertex(4, 4,
            3, 12,
            2, 4,
            5, 9,
            8, 8),
        alloc_weighted_vertex(5, 4,
            4, 9,
            8, 1,
            6, 4,
            7, 5),
        alloc_weighted_vertex(6, 2,
            5, 4,
            7, 6),
        alloc_weighted_vertex(7, 3,
            5, 5,
            6, 6,
            8, 20),
        alloc_weighted_vertex(8, 3,
            4, 8,
            5, 7,
            7, 20)
    };
    graph_t graph = {8, vrts};
    edges_set_t* set = mst_prim(&graph, vrts[0]);
    printf("Pritting edges of Prim MST:\n");
    for (int i = 0; i < set->max_size; i++) {
        weighted_edge_t* edge = set->edges[i];
        printf("u: %d, v: %d: w: %d\n", edge->u->value, edge->v->value, edge->weight);
        free(edge);
    }
    free_vertices(vrts, graph.size);
    free(set->edges);
    free(set);
    return 0;
}
