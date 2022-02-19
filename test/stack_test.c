//
// Created by kdp on 2/18/22.
//

#include "stack_test.h"

void run_stack_tests()
{
    Stack s;
    StackErr err;
    int item;

    printf("testing stack...\n");

    err = stack_init(&s, 2);
    stack_print(s);
    assert(err == STACK_NO_ERR);
    assert(stack_is_empty(s));

    err = stack_push(&s, 42);
    stack_print(s);
    assert(err == STACK_NO_ERR);
    assert(!stack_is_empty(s));

    err = stack_push(&s, 111);
    stack_print(s);
    assert(err == STACK_NO_ERR);
    assert(stack_is_full(s));

    err = stack_push(&s, 64);
    assert(err == STACK_OVERFLOW_ERR);

    err = stack_pop(&s, &item);
    stack_print(s);
    assert(err == STACK_NO_ERR);
    assert(item == 111);

    err = stack_pop(&s, &item);
    stack_print(s);
    assert(err == STACK_NO_ERR);
    assert(item == 42);

    err = stack_pop(&s, &item);
    stack_print(s);
    assert(err == STACK_UNDERFLOW_ERR);
    assert(item == 42);

    stack_free(&s);
}