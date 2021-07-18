#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


struct Nlarray {
    int MAX_LIMIT;
    int filled;
    void *first_item;
};

int get_args_len(va_list args) {
    int current_arg;
    int c;
    for (c = 1; current_arg != 0; c++) {
        current_arg = va_arg(args, int);
    }
    va_end(args);
    return c;
}

struct Nlarray *nlarray(void *arr, size_t size, size_t size_item) {
    int i;
    int filled = size;
    int MAX_LIMIT = 200;
    void *array_fixed_len[MAX_LIMIT];
    struct Nlarray *nlarr;
    for (i = 0; i < size; i++) {
        array_fixed_len[i] = arr;
        arr += size_item; 
    }
    nlarr = malloc(sizeof nlarr);
    nlarr->MAX_LIMIT = MAX_LIMIT;
    nlarr->filled = filled;
    nlarr->first_item = (void *)(array_fixed_len[0]);
    return nlarr;
}

void main() {
    long int arr[] = {10, 0, 20};
    void *arr_pt = &(arr[0]);
    struct Nlarray *nlarr = nlarray(arr_pt, 3, sizeof (long int));
    for (int i = 0; i < 3; i++) {
        long int *item = (long int*)(nlarr->first_item);
        printf("%d\n", *item);
        nlarr->first_item += sizeof (long int); 
    }
    printf("limit: %d", nlarr->MAX_LIMIT);
    free(nlarr);
}
