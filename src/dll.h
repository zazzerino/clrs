//
// Created by kdp on 2/19/22.
//

#ifndef CLRS_DLL_H
#define CLRS_DLL_H

#include <malloc.h>

struct dll_node
{
    int key;
    struct dll_node *next;
    struct dll_node *prev;
};

struct dll
{
    struct dll_node *head;
};

struct dll_node* dll_create_node(int key);

struct dll* dll_create();

struct dll_node* dll_search(struct dll *dll, int key);

void dll_insert_node(struct dll *dll, struct dll_node *node);

void dll_delete_node(struct dll *dll, struct dll_node *node);

void dll_free(struct dll *dll);

#endif //CLRS_DLL_H
