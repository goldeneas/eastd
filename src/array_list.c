#include "array_list.h"
#include "element.h"
#include <assert.h>
#include <stdlib.h>

struct array_list array_list_create(size_t size) {
    assert(size > 0);

    element* array = malloc(sizeof(element) * size);
    size_t lenght = 0;

    struct array_list array_list = {
        .array = array,
        .lenght = lenght,
        .size = size,
    };

    return array_list;
}

void array_list_destroy(struct array_list* array_list) {
    assert(array_list != NULL);
    if (array_list->array == NULL) { return; }

    free(array_list->array);
    array_list->array = NULL;
    array_list->size = 0;
    array_list->lenght = 0;
}

void array_list_push(struct array_list* array_list, element a) {
    assert(array_list != NULL);
    assert(array_list->array != NULL);
    assert(array_list->lenght < array_list->size);

    array_list->array[array_list->lenght] = a;
    array_list->lenght += 1;
}

element array_list_pop(struct array_list* array_list) {
    assert(array_list != NULL);
    assert(array_list->array != NULL);
    assert(array_list->lenght > 0);

    int last_idx = array_list->lenght - 1;
    array_list->lenght -= 1;
    return array_list->array[last_idx];
}

void array_list_realloc(struct array_list* array_list, size_t new_lenght, enum GrowingMode mode) {
    size_t new_size = 0;

    switch (mode) {
        case LINEAR: {
            bool should_grow = new_lenght > array_list->size;
            bool should_shrink = new_lenght < array_list->size - SHRINKING_DELTA;

            if (should_grow || should_shrink) {
                new_size = new_lenght + GROWING_DELTA;
                array_list->array = realloc(array_list->array, new_size * sizeof(element));
                array_list->size = new_size;
            }

            break;
        }

        case GEOMETRIC: {
            bool should_grow = new_lenght > array_list->size;
            bool should_shrink = new_lenght < array_list->size - SHRINKING_FACTOR;

            if (should_grow || should_shrink){
                 new_size =  new_lenght * GROWING_FACTOR;
                 array_list->array = realloc(array_list->array, new_size * sizeof(element));
                 array_list->size = new_size;
             };

            break;
        }
    }

    array_list->lenght = new_lenght;
}
