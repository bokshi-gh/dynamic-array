#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stddef.h>

typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} DynamicArray;

void dynamic_array_init(DynamicArray *arr);
void dynamic_array_deinit(DynamicArray *arr);

void dynamic_array_push_back(DynamicArray *arr, int value);
void dynamic_array_pop_back(DynamicArray *arr);

int dynamic_array_at(DynamicArray *arr, size_t index);
int dynamic_array_front(DynamicArray *arr);
int dynamic_array_back(DynamicArray *arr);

#endif
