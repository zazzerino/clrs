//
// Created by kdp on 2/18/22.
//

#ifndef CLRS_QUEUE_H
#define CLRS_QUEUE_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct queue
{
    size_t capacity;
    size_t head;
    size_t tail;
    int *items;
};

enum queue_err
{
    QUEUE_OK,
    QUEUE_MALLOC_ERR,
    QUEUE_UNDERFLOW_ERR,
    QUEUE_OVERFLOW_ERR,
};

enum queue_err queue_init(struct queue *q, size_t capacity);

void queue_free(struct queue *q);

bool queue_is_empty(struct queue);

bool queue_is_full(struct queue);

enum queue_err queue_enqueue(struct queue *q, int item);

enum queue_err queue_dequeue(struct queue *q, int *item);

void queue_print(struct queue);

#endif //CLRS_QUEUE_H
