#include <stdio.h>
#include <stdlib.h>
#include "dynamic_array.h"

int main() {
    // Stack-allocated
    DynamicArray arr;
    dynamic_array_init(&arr, 2);

    dynamic_array_append(&arr, 10);
    dynamic_array_append(&arr, 20);
    dynamic_array_append(&arr, 30);

    dynamic_array_print(&arr);

    int last = dynamic_array_pop(&arr);
    printf("Popped: %d\n", last);
    dynamic_array_print(&arr);

    dynamic_array_remove(&arr, 0);
    dynamic_array_print(&arr);

    dynamic_array_clear(&arr);
    dynamic_array_print(&arr);

    dynamic_array_free(&arr);

    // Heap-allocated
    DynamicArray *heap_arr = dynamic_array_create(3);
    dynamic_array_append(heap_arr, 1);
    dynamic_array_append(heap_arr, 2);
    dynamic_array_append(heap_arr, 3);

    dynamic_array_print(heap_arr);

    dynamic_array_free(heap_arr);
    free(heap_arr);

    return 0;
}