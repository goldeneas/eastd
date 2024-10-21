#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

struct node* node_create(element value) {
    struct node* node = malloc(sizeof(struct node));
    node->value = value;
    node->next = NULL;

    return node;
}

void node_destroy(struct node *node) {
    free(node);
}

linked_list linked_list_create() {
    return NULL;
}

void linked_list_destroy(linked_list list) {
    struct node* curr = list;

    while (curr != NULL) {
        struct node* next = curr->next;
        free(curr);

        curr = next;
    }
}

bool linked_list_is_empty(linked_list list) {
    return list == NULL;
}

linked_list linked_list_add(element value, linked_list list) {
    struct node* node = node_create(value);

    if (linked_list_is_empty(list)) {
        return node;
    }

    struct node* prec = NULL;
    struct node* curr = list;
    struct node* next = curr->next;
    while(next != NULL && less(curr->value, value)) {
        prec = curr;
        curr = next;
        next = curr->next;
    }

    if (greater(curr->value, value)) {
        if (prec == NULL) {
            node->next = curr;
            return node;
        } else {
            prec->next = node;
            node->next = curr;
            return list;
        }
    }

    if (next == NULL) {
        curr->next = node;
        node->next = NULL;
        return list;
    }

    return list;
}

linked_list linked_list_remove(element value, linked_list list) {
    if (linked_list_is_empty(list)) {
        return NULL;
    }

    struct node* prec = NULL;
    struct node* curr = list;
    struct node* next = curr->next;
    while(next != NULL && !equals(curr->value, value)) {
        prec = curr;
        curr = next;
        next = curr->next;
    }

    if (equals(curr->value, value)) {
        node_destroy(curr);

        if (prec == NULL) {
            return next;
        } else if(next == NULL) {
            prec->next = NULL;
            return list;
        } else {
            prec->next = next;
            return list;
        }
    }

    return list;
}

void linked_list_print(linked_list list) {
    if (linked_list_is_empty(list)) {
        printf("list is empty!\n");
        return;
    }

    struct node* curr = list;
    while(curr != NULL) {
        printf("node: { next: %p ; value: %i }\n", curr->next, curr->value);
        curr = curr->next;
    }
}

struct node* linked_list_search(element value, linked_list list) {
    if (linked_list_is_empty(list)) {
        return NULL;
    }

    struct node* curr = list;
    struct node* next = curr->next;
    while(next != NULL && !equals(curr->value, value)) {
        curr = next;
        next = curr->next;
    }

    if (equals(curr->value, value)) {
        printf("found element {%i} at %p\n", value, curr);
        return curr;
    }

    printf("element {%i} not found!\n", value);
    return NULL;
}
