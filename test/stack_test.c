//
// Created by kdp on 2/18/22.
//

#include "stack_test.h"

void run_stack_tests()
{
    struct stack s;
    enum stack_err err;
    int item;

    puts("testing stack...");

    err = stack_init(&s, 2);
    stack_print(s);
    assert(STACK_OK == err);
    assert(stack_is_empty(s));

    err = stack_push(&s, 1);
    stack_print(s);
    assert(STACK_OK == err);
    assert(!stack_is_empty(s));

    err = stack_push(&s, 2);
    stack_print(s);
    assert(STACK_OK == err);
    assert(stack_is_full(s));

    err = stack_push(&s, 3);
    assert(STACK_OVERFLOW_ERR == err);

    err = stack_pop(&s, &item);
    stack_print(s);
    assert(STACK_OK == err);
    assert(2 == item);

    err = stack_pop(&s, &item);
    stack_print(s);
    assert(STACK_OK == err);
    assert(1 == item);

    err = stack_pop(&s, &item);
    stack_print(s);
    assert(STACK_UNDERFLOW_ERR == err);
    assert(1 == item);

    stack_free(&s);
}