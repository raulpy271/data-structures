#include <stdlib.h>
#include "darray.h"
#define set(arr, i, type, value) { \
        *(type *)(get(arr, i)) = value; \
    }

array* make_arr(item source_arr, size_t size, size_t size_item) {
    int i;
    int length = size;
    int MAX_LIMIT = 200;
    void *array_fixed_len[MAX_LIMIT];
    array *arr;
    for (i = 0; i < size; i++) {
        array_fixed_len[i] = source_arr;
        source_arr += size_item; 
    }
    arr = malloc(sizeof arr);
    arr->MAX_LIMIT = MAX_LIMIT;
    arr->length = length;
    arr->size_item = size_item;
    arr->first_item = (item)(array_fixed_len[0]);
    return arr;
}

item get(array* arr, int i) {
    if (i > arr->length) {
        return (item) NULL;
    }
    item address = arr->first_item + (arr->size_item * i);
    return address;
}

void iter(array* arr, void (*func)()) {
    int i;
    item current = arr->first_item;
    for (i = 0; i < arr->length; i++) {
        func(current, i);
        current += arr->size_item;
    }
}

