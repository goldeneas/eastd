#ifndef __SORTING_H_
#define __SORTING_H_

#include "element.h"

void bubble_sort(element* array, int n);

void insertion_sort(element* array, int n);
void insert_ordered(element* array, int n, element value);

element_index partition(element* array, int n);
void quick_sort(element* array, int n);

void merge(element* array1, int n1, element* array2, int n2, element* dest);
void merge_sort(element* array, int n, element* temp);

void selection_sort(element* array, int n);
void selection_sort_rec(element* array, int n);
element_index search_min(element* array, int n);

#endif
