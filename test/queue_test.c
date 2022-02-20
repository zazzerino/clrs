//
// Created by kdp on 2/18/22.
//

#include "queue_test.h"

void run_queue_tests()
{
    Queue q;
    QueueRes res;
    int item;

    puts("testing queue...");

    res = queue_init(&q, 4);
    queue_print(q);
    assert(QUEUE_OK == res);
    assert(queue_is_empty(q));
    assert(!queue_is_full(q));

    res = queue_dequeue(&q, &item);
    assert(QUEUE_UNDERFLOW_ERR == res);

    res = queue_enqueue(&q, 1);
    queue_print(q);
    assert(QUEUE_OK == res);
    assert(!queue_is_empty(q));
    assert(!queue_is_full(q));

    res = queue_enqueue(&q, 2);
    queue_print(q);
    assert(QUEUE_OK == res);
    assert(!queue_is_empty(q));
    assert(!queue_is_full(q));

    res = queue_enqueue(&q, 3);
    queue_print(q);
    assert(QUEUE_OK == res);
    assert(!queue_is_empty(q));
    assert(queue_is_full(q));

    res = queue_enqueue(&q, 4);
    queue_print(q);
    assert(QUEUE_OVERFLOW_ERR == res);

    res = queue_dequeue(&q, &item);
    queue_print(q);
    assert(QUEUE_OK == res);
    assert(1 == item);
    assert(!queue_is_full(q));

    res = queue_enqueue(&q, 4);
    queue_print(q);
    assert(QUEUE_OK == res);
    assert(queue_is_full(q));

    res = queue_dequeue(&q, &item);
    queue_print(q);
    assert(res == QUEUE_OK);
    assert(2 == item);
    assert(!queue_is_full(q));

    res = queue_enqueue(&q, 5);
    queue_print(q);
    assert(res == QUEUE_OK);
    assert(queue_is_full(q));

    res = queue_dequeue(&q, &item);
    queue_print(q);
    assert(res == QUEUE_OK);
    assert(3 == item);

    res = queue_dequeue(&q, &item);
    queue_print(q);
    assert(res == QUEUE_OK);
    assert(4 == item);

    res = queue_dequeue(&q, &item);
    queue_print(q);
    assert(res == QUEUE_OK);
    assert(5 == item);
    assert(queue_is_empty(q));

    res = queue_dequeue(&q, &item);
    queue_print(q);
    assert(res == QUEUE_UNDERFLOW_ERR);

    queue_free(&q);
}