//
// Created by kdp on 2/19/22.
//

#include "dllist.h"

struct dllist *dllist_create()
{
    struct dllist *dll = malloc(sizeof(struct dllist));
    dll->head = NULL;
    return dll;
}

struct dll_node *dllist_create_node(int key)
{
    struct dll_node *node = malloc(sizeof(struct dll_node));
    node->key = key;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

struct dll_node *dllist_search(struct dllist *dll, int key)
{
    struct dll_node *node = dll->head;

    while (NULL != node
           && key != node->key)
    {
        node = node->next;
    }

    return node;
}

void dllist_insert_node(struct dllist *dll, struct dll_node *node)
{
    node->next = dll->head;

    if (NULL != dll->head) {
        dll->head->prev = node;
    }

    dll->head = node;
    node->prev = NULL;
}

void dllist_delete_node(struct dllist *dll, struct dll_node *node)
{
    if (NULL != node->prev) {
        node->prev->next = node->next;
    } else {
        dll->head = node->next;
    }

    if (NULL != node->next) {
        node->next->prev = node->prev;
    }

    free(node);
}

void dllist_delete(struct dllist *dll)
{
    if (NULL == dll->head) {
        goto exit;
    };

    struct dll_node *node = dll->head;

    while (NULL != node->next) {
        node = node->next;
        free(node->prev);
    }

    free(node);

    exit:
    free(dll);
}

void dll_print_node(struct dll_node node)
{
    printf("node{key=%d, next=%p, prev=%p}", node.key, node.next, node.prev);
}

void dllist_print(struct dllist dll)
{
    printf("dllist{items=[");
    struct dll_node *node = dll.head;

    while (NULL != node)
    {
        dll_print_node(*node);
        node = node->next;

        if (node) {
            printf(", ");
        }
    }

    puts("]}");
}
