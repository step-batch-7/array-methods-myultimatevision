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

Bool is_even(Object data)
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

ArrayVoid_ptr create_array_from(int *array, int length)
{
  ArrayVoid_ptr new_array = malloc(sizeof(ArrayVoid));
  new_array->length = length;
  new_array->array = malloc(sizeof(Object) * length);
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
  print_assert_status(status, "should give empty array when array is empty");

  int array[6] = {1, 2, 3, 4, 5, 6};
  int expected_array1[6] = {1, 4, 9, 16, 25, 36};
  list = create_array_from(array, 6);
  status = assert_values(map_void(list, &square), expected_array1, 6);
  print_assert_status(status, "should give the squares of elements in the array when array is not empty");
}

void test_filter_void()
{
  printf("filter_void\n");
  int *empty_array;

  ArrayVoid_ptr list = create_array_from(empty_array, 0);
  Bool status = assert_values(filter_void(list, &is_even), empty_array, 0);
  print_assert_status(status, "should give empty array when array is empty");

  int array1[5] = {1, 3, 7, 5, 11};
  list = create_array_from(array1, 5);
  status = assert_values(filter_void(list, &is_even), empty_array, 0);
  print_assert_status(status, "should give the empty array when array has no even numbers");

  int array2[6] = {1, 2, 3, 4, 5, 6};
  int expected_array1[3] = {2, 4, 6};
  list = create_array_from(array2, 6);
  status = assert_values(filter_void(list, &is_even), expected_array1, 3);
  print_assert_status(status, "should filter the even numbers in the array");
}

void test_reduce_void()
{
  printf("reduce_void\n");

  int *empty_array;

  ArrayVoid_ptr list = create_array_from(empty_array, 0);
  int initial_value = 0;
  int expected_value = 0;
  Bool status = are_Objects_equal(reduce_void(list, &initial_value, &sum_of_numbers), &expected_value);
  print_assert_status(status, "should give initial value when array is empty");

  int array[6] = {1, 2, 3, 4, 5, 6};
  list = create_array_from(array, 6);
  initial_value = 0;
  expected_value = 21;
  reduce_void(list, &initial_value, &sum_of_numbers);
  status = are_Objects_equal(reduce_void(list, &initial_value, &sum_of_numbers), &expected_value);
  print_assert_status(status, "should give the sum of elements of the array");
}

int main(void)
{
  test_map_void();
  test_filter_void();
  test_reduce_void();
  return 0;
}