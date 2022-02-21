//
// Created by kdp on 2/19/22.
//

#ifndef CLRS_DLLIST_H
#define CLRS_DLLIST_H

#include <malloc.h>

struct dll_node
{
    int key;
    struct dll_node *next;
    struct dll_node *prev;
};

struct dllist
{
    struct dll_node *head;
};

struct dllist *dllist_create();

struct dll_node *dllist_create_node(int key);

void dllist_print(struct dllist);

struct dll_node *dllist_search(struct dllist *dll, int key);

void dllist_insert_node(struct dllist *dll, struct dll_node *node);

void dllist_delete_node(struct dllist *dll, struct dll_node *node);

void dllist_delete(struct dllist *dll);

#endif //CLRS_DLLIST_H
