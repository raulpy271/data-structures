
#include <stdio.h>
#include "src/graph.h"

void bfs_example(graph_t* graph) {
    vertex_t* vrt = graph->adj[1];
    bfs(graph, vrt);
    print_graph(graph);
}

void dfs_example(graph_t* graph) {
    dfs(graph);
    print_graph(graph);
}

void topological_sort_example(graph_t* graph) {
    dlist_t* list = topological_sort(graph);
    printf("Topological sort: ");
    for (int i = 0; i < graph->size; i++) {
        printf("%d ", (unsigned int) (long unsigned int) get(list, i));
    }
    printf("\n");
    //print_graph(graph);
}

int main() {
    // Exemplo 596
    //vertex_t* vrts[] = {
    //    alloc_vertex(0, 2, 1, 4),
    //    alloc_vertex(1, 2, 0, 5),
    //    alloc_vertex(2, 3, 3, 5, 6),
    //    alloc_vertex(3, 3, 2, 6, 7),
    //    alloc_vertex(4, 1, 0),
    //    alloc_vertex(5, 3, 1, 2, 6),
    //    alloc_vertex(6, 4, 5, 2, 3, 7),
    //    alloc_vertex(7, 2, 3, 6),
    //};
    //graph_t graph = {8, vrts};

    // Exemplo 605
    //vertex_t* vrts[] = {
    //    alloc_vertex(0, 2, 1, 3),
    //    alloc_vertex(1, 1, 4),
    //    alloc_vertex(2, 2, 4, 5),
    //    alloc_vertex(3, 1, 1),
    //    alloc_vertex(4, 1, 3),
    //    alloc_vertex(5, 1, 5),
    //};
    //graph_t graph = {6, vrts};

    // Exemplo GeeksForGeeks
    //vertex_t* vrts[] = {
    //    alloc_vertex(0, 0),
    //    alloc_vertex(1, 0),
    //    alloc_vertex(2, 1, 3),
    //    alloc_vertex(3, 1, 1),
    //    alloc_vertex(4, 2, 0, 1),
    //    alloc_vertex(5, 2, 0, 2),
    //};
    //graph_t graph = {6, vrts};

    print_graph(&graph);
    //bfs_example(&graph);
    //dfs_example(&graph);
    //topological_sort_example(&graph);

}

