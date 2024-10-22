#include "linked_list.h"
#include "array.h"
#include "sorting.h"

int main() {
    int array[] = { 10, 5, 21, 8, 1 };
    insertion_sort(array, 5);
    array_print(array, 5);

    return 0;
}
