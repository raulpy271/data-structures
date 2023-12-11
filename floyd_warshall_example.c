
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#include "src/floyd_warshall.h"

#define I INFINITY

int main() {
    double graph[N][N] = {
        {0.0, 3.0,  8.0,   I, -4.0},
        {  I, 0.0,    I, 1.0,  7.0},
        {  I, 4.0,  0.0,   I,    I},
        {2.0,   I, -5.0, 0.0,    I},
        {  I,   I,  3.0, 6.0,  0.0}
    };
    double weights[N][N];
    size_t pred[N][N];
    floyd_warshall(graph, weights, pred);
    printf("WEIGHTS\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%g\t", weights[i][j]);
        }
        printf("\n");
    }
    printf("PRED\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (pred[i][j] == NO_PRED) {
                printf("nil\t");
            } else {
                printf("%ld\t", pred[i][j] + 1);
            }
        }
        printf("\n");
    }
    return 0;
}
