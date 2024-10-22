#include "element.h"

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
