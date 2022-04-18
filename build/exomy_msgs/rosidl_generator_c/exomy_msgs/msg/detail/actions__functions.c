// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from exomy_msgs:msg/Actions.idl
// generated code does not contain a copyright notice
#include "exomy_msgs/msg/detail/actions__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool
exomy_msgs__msg__Actions__init(exomy_msgs__msg__Actions * msg)
{
  if (!msg) {
    return false;
  }
  // lin_vel
  // ang_vel
  return true;
}

void
exomy_msgs__msg__Actions__fini(exomy_msgs__msg__Actions * msg)
{
  if (!msg) {
    return;
  }
  // lin_vel
  // ang_vel
}

exomy_msgs__msg__Actions *
exomy_msgs__msg__Actions__create()
{
  exomy_msgs__msg__Actions * msg = (exomy_msgs__msg__Actions *)malloc(sizeof(exomy_msgs__msg__Actions));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(exomy_msgs__msg__Actions));
  bool success = exomy_msgs__msg__Actions__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
exomy_msgs__msg__Actions__destroy(exomy_msgs__msg__Actions * msg)
{
  if (msg) {
    exomy_msgs__msg__Actions__fini(msg);
  }
  free(msg);
}


bool
exomy_msgs__msg__Actions__Sequence__init(exomy_msgs__msg__Actions__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  exomy_msgs__msg__Actions * data = NULL;
  if (size) {
    data = (exomy_msgs__msg__Actions *)calloc(size, sizeof(exomy_msgs__msg__Actions));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = exomy_msgs__msg__Actions__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        exomy_msgs__msg__Actions__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
exomy_msgs__msg__Actions__Sequence__fini(exomy_msgs__msg__Actions__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      exomy_msgs__msg__Actions__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

exomy_msgs__msg__Actions__Sequence *
exomy_msgs__msg__Actions__Sequence__create(size_t size)
{
  exomy_msgs__msg__Actions__Sequence * array = (exomy_msgs__msg__Actions__Sequence *)malloc(sizeof(exomy_msgs__msg__Actions__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = exomy_msgs__msg__Actions__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
exomy_msgs__msg__Actions__Sequence__destroy(exomy_msgs__msg__Actions__Sequence * array)
{
  if (array) {
    exomy_msgs__msg__Actions__Sequence__fini(array);
  }
  free(array);
}
