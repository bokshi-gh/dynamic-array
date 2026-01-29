#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stddef.h>

typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} DynamicArray;

void dynamic_array_init(DynamicArray *arr, size_t initial_capacity);

DynamicArray* dynamic_array_create(size_t initial_capacity);

void dynamic_array_append(DynamicArray *arr, int value);

int dynamic_array_pop(DynamicArray *arr);

void dynamic_array_remove(DynamicArray *arr, size_t index);

int dynamic_array_get(const DynamicArray *arr, size_t index);
void dynamic_array_set(DynamicArray *arr, size_t index, int value);

void dynamic_array_print(const DynamicArray *arr);

void dynamic_array_clear(DynamicArray *arr);

void dynamic_array_free(DynamicArray *arr);

#endif
