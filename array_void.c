#include "array_void.h"
#include <stdio.h>
#include <stdlib.h>

ArrayVoid_ptr map_void(ArrayVoid_ptr src, MapperVoid mapper)
{
  ArrayVoid_ptr mapped_array = malloc(sizeof(ArrayVoid));
  mapped_array->array = malloc(sizeof(Object) * src->length);
  for (int i = 0; i < src->length; i++)
  {
    mapped_array->array[i] = (*mapper)(src->array[i]);
  }
  mapped_array->length = src->length;
  return mapped_array;
}