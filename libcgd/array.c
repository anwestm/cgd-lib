//
// Created by ANDREAS WESTMAN
// on 2019-01-25.
//

#include "array.h"
#include <malloc.h>
#include <mem.h>

CGD_Array *cgd_array_create(size_t capacity)
{
    CGD_Array *array = (CGD_Array*) malloc(sizeof(CGD_Array));
    array->data = malloc(capacity * sizeof(void*));
    array->used = 0;
    array->size = capacity;

    return array;
}

void cgd_array_insert(CGD_Array *array, void *element, int index)
{
    if (array->used < index && 0 <= index)
    {
        array->data[index] = element;
    }
}

void cgd_array_append(CGD_Array *array, void *element)
{
    if (array->used >= array->size)
    {
        array->size *= 2;
        array->data = realloc(array->data, array->size * sizeof(void*));
    }
    array->data[array->used++] = element;
}

void *cgd_array_get(CGD_Array *array, int index)
{
    if (0 <= index && index <= array->size)
        return array->data[index];
    return NULL;
}

size_t cgd_array_len(CGD_Array *array)
{
    return array->used;
}

void cgd_array_clear(CGD_Array *array)
{
    for (int i = 0; i < cgd_array_len(array); i++)
    {
        array->data[i] = NULL;
    }
    array->used = 0;

}


void cgd_array_free(CGD_Array *array)
{
    free(array->data);
    free(array);
}





