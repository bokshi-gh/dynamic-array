#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stddef.h> // for size_t

// DynamicArray struct
typedef struct {
    int *data;       // pointer to elements
    size_t size;     // current number of elements
    size_t capacity; // allocated capacity
} DynamicArray;

// 1. Initializer (stack or pre-allocated object)
void dynamic_array_init(DynamicArray *arr, size_t initial_capacity);

// 2. Constructor (heap allocation + init)
DynamicArray* dynamic_array_create(size_t initial_capacity);

// 3. Append element at end
void dynamic_array_append(DynamicArray *arr, int value);

// 4. Pop element from end
int dynamic_array_pop(DynamicArray *arr);

// 5. Remove element at index
void dynamic_array_remove(DynamicArray *arr, size_t index);

// 6. Get / Set element
int dynamic_array_get(const DynamicArray *arr, size_t index);
void dynamic_array_set(DynamicArray *arr, size_t index, int value);

// 7. Print array (debug)
void dynamic_array_print(const DynamicArray *arr);

// 8. Clear all elements
void dynamic_array_clear(DynamicArray *arr);

// 9. Destructor (free internal memory)
void dynamic_array_free(DynamicArray *arr);

#endif // DYNAMIC_ARRAY_H