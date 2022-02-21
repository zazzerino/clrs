//
// Created by kdp on 2/19/22.
//

#include "dllist_test.h"

void run_dll_tests()
{
    puts("running dllist tests");

    struct dll_node *node;
    struct dllist *dll;

    dll = dllist_create();
    dllist_print(*dll);
    assert(NULL != dll);

    struct dll_node *n0 = dllist_create_node(1);
    dllist_insert_node(dll, n0);
    dllist_print(*dll);
    assert(1 == dll->head->key);

    struct dll_node *n1 = dllist_create_node(4);
    dllist_insert_node(dll, n1);
    dllist_print(*dll);
    assert(4 == dll->head->key);
    assert(1 == dll->head->next->key);

    struct dll_node *n2 = dllist_create_node(16);
    dllist_insert_node(dll, n2);
    dllist_print(*dll);
    assert(16 == dll->head->key);

    node = dllist_search(dll, 1);
    assert(node == n0);
    assert(1 == node->key);

    node = dllist_search(dll, 4);
    assert(node == n1);
    assert(4 == node->key);

    node = dllist_search(dll, 1234);
    assert(NULL == node);

    dllist_delete_node(dll, n1);
    node = dllist_search(dll, 4);
    assert(NULL == node);

    dllist_delete(dll);
}