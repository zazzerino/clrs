//
// Created by kdp on 2/18/22.
//

#ifndef CLRS_STACK_H
#define CLRS_STACK_H

#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>

struct stack
{
    size_t capacity;
    size_t top;
    int *items;
};

enum stack_err
{
    STACK_OK,
    STACK_MALLOC_ERR,
    STACK_OVERFLOW_ERR,
    STACK_UNDERFLOW_ERR,
};

enum stack_err stack_init(struct stack *s, size_t capacity);

void stack_free(struct stack *s);

bool stack_is_empty(struct stack);

bool stack_is_full(struct stack);

enum stack_err stack_push(struct stack *s, int item);

enum stack_err stack_pop(struct  stack *s, int *item);

void stack_print(struct stack);

#endif //CLRS_STACK_H
