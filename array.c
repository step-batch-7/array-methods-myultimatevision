#include "array.h"
#include <stdlib.h>
#include <string.h>

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

Array *filter(Array *src, Predicate predicate)
{
  int temp_array[src->length];
  int count = 0;

  for (int i = 0; i < src->length; i++)
  {
    int number = src->array[i];
    if ((*predicate)(number))
    {
      temp_array[count] = number;
      count++;
    }
  }
  Array *new_array = malloc(sizeof(Array));
  new_array->length = count;
  new_array->array = malloc(sizeof(int) * count);
  memcpy(new_array->array, temp_array, sizeof(int) * count);
  return new_array;
}