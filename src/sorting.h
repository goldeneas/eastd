#ifndef __SORTING_H_
#define __SORTING_H_

#include "element.h"

void bubble_sort(element* array, int n);

void insertion_sort(element* array, int n);
void insert_ordered(element* array, int n, element value);

void selection_sort(element* array, int n);
void selection_sort_rec(element* array, int n);
element_index search_min(element* array, int n);

#endif
