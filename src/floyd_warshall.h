
#ifndef FLOYD_WARSHALL_H_
#define FLOYD_WARSHALL_H_

#include <stddef.h>

#define N 5
#define NO_PRED -1

void floyd_warshall(double graph[N][N], double weights[N][N], size_t pred[N][N]);
void print_all_pairs(size_t pred[N][N], size_t i, size_t j);

#endif // FLOYD_WARSHALL_H_
