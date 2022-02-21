cmake_minimum_required(VERSION 3.21)
project(clrs C)

set(CMAKE_C_STANDARD 17)

add_executable(clrs src/main.c src/stack.c src/stack.h test/stack_test.c test/stack_test.h src/queue.c src/queue.h test/queue_test.c test/queue_test.h src/dllist.c src/dllist.h test/dllist_test.c test/dllist_test.h)
