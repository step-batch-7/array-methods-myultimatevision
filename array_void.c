#include "array_void.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

ArrayVoid_ptr filter_void(ArrayVoid_ptr src, PredicateVoid predicate)
{
  Object temp_array[src->length];
  int count = 0;

  for (int i = 0; i < src->length; i++)
  {
    Object number = src->array[i];
    if ((*predicate)(number))
    {
      temp_array[count] = number;
      count++;
    }
  }
  ArrayVoid_ptr new_array = malloc(sizeof(ArrayVoid));
  new_array->length = count;
  new_array->array = malloc(sizeof(Object) * count);
  memcpy(new_array->array, temp_array, sizeof(Object) * count);
  return new_array;
}

Object reduce_void(ArrayVoid_ptr src, Object init, ReducerVoid reducer)
{
  for (int i = 0; i < src->length; i++)
  {
    init = (*reducer)(init, src->array[i]);
  }
  return init;
}