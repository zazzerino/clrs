//
// Created by kdp on 2/18/22.
//

#ifndef CLRS_QUEUE_H
#define CLRS_QUEUE_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct
{
    size_t capacity;
    unsigned int head;
    unsigned int tail;
    int *items;
} Queue;

typedef enum
{
    QUEUE_NO_ERR,
    QUEUE_MALLOC_ERR,
    QUEUE_UNDERFLOW_ERR,
    QUEUE_OVERFLOW_ERR,
} QueueErr;

QueueErr queue_init(Queue *q, size_t capacity);

void queue_free(Queue*);

bool queue_is_empty(Queue);

bool queue_is_full(Queue);

QueueErr queue_enqueue(Queue *q, int item);

QueueErr queue_dequeue(Queue *q, int *item);

void queue_print(Queue);

#endif //CLRS_QUEUE_H
