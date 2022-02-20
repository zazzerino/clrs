//
// Created by kdp on 2/19/22.
//

#include "dll.h"

struct dll_node* dll_create_node(int key)
{
    struct dll_node* node = malloc(sizeof(struct dll_node));
    node->key = key;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

struct dll* dll_create()
{
    struct dll* dll = malloc(sizeof(struct dll));
    dll->head = NULL;
    return dll;
}

struct dll_node* dll_search(struct dll *dll, int key)
{
    struct dll_node *node = dll->head;

    while (NULL != node
           && key != node->key)
    {
        node = node->next;
    }

    return node;
}

void dll_insert_node(struct dll *dll, struct dll_node *node)
{
    node->next = dll->head;

    if (NULL != dll->head) {
        dll->head->prev = node;
    }

    dll->head = node;
    node->prev = NULL;
}

void dll_delete_node(struct dll *dll, struct dll_node *node)
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

void dll_free(struct dll *dll)
{
    if (NULL == dll->head) return;

    struct dll_node *node = dll->head;

    while (NULL != node->next) {
        node = node->next;
        free(node->prev);
    }

    free(node);
    free(dll);
}

void dll_print_node(struct dll_node node)
{
    printf("node{key=%d, next=%p, prev=%p}", node.key, node.next, node.prev);
}

//void dll_print(dll_node head)
//{
//    printf("dll{items=[");
//    dll_node *node = &head;
//
//    while (NULL != node)
//    {
//        dll_print_node(*node);
//        node = node->next;
//    }
//
//    puts("]}");
//}
