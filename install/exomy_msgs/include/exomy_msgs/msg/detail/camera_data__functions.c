// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from exomy_msgs:msg/CameraData.idl
// generated code does not contain a copyright notice
#include "exomy_msgs/msg/detail/camera_data__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `depth_data`
// Member `robot_pos`
// Member `robot_vel`
// Member `robot_acc`
// Member `robot_rot`
// Member `robot_ang_vel`
// Member `robot_ang_acc`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
exomy_msgs__msg__CameraData__init(exomy_msgs__msg__CameraData * msg)
{
  if (!msg) {
    return false;
  }
  // depth_data
  if (!rosidl_runtime_c__double__Sequence__init(&msg->depth_data, 0)) {
    exomy_msgs__msg__CameraData__fini(msg);
    return false;
  }
  // robot_pos
  if (!rosidl_runtime_c__double__Sequence__init(&msg->robot_pos, 0)) {
    exomy_msgs__msg__CameraData__fini(msg);
    return false;
  }
  // robot_vel
  if (!rosidl_runtime_c__double__Sequence__init(&msg->robot_vel, 0)) {
    exomy_msgs__msg__CameraData__fini(msg);
    return false;
  }
  // robot_acc
  if (!rosidl_runtime_c__double__Sequence__init(&msg->robot_acc, 0)) {
    exomy_msgs__msg__CameraData__fini(msg);
    return false;
  }
  // robot_rot
  if (!rosidl_runtime_c__double__Sequence__init(&msg->robot_rot, 0)) {
    exomy_msgs__msg__CameraData__fini(msg);
    return false;
  }
  // robot_ang_vel
  if (!rosidl_runtime_c__double__Sequence__init(&msg->robot_ang_vel, 0)) {
    exomy_msgs__msg__CameraData__fini(msg);
    return false;
  }
  // robot_ang_acc
  if (!rosidl_runtime_c__double__Sequence__init(&msg->robot_ang_acc, 0)) {
    exomy_msgs__msg__CameraData__fini(msg);
    return false;
  }
  return true;
}

void
exomy_msgs__msg__CameraData__fini(exomy_msgs__msg__CameraData * msg)
{
  if (!msg) {
    return;
  }
  // depth_data
  rosidl_runtime_c__double__Sequence__fini(&msg->depth_data);
  // robot_pos
  rosidl_runtime_c__double__Sequence__fini(&msg->robot_pos);
  // robot_vel
  rosidl_runtime_c__double__Sequence__fini(&msg->robot_vel);
  // robot_acc
  rosidl_runtime_c__double__Sequence__fini(&msg->robot_acc);
  // robot_rot
  rosidl_runtime_c__double__Sequence__fini(&msg->robot_rot);
  // robot_ang_vel
  rosidl_runtime_c__double__Sequence__fini(&msg->robot_ang_vel);
  // robot_ang_acc
  rosidl_runtime_c__double__Sequence__fini(&msg->robot_ang_acc);
}

exomy_msgs__msg__CameraData *
exomy_msgs__msg__CameraData__create()
{
  exomy_msgs__msg__CameraData * msg = (exomy_msgs__msg__CameraData *)malloc(sizeof(exomy_msgs__msg__CameraData));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(exomy_msgs__msg__CameraData));
  bool success = exomy_msgs__msg__CameraData__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
exomy_msgs__msg__CameraData__destroy(exomy_msgs__msg__CameraData * msg)
{
  if (msg) {
    exomy_msgs__msg__CameraData__fini(msg);
  }
  free(msg);
}


bool
exomy_msgs__msg__CameraData__Sequence__init(exomy_msgs__msg__CameraData__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  exomy_msgs__msg__CameraData * data = NULL;
  if (size) {
    data = (exomy_msgs__msg__CameraData *)calloc(size, sizeof(exomy_msgs__msg__CameraData));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = exomy_msgs__msg__CameraData__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        exomy_msgs__msg__CameraData__fini(&data[i - 1]);
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
exomy_msgs__msg__CameraData__Sequence__fini(exomy_msgs__msg__CameraData__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      exomy_msgs__msg__CameraData__fini(&array->data[i]);
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

exomy_msgs__msg__CameraData__Sequence *
exomy_msgs__msg__CameraData__Sequence__create(size_t size)
{
  exomy_msgs__msg__CameraData__Sequence * array = (exomy_msgs__msg__CameraData__Sequence *)malloc(sizeof(exomy_msgs__msg__CameraData__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = exomy_msgs__msg__CameraData__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
exomy_msgs__msg__CameraData__Sequence__destroy(exomy_msgs__msg__CameraData__Sequence * array)
{
  if (array) {
    exomy_msgs__msg__CameraData__Sequence__fini(array);
  }
  free(array);
}
