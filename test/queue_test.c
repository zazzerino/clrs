//
// Created by kdp on 2/18/22.
//

#include "queue_test.h"

void run_queue_tests()
{
    struct queue q;
    enum queue_err err;
    int item;

    puts("testing queue...");

    err = queue_init(&q, 4);
    queue_print(q);
    assert(QUEUE_OK == err);
    assert(queue_is_empty(q));
    assert(!queue_is_full(q));

    err = queue_dequeue(&q, &item);
    assert(QUEUE_UNDERFLOW_ERR == err);

    err = queue_enqueue(&q, 1);
    queue_print(q);
    assert(QUEUE_OK == err);
    assert(!queue_is_empty(q));
    assert(!queue_is_full(q));

    err = queue_enqueue(&q, 2);
    queue_print(q);
    assert(QUEUE_OK == err);
    assert(!queue_is_empty(q));
    assert(!queue_is_full(q));

    err = queue_enqueue(&q, 3);
    queue_print(q);
    assert(QUEUE_OK == err);
    assert(!queue_is_empty(q));
    assert(queue_is_full(q));

    err = queue_enqueue(&q, 4);
    queue_print(q);
    assert(QUEUE_OVERFLOW_ERR == err);

    err = queue_dequeue(&q, &item);
    queue_print(q);
    assert(QUEUE_OK == err);
    assert(1 == item);
    assert(!queue_is_full(q));

    err = queue_enqueue(&q, 4);
    queue_print(q);
    assert(QUEUE_OK == err);
    assert(queue_is_full(q));

    err = queue_dequeue(&q, &item);
    queue_print(q);
    assert(err == QUEUE_OK);
    assert(2 == item);
    assert(!queue_is_full(q));

    err = queue_enqueue(&q, 5);
    queue_print(q);
    assert(err == QUEUE_OK);
    assert(queue_is_full(q));

    err = queue_dequeue(&q, &item);
    queue_print(q);
    assert(err == QUEUE_OK);
    assert(3 == item);

    err = queue_dequeue(&q, &item);
    queue_print(q);
    assert(err == QUEUE_OK);
    assert(4 == item);

    err = queue_dequeue(&q, &item);
    queue_print(q);
    assert(err == QUEUE_OK);
    assert(5 == item);
    assert(queue_is_empty(q));

    err = queue_dequeue(&q, &item);
    queue_print(q);
    assert(err == QUEUE_UNDERFLOW_ERR);

    err = queue_enqueue(&q, 6);
    queue_print(q);
    assert(err == QUEUE_OK);

    err = queue_enqueue(&q, 7);
    queue_print(q);
    assert(err == QUEUE_OK);

    err = queue_enqueue(&q, 8);
    queue_print(q);
    assert(err == QUEUE_OK);
    assert(queue_is_full(q));

    queue_free(&q);
}