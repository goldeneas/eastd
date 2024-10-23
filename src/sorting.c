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

void insert_ordered(element* array, int n, element value) {
    if (n == 0) {
        printf("cannot insert in uninitialized array");
        return;
    }

    element_index target_idx = -1;
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

void insertion_sort(element* array, int n) {
    for (int i = 1; i < n; i++) {
        insert_ordered(array, i, array[i]);
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

element_index partition(element* array, int n) {
    int k = 1; // prima posizione modificabile
    for (int i = 1; i < n; i++) {
        if (less(array[i], array[0])) {
            swap(&array[k], &array[i]);
            k += 1;
        }
    }

    swap(&array[0], &array[k - 1]);
    return k - 1;
}

void quick_sort(element* array, int n) {
    if (n < 2) { return; }

    int k = partition(array, n);
    quick_sort(array, k);
    quick_sort(array + k + 1, n - k - 1);
}

void merge(element* array1, int n1, element* array2, int n2, element* dest) {
    int pos1 = 0;
    int pos2 = 0;
    int i = 0;

    while(pos1 < n1 && pos2 < n2) {
        if (less(array1[pos1], array2[pos2])) {
            dest[i] = array1[pos1];
            pos1 += 1;
        } else {
            dest[i] = array2[pos2];
            pos2 += 1;
        }

        i += 1;
    }

    while (pos1 < n1) {
        dest[i] = array1[pos1];
        pos1 += 1;
        i += 1;
    }

    while (pos2 < n2) {
        dest[i] = array2[pos2];
        pos2 += 1;
        i += 1;
    }
}

void merge_sort(element* array, int n, element* temp) {
    int m = n / 2;
    if (n < 2) { return; }

    merge_sort(array, m, temp);
    merge_sort(array + m, n - m, temp);
    merge(array, m, array + m, n - m, temp);

    for (int i = 0; i < n; i++) {
        array[i] = temp[i];
    }
}
