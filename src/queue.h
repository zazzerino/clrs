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
    size_t head;
    size_t tail;
    int *items;
} Queue;

typedef enum
{
    QUEUE_OK,
    QUEUE_MALLOC_ERR,
    QUEUE_UNDERFLOW_ERR,
    QUEUE_OVERFLOW_ERR,
} QueueRes;

QueueRes queue_init(Queue *q, size_t capacity);

void queue_free(Queue *);

bool queue_is_empty(Queue);

bool queue_is_full(Queue);

QueueRes queue_enqueue(Queue *q, int item);

QueueRes queue_dequeue(Queue *q, int *item);

void queue_print(Queue);

#endif //CLRS_QUEUE_H
