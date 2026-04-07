#include "dynamic_array.h"
#include <stdlib.h>
#include <stdio.h>

static void dynamic_array_resize(DynamicArray *arr) {
    arr->capacity *= 2;
    int *new_data = (int *)realloc(arr->data, arr->capacity * sizeof(int));

    if (!new_data) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    arr->data = new_data;
}

void dynamic_array_init(DynamicArray *arr) {
    arr->size = 0;
    arr->capacity = 2;
    arr->data = (int *)malloc(arr->capacity * sizeof(int));

    if (!arr->data) {
        printf("Memory allocation failed\n");
        exit(1);
    }
}

void dynamic_array_deinit(DynamicArray *arr) {
    free(arr->data);
    arr->data = NULL;
    arr->size = 0;
    arr->capacity = 0;
}

void dynamic_array_push_back(DynamicArray *arr, int value) {
    if (arr->size == arr->capacity) {
        dynamic_array_resize(arr);
    }
    arr->data[arr->size++] = value;
}

void dynamic_array_pop_back(DynamicArray *arr) {
    if (arr->size == 0) {
        printf("Array is empty\n");
        return;
    }
    arr->size--;
}

int dynamic_array_at(DynamicArray *arr, size_t index) {
    if (index >= arr->size) {
        printf("Index out of bounds\n");
        exit(1);
    }
    return arr->data[index];
}

int dynamic_array_front(DynamicArray *arr) {
    if (arr->size == 0) {
        printf("Array is empty\n");
        exit(1);
    }
    return arr->data[0];
}

int dynamic_array_back(DynamicArray *arr) {
    if (arr->size == 0) {
        printf("Array is empty\n");
        exit(1);
    }
    return arr->data[arr->size - 1];
}
