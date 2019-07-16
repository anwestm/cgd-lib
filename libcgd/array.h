//
// Created by ANDREAS WESTMAN
// on 2019-01-25.
//

#ifndef CGD_LIB_ARRAY_H
#define CGD_LIB_ARRAY_H

#include <stdlib.h>

#define DA()

typedef struct {
    void **data;
    size_t used;
    size_t size;
} CGD_Array;

CGD_Array *cgd_array_create(size_t capacity);
void cgd_array_insert(CGD_Array *array, void *element, int index);
void cgd_array_append(CGD_Array *array, void *element);
void *cgd_array_get(CGD_Array *array, int index);
size_t cgd_array_len(CGD_Array *array);
void cgd_array_clear(CGD_Array *array);
void cgd_array_free(CGD_Array *array);


#endif //CGD_LIB_ARRAY_H
