#ifndef __ELEMENT_H_
#define __ELEMENT_H_

#include <stdbool.h>

#define TYPE_PRINTF_PARAM "%i"
typedef int element;
typedef int element_index;

void swap(element* a, element* b);
bool equals(element a, element b);
bool greater(element a, element b);
bool less(element a, element b);

#endif
