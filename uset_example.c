
#include <stdio.h>
#include <stdlib.h>
#include "src/uset.h"

int main() {
    uset_t set1 = alloc_uset(2, 0, 1);
    uset_t set2 = alloc_uset(2, 1, 3);
    uset_t set = uset_union(set1, set2);
    printf("set[0] %d \n", (int) uset_in(set, 0));
    printf("set[1] %d \n", (int) uset_in(set, 1));
    printf("set[2] %d \n", (int) uset_in(set, 2));
    printf("set[3] %d \n", (int) uset_in(set, 3));
    free(set1);
    free(set2);
    free(set);
    return 0;
}


