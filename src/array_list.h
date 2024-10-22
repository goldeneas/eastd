#ifndef __ARRAY_LIST_H
#define __ARRAY_LIST_H

#include "element.h"
#include <stddef.h>

#define SHRINKING_DELTA 20
#define SHRINKING_FACTOR 4
#define GROWING_DELTA 10
#define GROWING_FACTOR 2

struct array_list {
    element* array;
    size_t lenght;
    size_t size;
};

enum GrowingMode {
    LINEAR,
    GEOMETRIC,
};

struct array_list array_list_create(size_t size);
void array_list_destroy(struct array_list* array_list);
void array_list_push(struct array_list* array_list, element a);
element array_list_pop(struct array_list* array_list);
void array_list_realloc(struct array_list* array_list, size_t new_lenght, enum GrowingMode mode);

#endif
