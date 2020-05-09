#include "array.h"
#include <stdlib.h>

Array *map(Array *src, Mapper mapper)
{
  Array *mapped_array = malloc(sizeof(Array));

  mapped_array->array = malloc(src->length * sizeof(int));
  mapped_array->length = src->length;
  for (int i = 0; i < src->length; i++)
  {
    mapped_array->array[i] = (*mapper)(src->array[i]);
  }
  return mapped_array;
}