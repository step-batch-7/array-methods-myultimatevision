#include "array.h"
#include "array_void.h"
#include <stdio.h>
#include <stdlib.h>

Object square(Object data)
{
  int number = *(int *)data;
  int *square = malloc(sizeof(int));
  *square = number * number;
  return square;
}

Bool isEven(Object data)
{
  int number = *(int *)data;
  return number % 2 == 0;
}

Object sum_of_numbers(Object initial, Object data)
{
  int number = *(int *)data;
  int *sum = malloc(sizeof(int));
  *sum = *(int *)initial + number;
  return sum;
}

void print_array(ArrayVoid_ptr list)
{
  for (int i = 0; i < list->length; i++)
  {
    int *number = (int *)list->array[i];
    printf("%d\n", *number);
  }
  printf("\n");
}

int main(void)
{
  int array[6] = {1, 2, 3, 4, 5, 6};
  ArrayVoid_ptr list = malloc(sizeof(ArrayVoid));
  list->length = 6;
  list->array = malloc(sizeof(Object) * 6);
  list->array[0] = &array[0];
  list->array[1] = &array[1];
  list->array[2] = &array[2];
  list->array[3] = &array[3];
  list->array[4] = &array[4];
  list->array[5] = &array[5];
  ArrayVoid_ptr mapped_array = map_void(list, &square);
  print_array(mapped_array);
  ArrayVoid_ptr filtered_array = filter_void(list, &isEven);
  print_array(filtered_array);
  int initial = 0;
  Object sum = reduce_void(list, &initial, &sum_of_numbers);
  printf("%d\n", *(int *)sum);

  return 0;
}