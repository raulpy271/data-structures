#include <stdio.h>

#include "src/priority_queue.h"

bool smallest_int(void* a, void* b) {
    return (*(int *)a) < (*(int *)b);
}

void sort_arr_using_queue(queue_t* queue, int arr[]) {
    int i = 0;
    while(!is_empty_queue(*queue)) {
        arr[i] = *(int *)pop(queue, smallest_int);
        i++;
    }
}

int main() {
    // Sort an array using a priority queue
    int length = 4;
    int sorted_arr[4] = {};
    queue_t unsorted_queue = alloc_node();
    int element1 = 10;
    int element2 = 20;
    int element3 = 30;
    int element4 = 40;
    insert(&unsorted_queue, &element4);
    insert(&unsorted_queue, &element2);
    insert(&unsorted_queue, &element1);
    insert(&unsorted_queue, &element3);
    sort_arr_using_queue(&unsorted_queue, sorted_arr);
    printf("sorted arr: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", sorted_arr[i]);
    }
    printf("\n");
    return 0;
}

