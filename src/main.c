#include "linked_list.h"
#include "sorting.h"
#include "element.h"

int main() {
    linked_list list = linked_list_create();
    list = linked_list_add(0, list);
    list = linked_list_add(3, list);
    list = linked_list_add(2, list);
    list = linked_list_push_back(0, list);
    linked_list_print(list);

    return 0;
}
