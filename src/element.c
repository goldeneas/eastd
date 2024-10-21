#include "element.h"
#include <stdio.h>

void swap(element* a, element* b) {
    element temp = *b;
    *b = *a;
    *a = temp;
}

bool equals(element a, element b) {
    return a == b;
}

bool greater(element a, element b) {
    return a > b;
}

bool less(element a, element b) {
    return a < b;
}

void array_print(element* array, int n) {
    printf("Array: { ");
    for (int i = 0; i < n; i++) {
        printf("%i ", array[i]);
    }
    printf("}\n");
}
