#include <stdio.h>
#include "src/darray.c"

void print(item item, int i) {
    printf("arr[%d] = %d;\n", i, *(int *)item);
}

void main() {
    int source_arr[] = {10, 0, 20, 30, 10, 49};
    array* arr = make_arr(source_arr, 6, sizeof (int));
    set(arr, 1, int, 10);
    iter(arr, *print);
    free(arr);
}

