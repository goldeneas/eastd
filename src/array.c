#include "array.h"
#include <stdio.h>

void array_print(element* array, int n) {
    printf("Array: { ");
    for (int i = 0; i < n; i++) {
        printf(TYPE_PRINTF_PARAM, array[i]);
    }
    printf("}\n");
}
