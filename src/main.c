#include "linked_list.h"

int main() {
    linked_list list = linked_list_create();
    list = linked_list_add(2, list);
    list = linked_list_add(3, list);

    linked_list_print(list);
    linked_list_search(7, list);

    return 0;
}
