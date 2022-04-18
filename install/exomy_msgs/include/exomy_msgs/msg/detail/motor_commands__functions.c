// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from exomy_msgs:msg/MotorCommands.idl
// generated code does not contain a copyright notice
#include "exomy_msgs/msg/detail/motor_commands__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `motor_velocities`
// Member `steering_angles`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
exomy_msgs__msg__MotorCommands__init(exomy_msgs__msg__MotorCommands * msg)
{
  if (!msg) {
    return false;
  }
  // motor_velocities
  if (!rosidl_runtime_c__double__Sequence__init(&msg->motor_velocities, 0)) {
    exomy_msgs__msg__MotorCommands__fini(msg);
    return false;
  }
  // steering_angles
  if (!rosidl_runtime_c__double__Sequence__init(&msg->steering_angles, 0)) {
    exomy_msgs__msg__MotorCommands__fini(msg);
    return false;
  }
  return true;
}

void
exomy_msgs__msg__MotorCommands__fini(exomy_msgs__msg__MotorCommands * msg)
{
  if (!msg) {
    return;
  }
  // motor_velocities
  rosidl_runtime_c__double__Sequence__fini(&msg->motor_velocities);
  // steering_angles
  rosidl_runtime_c__double__Sequence__fini(&msg->steering_angles);
}

exomy_msgs__msg__MotorCommands *
exomy_msgs__msg__MotorCommands__create()
{
  exomy_msgs__msg__MotorCommands * msg = (exomy_msgs__msg__MotorCommands *)malloc(sizeof(exomy_msgs__msg__MotorCommands));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(exomy_msgs__msg__MotorCommands));
  bool success = exomy_msgs__msg__MotorCommands__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
exomy_msgs__msg__MotorCommands__destroy(exomy_msgs__msg__MotorCommands * msg)
{
  if (msg) {
    exomy_msgs__msg__MotorCommands__fini(msg);
  }
  free(msg);
}


bool
exomy_msgs__msg__MotorCommands__Sequence__init(exomy_msgs__msg__MotorCommands__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  exomy_msgs__msg__MotorCommands * data = NULL;
  if (size) {
    data = (exomy_msgs__msg__MotorCommands *)calloc(size, sizeof(exomy_msgs__msg__MotorCommands));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = exomy_msgs__msg__MotorCommands__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        exomy_msgs__msg__MotorCommands__fini(&data[i - 1]);
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
exomy_msgs__msg__MotorCommands__Sequence__fini(exomy_msgs__msg__MotorCommands__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      exomy_msgs__msg__MotorCommands__fini(&array->data[i]);
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

exomy_msgs__msg__MotorCommands__Sequence *
exomy_msgs__msg__MotorCommands__Sequence__create(size_t size)
{
  exomy_msgs__msg__MotorCommands__Sequence * array = (exomy_msgs__msg__MotorCommands__Sequence *)malloc(sizeof(exomy_msgs__msg__MotorCommands__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = exomy_msgs__msg__MotorCommands__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
exomy_msgs__msg__MotorCommands__Sequence__destroy(exomy_msgs__msg__MotorCommands__Sequence * array)
{
  if (array) {
    exomy_msgs__msg__MotorCommands__Sequence__fini(array);
  }
  free(array);
}
