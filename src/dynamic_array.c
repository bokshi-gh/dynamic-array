#include "dynamic_array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dynamic_array_init(DynamicArray *arr, size_t initial_capacity) {
    if (!arr) return;
    arr->size = 0;
    arr->capacity = initial_capacity > 0 ? initial_capacity : 4;
    arr->data = malloc(arr->capacity * sizeof(int));
}

DynamicArray* dynamic_array_create(size_t initial_capacity) {
    DynamicArray *arr = malloc(sizeof(DynamicArray));
    if (!arr) return NULL;
    dynamic_array_init(arr, initial_capacity);
    return arr;
}

void dynamic_array_append(DynamicArray *arr, int value) {
    if (!arr) return;

    if (arr->size >= arr->capacity) {
        arr->capacity *= 2;
        arr->data = realloc(arr->data, arr->capacity * sizeof(int));
    }

    arr->data[arr->size++] = value;
}

int dynamic_array_pop(DynamicArray *arr) {
    if (!arr || arr->size == 0) return 0; // or error code
    return arr->data[--arr->size];
}

void dynamic_array_remove(DynamicArray *arr, size_t index) {
    if (!arr || index >= arr->size) return;
    for (size_t i = index; i < arr->size - 1; i++)
        arr->data[i] = arr->data[i + 1];
    arr->size--;
}

int dynamic_array_get(const DynamicArray *arr, size_t index) {
    if (!arr || index >= arr->size) return 0; // or error code
    return arr->data[index];
}

void dynamic_array_set(DynamicArray *arr, size_t index, int value) {
    if (!arr || index >= arr->size) return;
    arr->data[index] = value;
}

void dynamic_array_print(const DynamicArray *arr) {
    if (!arr) return;
    printf("DynamicArray(size=%zu, capacity=%zu): [", arr->size, arr->capacity);
    for (size_t i = 0; i < arr->size; i++) {
        printf("%d", arr->data[i]);
        if (i + 1 < arr->size) printf(", ");
    }
    printf("]\n");
}

void dynamic_array_clear(DynamicArray *arr) {
    if (!arr) return;
    arr->size = 0;
}

void dynamic_array_free(DynamicArray *arr) {
    if (!arr) return;
    free(arr->data);
    arr->data = NULL;
    arr->size = 0;
    arr->capacity = 0;
}
