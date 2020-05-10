#include "assert_array_void.h"
#include <stdio.h>

Bool are_Objects_equal(Object value1, Object value2)
{
  return *(int *)value1 == *(int *)value1;
}

Bool assert_values(ArrayVoid_ptr list, int *array, int array_length)
{
  Bool status = True;
  status = status && (list->length == array_length);
  if (status)
  {
    for (int i = 0; i < array_length; i++)
    {
      status = status && are_Objects_equal(list->array[i], &array[i]);
    }
  }
  return status;
}

void print_assert_status(Bool status, char *message)
{
  char *status_message = status ? "Success" : "Failure";
  printf("\t%s! %s\n", status_message, message);
}