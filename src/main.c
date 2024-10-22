#include "linked_list.h"
#include "array.h"
#include "sorting.h"

int main() {
    int array[] = { 2, 1, 5, 6, 3 };
    selection_sort(array, 5);
    array_print(array, 5);

    return 0;
}
