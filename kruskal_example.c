
#include <stdio.h>
#include "src/dsets.h"
#include "src/kruskal.h"

int main() {
    dset_member_t* m1 = alloc_dset_member((void*) 1);
    dset_member_t* m2 = alloc_dset_member((void*) 2);
    dset_member_t* m3 = alloc_dset_member((void*) 3);
    dset_member_t* m4 = alloc_dset_member((void*) 4);
    dset_member_t* m5 = alloc_dset_member((void*) 5);
    dset_member_t* m6 = alloc_dset_member((void*) 6);
    dset_member_t* m7 = alloc_dset_member((void*) 7);
    dset_member_t* m8 = alloc_dset_member((void*) 8);
    weighted_graph_t* graph = alloc_weighted_graph();
    alloc_vertices(graph, 8, m1, m2, m3, m4, m5, m6, m7, m8);
    alloc_edges(graph, 11,
        m1, m2, 3,
        m1, m3, 5,
        m2, m4, 4,
        m3, m4, 12,
        m4, m5, 9,
        m4, m8, 8,
        m5, m8, 1,
        m5, m6, 4,
        m5, m7, 5,
        m6, m7, 6,
        m7, m8, 20
    );
    edges_set_t* edges = mst_kruskal(graph);
    printf("Pritting edges of Kruskal MST:\n");
    for (int i = 0; i < edges->max_size; i++) {
        printf("u: %ld, v: %ld, w: %d\n",
            (long unsigned int)edges->edges[i]->u->member,
            (long unsigned int)edges->edges[i]->v->member,
            edges->edges[i]->weight
        );
    }
    free(edges->edges);
    free(edges);
    free_weighted_graph(graph);
    return 0;
}

