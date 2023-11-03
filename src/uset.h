
#ifndef USET_H_
#define USET_H_

#include <stdbool.h>

#define USET_MAX_ITEMS 1000

typedef bool* uset_t;

uset_t alloc_uset(size_t size, ...);

bool uset_in(uset_t set, unsigned int value);

uset_t uset_union(uset_t set1, uset_t set2);

#endif // USET_H_
