#include <stdlib.h>
#include "stack.h"

stk_t* init() {
    stk_t* stk = malloc(sizeof (stk_t));
    stk->element = NULL;
    stk->before = NULL;
    return stk;
}

void push(stk_t* stk, void* ele) {
    stk_t* before_stk = malloc(sizeof (stk_t));
    before_stk->element = stk->element;
    before_stk->before = stk->before;
    stk->element = ele;
    stk->before = before_stk;
}

void* top(stk_t* stk) {
    return stk->element;
}

int is_null(stk_t* stk) {
    if (stk->before == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void* pop(stk_t* stk) {
    if (!is_null(stk)) {
        void* element = stk->element;
        stk_t* before_top = stk->before;
        stk->element = before_top->element;
        stk->before = before_top->before;
        free(before_top);
        return element;
    } else {
        return NULL;
    }
}

