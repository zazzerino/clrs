//
// Created by kdp on 2/18/22.
//

#ifndef CLRS_STACK_H
#define CLRS_STACK_H

#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct
{
    size_t capacity;
    unsigned int top;
    int *items;
} Stack;

typedef enum
{
    STACK_NO_ERR,
    STACK_MALLOC_ERR,
    STACK_OVERFLOW_ERR,
    STACK_UNDERFLOW_ERR,
} StackErr;

StackErr stack_init(Stack *s, size_t capacity);

void stack_free(Stack*);

bool stack_is_empty(Stack);

bool stack_is_full(Stack);

StackErr stack_push(Stack *s, int item);

StackErr stack_pop(Stack *s, int *item);

void stack_print(Stack);

#endif //CLRS_STACK_H