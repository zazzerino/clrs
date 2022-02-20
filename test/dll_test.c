//
// Created by kdp on 2/19/22.
//

#include "dll_test.h"

void run_dll_tests()
{
    puts("running dll tests");

    struct dll_node *node;
    struct dll *dll = dll_create();
    assert(NULL != dll);

    struct dll_node *n0 = dll_create_node(1);
    dll_insert_node(dll, n0);
    assert(1 == dll->head->key);

    struct dll_node *n1 = dll_create_node(4);
    dll_insert_node(dll, n1);
    assert(4 == dll->head->key);
    assert(1 == dll->head->next->key);

    node = dll_search(dll, 1);
    assert(node == n0);
    assert(1 == node->key);

    node = dll_search(dll, 4);
    assert(node == n1);
    assert(4 == node->key);

    node = dll_search(dll, 1234);
    assert(NULL == node);

    dll_delete_node(dll, n1);
    node = dll_search(dll, 4);
    assert(NULL == node);

    dll_free(dll);
}