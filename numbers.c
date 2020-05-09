#include "array.h"
#include <stdio.h>
#include <stdlib.h>

int square(int number)
{
  return number * number;
}

int main(void)
{
  Array *list = malloc(sizeof(Array));
  list->length = 6;
  list->array = malloc(sizeof(int) * 6);
  list->array[0] = 1;
  list->array[1] = 2;
  list->array[2] = 3;
  list->array[3] = 4;
  list->array[4] = 5;
  list->array[5] = 6;
  Array *mapped_array = map(list, &square);
  for (int i = 0; i < mapped_array->length; i++)
  {
    printf("%d\n", mapped_array->array[i]);
  }

  return 0;
}