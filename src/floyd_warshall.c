
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "floyd_warshall.h"

void floyd_warshall(double graph[N][N], double weights[N][N], size_t pred[N][N]) {
    double (*d_previus)[N] = memcpy(
        malloc(sizeof(double) * N * N),
        (void*) graph,
        sizeof(double) * N * N
    );
    double (*d)[N] = weights;
    size_t (*pred_previus)[N] = malloc(sizeof(size_t) * N * N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if ((i == j) || isinf(graph[i][j])) {
                pred_previus[i][j] = NO_PRED;
            } else {
                pred_previus[i][j] = i;
            }
        }
    }
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (d_previus[i][j] <= (d_previus[i][k] + d_previus[k][j])) {
                    d[i][j] = d_previus[i][j];
                    pred[i][j] = pred_previus[i][j];
                } else {
                    d[i][j] = d_previus[i][k] + d_previus[k][j];
                    pred[i][j] = pred_previus[k][j];
                }
            }
        }
        memcpy(d_previus, (void*) d, sizeof(double) * N * N);
        memcpy(pred_previus, (void*) pred, sizeof(size_t) * N * N);
    }
}

void print_all_pairs(size_t pred[N][N], size_t i, size_t j) {
    if (i == j) {
        printf("%ld ", i);
    } else if (pred[i][j] == NO_PRED) {
        printf("no path from %ld to %ld exists", i, j);
    } else {
        print_all_pairs(pred, i, pred[i][j]);
        printf("%ld ", j);
    }
}

