//
// Created by kdp on 2/18/22.
//

#include "queue.h"

QueueErr queue_init(Queue *q, size_t capacity)
{
    q->capacity = capacity;
    q->head = 0;
    q->tail = 0;
    q->items = (int *) malloc(sizeof(int) * capacity);

    if (q->items == NULL) {
        return QUEUE_MALLOC_ERR;
    }

    return QUEUE_NO_ERR;
}

void queue_free(Queue *q)
{
    free(q->items);
}

bool queue_is_empty(Queue q)
{
    return q.head == q.tail;
}

bool queue_is_full(Queue q)
{
    return q.head == (q.tail + 1) % q.capacity;
}

QueueErr queue_enqueue(Queue *q, int item)
{
    if (queue_is_full(*q)) {
        return QUEUE_OVERFLOW_ERR;
    }

    q->items[q->tail] = item;
    q->tail = q->tail == q->capacity
              ? 0
              : q->tail + 1;

    return QUEUE_NO_ERR;
}

QueueErr queue_dequeue(Queue *q, int *item)
{
    if (queue_is_empty(*q)) {
        return QUEUE_UNDERFLOW_ERR;
    }

    *item = q->items[q->head];
    q->head = q->head == q->capacity
              ? 0
              : q->head + 1;

    return QUEUE_NO_ERR;
}

void queue_print(Queue q)
{
    printf("queue{capacity=%zu, head=%u, tail=%u}\n", q.capacity, q.head, q.tail);
}
