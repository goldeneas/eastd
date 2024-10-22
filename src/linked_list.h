#ifndef __LINKED_LIST_H
#define __LINKED_LIST_H

#include <stddef.h>
#include <stdbool.h>
#include "element.h"

struct node {
    struct node* next;
    element value;
};

typedef struct node* linked_list;

linked_list linked_list_create();
void linked_list_destroy(linked_list list);
linked_list linked_list_add(element value, linked_list list);
linked_list linked_list_remove(element value, linked_list list);
struct node* linked_list_search(element value, linked_list list);
void linked_list_print(linked_list list);
bool linked_list_is_empty(linked_list list);

struct node* node_create(element value);
void node_destroy(struct node* node);

#endif
