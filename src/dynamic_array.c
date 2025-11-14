#include "dynamic_array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. Initializer
void dynamic_array_init(DynamicArray *arr, size_t initial_capacity) {
    if (!arr) return;
    arr->size = 0;
    arr->capacity = initial_capacity > 0 ? initial_capacity : 4;
    arr->data = malloc(arr->capacity * sizeof(int));
}

// 2. Constructor
DynamicArray* dynamic_array_create(size_t initial_capacity) {
    DynamicArray *arr = malloc(sizeof(DynamicArray));
    if (!arr) return NULL;
    dynamic_array_init(arr, initial_capacity);
    return arr;
}

// 3. Append
void dynamic_array_append(DynamicArray *arr, int value) {
    if (!arr) return;

    if (arr->size >= arr->capacity) {
        arr->capacity *= 2;
        arr->data = realloc(arr->data, arr->capacity * sizeof(int));
    }

    arr->data[arr->size++] = value;
}

// 4. Pop
int dynamic_array_pop(DynamicArray *arr) {
    if (!arr || arr->size == 0) return 0; // or error code
    return arr->data[--arr->size];
}

// 5. Remove at index
void dynamic_array_remove(DynamicArray *arr, size_t index) {
    if (!arr || index >= arr->size) return;
    for (size_t i = index; i < arr->size - 1; i++)
        arr->data[i] = arr->data[i + 1];
    arr->size--;
}

// 6. Get / Set
int dynamic_array_get(const DynamicArray *arr, size_t index) {
    if (!arr || index >= arr->size) return 0; // or error code
    return arr->data[index];
}

void dynamic_array_set(DynamicArray *arr, size_t index, int value) {
    if (!arr || index >= arr->size) return;
    arr->data[index] = value;
}

// 7. Print
void dynamic_array_print(const DynamicArray *arr) {
    if (!arr) return;
    printf("DynamicArray(size=%zu, capacity=%zu): [", arr->size, arr->capacity);
    for (size_t i = 0; i < arr->size; i++) {
        printf("%d", arr->data[i]);
        if (i + 1 < arr->size) printf(", ");
    }
    printf("]\n");
}

// 8. Clear
void dynamic_array_clear(DynamicArray *arr) {
    if (!arr) return;
    arr->size = 0;
}

// 9. Destructor
void dynamic_array_free(DynamicArray *arr) {
    if (!arr) return;
    free(arr->data);
    arr->data = NULL;
    arr->size = 0;
    arr->capacity = 0;
}