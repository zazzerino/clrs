//
// Created by kdp on 2/18/22.
//

#include "queue_test.h"

void run_queue_tests()
{
    Queue q;
    QueueErr err;
    int item;

    printf("testing queue...\n");

    err = queue_init(&q, 3);
    queue_print(q);
    assert(err == QUEUE_NO_ERR);
    assert(queue_is_empty(q));
    assert(!queue_is_full(q));

    err = queue_dequeue(&q, &item);
    assert(err == QUEUE_UNDERFLOW_ERR);

    err = queue_enqueue(&q, 0);
    queue_print(q);
    assert(err == QUEUE_NO_ERR);
    assert(!queue_is_empty(q));
    assert(!queue_is_full(q));

    err = queue_enqueue(&q, 1);
    queue_print(q);
    assert(err == QUEUE_NO_ERR);
    assert(!queue_is_empty(q));
    assert(queue_is_full(q));

    err = queue_enqueue(&q, 2);
    queue_print(q);
    assert(err == QUEUE_OVERFLOW_ERR);

    err = queue_dequeue(&q, &item);
    queue_print(q);
    assert(err == QUEUE_NO_ERR);
    assert(0 == item);

    err = queue_dequeue(&q, &item);
    queue_print(q);
    assert(err == QUEUE_NO_ERR);
    assert(queue_is_empty(q));
    assert(1 == item);

    err = queue_dequeue(&q, &item);
    queue_print(q);
    assert(err == QUEUE_UNDERFLOW_ERR);

    err = queue_enqueue(&q, 3);
    queue_print(q);
    assert(err == QUEUE_NO_ERR);

    err = queue_enqueue(&q, 4);
    queue_print(q);
    assert(err == QUEUE_NO_ERR);

    err = queue_dequeue(&q, &item);
    queue_print(q);
    assert(err == QUEUE_NO_ERR);
    assert(3 == item);

    err = queue_enqueue(&q, 5);
    queue_print(q);
    assert(err == QUEUE_NO_ERR);

    err = queue_dequeue(&q, &item);
    queue_print(q);
    assert(err == QUEUE_NO_ERR);
    assert(4 == item);

    queue_free(&q);
}