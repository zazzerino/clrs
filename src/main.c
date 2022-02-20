//
// Created by kdp on 2/18/22.
//

#include <stdio.h>
#include "../test/stack_test.h"
#include "../test/queue_test.h"

int main()
{
    puts("running tests...");

    run_stack_tests();
    run_queue_tests();

    return 0;
}
