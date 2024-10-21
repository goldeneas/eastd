#include "linked_list.h"
#include "sorting.h"
#include "element.h"

int main() {
    element array[] = { 2, 5, 6, 10, 21 };
    insertion_sort(array, 5);
    array_print(array, 5);
    
    return 0;
}
