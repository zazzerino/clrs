//
// Created by kdp on 2/18/22.
//

#include "stack_test.h"

void run_stack_tests()
{
    Stack s;
    StackRes res;
    int item;

    puts("testing stack...");

    res = stack_init(&s, 2);
    stack_print(s);
    assert(STACK_OK == res);
    assert(stack_is_empty(s));

    res = stack_push(&s, 1);
    stack_print(s);
    assert(STACK_OK == res);
    assert(!stack_is_empty(s));

    res = stack_push(&s, 2);
    stack_print(s);
    assert(STACK_OK == res);
    assert(stack_is_full(s));

    res = stack_push(&s, 3);
    assert(STACK_OVERFLOW_ERR == res);

    res = stack_pop(&s, &item);
    stack_print(s);
    assert(STACK_OK == res);
    assert(2 == item);

    res = stack_pop(&s, &item);
    stack_print(s);
    assert(STACK_OK == res);
    assert(1 == item);

    res = stack_pop(&s, &item);
    stack_print(s);
    assert(STACK_UNDERFLOW_ERR == res);
    assert(1 == item);

    stack_free(&s);
}