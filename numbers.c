#include "array.h"
#include <stdio.h>
#include <stdlib.h>

int square(int number)
{
  return number * number;
}

void print_array(Array *list)
{
  for (int i = 0; i < list->length; i++)
  {
    printf("%d\n", list->array[i]);
  }
  printf("\n");
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
  print_array(mapped_array);

  return 0;
}