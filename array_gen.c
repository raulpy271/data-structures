#include <stdio.h>
#include <stdlib.h>

typedef void* item;

struct array {
    int MAX_LIMIT;
    int length;
    int size_item;
    item first_item;
};

typedef struct array array;

array* make_arr(void *source_arr, size_t size, size_t size_item) {
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
    arr->first_item = (void *)(array_fixed_len[0]);
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

void print(item item, int i) {
    printf("arr[%d] = %d;\n", i, *(int *)item);
}

void main() {
    int source_arr[] = {10, 0, 20, 30, 10, 49};
    array* arr = make_arr((void *)source_arr, 6, sizeof (int));
    printf("%d\n", *(int *)get(arr, arr->length - 1));
    iter(arr, (void *)print);
    free(arr);
}
