#include <stdio.h>
#include "src/dlist.h"

void print(dlist_t list) {
    printf("header: front: %p,\trear: %p\n",
        list.front, list.rear);
    if (!is_empty(&list)) {
        dnode_t* current_node = list.front;
        while (current_node != NULL) {
            printf("left: %p - element: %p - right: %p\n", 
                current_node->left,
                (current_node->element),
                current_node->right);
            current_node = current_node->right;
        }
    }
}

int main() {
    // Storing in a list elements with different types
    int el1 = 0;
    float el2 = 0.1;
    double el3 = 101;
    char el4 = '!';
    char el5[] = "Hello world";
    dlist_t* list = alloc_dlist();

    append_right(list, &el1);
    append_right(list, &el2);
    append_right(list, &el3);
    append_right(list, &el4);
    append_left(list, &el5);

    print(*list);

    char* leftmost = pop_left(list);

    printf("leftmost address: %p\nleftmost element: %s\n", leftmost, leftmost);
    return 0;
}
