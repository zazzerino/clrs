//
// Created by kdp on 2/18/22.
//

#include "stack.h"

StackErr stack_init(Stack *s, size_t capacity)
{
    s->capacity = capacity;
    s->top = 0;
    s->items = (int *) malloc(sizeof(int) * capacity);

    if (s->items == NULL) {
        return STACK_MALLOC_ERR;
    }

    return STACK_NO_ERR;
}

void stack_free(Stack *s)
{
    free(s->items);
}

bool stack_is_empty(Stack s)
{
    return s.top == 0;
}

bool stack_is_full(Stack s)
{
    return s.top == s.capacity;
}

StackErr stack_push(Stack *s, int item)
{
    if (stack_is_full(*s)) {
        return STACK_OVERFLOW_ERR;
    }

    s->items[s->top] = item;
    s->top++;
    return STACK_NO_ERR;
}

StackErr stack_pop(Stack *s, int *item)
{
    if (stack_is_empty(*s)) {
        return STACK_UNDERFLOW_ERR;
    }

    s->top--;
    *item = s->items[s->top];
    return STACK_NO_ERR;
}

void stack_print(Stack s)
{
    printf("stack{");
    printf("capacity=%zu, top=%u, ", s.capacity, s.top);
    printf("items=[");

    unsigned int last_index = s.top - 1;

    for (int i = 0; i < s.top; i++) {
        printf("%d", s.items[i]);

        if (i < last_index) {
            printf(",");
        }
    }

    printf("]}\n");
}
