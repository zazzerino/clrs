//
// Created by kdp on 2/18/22.
//

#include "queue.h"

QueueRes queue_init(Queue *q, size_t capacity)
{
    q->capacity = capacity;
    q->head = 0;
    q->tail = 0;
    q->items = malloc(sizeof(int) * capacity);

    if (NULL == q->items) {
        return QUEUE_MALLOC_ERR;
    }

    return QUEUE_OK;
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

QueueRes queue_enqueue(Queue *q, int item)
{
    if (queue_is_full(*q)) {
        return QUEUE_OVERFLOW_ERR;
    }

    q->items[q->tail] = item;
    q->tail = (q->capacity - 1) == q->tail
              ? 0
              : q->tail + 1;

    return QUEUE_OK;
}

QueueRes queue_dequeue(Queue *q, int *item)
{
    if (queue_is_empty(*q)) {
        return QUEUE_UNDERFLOW_ERR;
    }

    *item = q->items[q->head];
    q->head = (q->capacity - 1) == q->head
              ? 0
              : q->head + 1;

    return QUEUE_OK;
}

void queue_print(Queue q)
{
    printf("queue{capacity=%zu, head=%zu, tail=%zu, items=[", q.capacity, q.head, q.tail);

    if (q.head <= q.tail) {
        for (size_t i = q.head; i < q.tail; i++) {
            printf("%d", q.items[i]);

            if (i < (q.tail - 1)) {
                printf(",");
            }
        }
    } else {
        for (size_t i = q.head; i < q.capacity; i++) {
            printf("%d", q.items[i]);

            if (i < (q.capacity - 1) || q.tail > 0) {
                printf(",");
            }
        }

        for (size_t i = 0; i < q.tail; i++) {
            printf("%d", q.items[i]);

            if (i < (q.tail - 1)) {
                printf(",");
            }
        }
    }

    puts("]}");
}
