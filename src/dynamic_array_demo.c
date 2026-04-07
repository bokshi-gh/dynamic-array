#include <stdio.h>
#include "dynamic_array.h"

int main() {
    DynamicArray arr;
    dynamic_array_init(&arr);

    dynamic_array_push_back(&arr, 100);
    dynamic_array_push_back(&arr, 200);
    dynamic_array_push_back(&arr, 300);

    printf("Front: %d\n", dynamic_array_front(&arr));
    printf("Back: %d\n", dynamic_array_back(&arr));
    printf("At index 1: %d\n", dynamic_array_at(&arr, 1));

    dynamic_array_pop_back(&arr);
    printf("Back after pop: %d\n", dynamic_array_back(&arr));

    dynamic_array_deinit(&arr);
    return 0;
}
