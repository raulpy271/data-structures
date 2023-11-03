
#include <stdarg.h>
#include <stdlib.h>

#include "uset.h"

uset_t alloc_uset(size_t size, ...) {
    uset_t set = malloc(sizeof (bool) * USET_MAX_ITEMS);
    va_list ap;
    va_start(ap, size);
    for (int i = 0; i < size; i++) {
        unsigned int member = va_arg(ap, unsigned int);
        set[member] = true;
    }
    va_end(ap);
    return set;
}

bool uset_in(uset_t set, unsigned int value) {
    return set[value];
}

uset_t uset_union(uset_t set1, uset_t set2) {
    uset_t set = alloc_uset(0);
    for (int i = 0; i < USET_MAX_ITEMS; i++) {
        set[i] = set1[i] || set2[i];
    }
    return set;
}

