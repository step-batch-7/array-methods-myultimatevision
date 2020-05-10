#include "../array_void.h"
#include "assert_array_void.h"
#include <stdio.h>
#include <stdlib.h>

Object square(Object data)
{
  int number = *(int *)data;
  int *square = malloc(sizeof(int));
  *square = number * number;
  return square;
}

ArrayVoid_ptr create_array_from(int *array, int length)
{
  ArrayVoid_ptr new_array = malloc(sizeof(ArrayVoid));
  new_array->length = length;
  new_array->array = malloc(sizeof(Object) * 4);
  for (int i = 0; i < length; i++)
  {
    new_array->array[i] = &array[i];
  }
  return new_array;
}

void test_map_void()
{
  printf("map_void\n");
  int *empty_array;
  ArrayVoid_ptr list = create_array_from(empty_array, 0);
  Bool status = assert_values(map_void(list, &square), empty_array, 0);
  print_assert_status(status, "should return empty array when array is empty");

  int array[6] = {1, 2, 3, 4, 5, 6};
  int expected_array1[6] = {1, 4, 9, 16, 25, 36};
  list = create_array_from(array, 6);
  status = assert_values(map_void(list, &square), expected_array1, 6);
  print_assert_status(status, "should give the squares of elements in the array when array is not empty");
}

int main(void)
{
  test_map_void();
  return 0;
}