//
// Created by kdp on 2/18/22.
//

#include "stack.h"

enum stack_err stack_init(struct stack *s, size_t capacity)
{
    s->capacity = capacity;
    s->top = 0;
    s->items = malloc(sizeof(int) * capacity);

    if (NULL == s->items) {
        return STACK_MALLOC_ERR;
    }

    return STACK_OK;
}

void stack_free(struct stack *s)
{
    free(s->items);
}

bool stack_is_empty(struct stack s)
{
    return 0 == s.top;
}

bool stack_is_full(struct stack s)
{
    return s.top == s.capacity;
}

enum stack_err stack_push(struct stack *s, int item)
{
    if (stack_is_full(*s)) {
        return STACK_OVERFLOW_ERR;
    }

    s->items[s->top] = item;
    ++s->top;
    return STACK_OK;
}

enum stack_err stack_pop(struct stack *s, int *item)
{
    if (stack_is_empty(*s)) {
        return STACK_UNDERFLOW_ERR;
    }

    --s->top;
    *item = s->items[s->top];
    return STACK_OK;
}

void stack_print(struct stack s)
{
    printf("stack{capacity=%zu, top=%zu, items=[", s.capacity, s.top);

    for (size_t i = 0; i < s.top; i++) {
        printf("%d", s.items[i]);

        if (i < (s.top - 1)) {
            printf(",");
        }
    }

    puts("]}");
}
