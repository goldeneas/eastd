#include "sorting.h"
#include "array.h"
#include "stdbool.h"
#include "element.h"
#include <stdio.h>

void bubble_sort(element* array, int n) {
    bool modified = false;

    do {
        modified = false;
        for(int i = 0; i < n - 1; i++) {

            if(greater(array[i], array[i+1])) {
                modified = true;
                swap(&array[i], &array[i+1]);
            }
        }
    } while (modified);
}

// PRE:
// - the array has at least an empty slot
void insert_ordered(element* array, int n, element value) {
    if (n == 0) {
        printf("cannot insert in uninitialized array");
        return;
    }

    if (n == 1) {
        array[0] = value;
        return;
    }

    element_index target_idx = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (greater(array[i], value)) { continue; }
        target_idx = i;
        break;
    }

    for (int i = n - 1; i > target_idx; i--) {
        swap(&array[i + 1], &array[i]);
    }

    array[target_idx + 1] = value;
}

// PRE:
// - the array has at least an empty slot
// - the array is ordered
// todo fix this :)
void insertion_sort(element* array, int n) {
    for (int i = 0; i < n; i++) {
        insert_ordered(array, i + 1, array[i]);
    }
}

void selection_sort_rec(element* array, int n) {
    if (n <= 1) { return; }

    element_index min_idx = search_min(array, n);
    swap(&array[0], &array[min_idx]);
    selection_sort_rec(array + 1, n - 1);
}

void selection_sort(element* array, int n) {
    for (int i = 0; i < n; i++) {
        element_index min_idx = i + search_min(array + i, n - i);
        swap(&array[i], &array[min_idx]);
    }
}

element_index search_min(element* array, int n) {
    element_index min_idx = 0;
    for (int i = 1; i < n; i++) {
        if (!less(array[i], array[min_idx])) { continue; }
        min_idx = i;
    }

    return min_idx;
}
