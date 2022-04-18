// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from exomy_msgs:msg/CameraData.idl
// generated code does not contain a copyright notice

#ifndef EXOMY_MSGS__MSG__DETAIL__CAMERA_DATA__STRUCT_H_
#define EXOMY_MSGS__MSG__DETAIL__CAMERA_DATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'depth_data'
// Member 'robot_pos'
// Member 'robot_vel'
// Member 'robot_acc'
// Member 'robot_rot'
// Member 'robot_ang_vel'
// Member 'robot_ang_acc'
#include "rosidl_runtime_c/primitives_sequence.h"

// Struct defined in msg/CameraData in the package exomy_msgs.
typedef struct exomy_msgs__msg__CameraData
{
  rosidl_runtime_c__double__Sequence depth_data;
  rosidl_runtime_c__double__Sequence robot_pos;
  rosidl_runtime_c__double__Sequence robot_vel;
  rosidl_runtime_c__double__Sequence robot_acc;
  rosidl_runtime_c__double__Sequence robot_rot;
  rosidl_runtime_c__double__Sequence robot_ang_vel;
  rosidl_runtime_c__double__Sequence robot_ang_acc;
} exomy_msgs__msg__CameraData;

// Struct for a sequence of exomy_msgs__msg__CameraData.
typedef struct exomy_msgs__msg__CameraData__Sequence
{
  exomy_msgs__msg__CameraData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} exomy_msgs__msg__CameraData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // EXOMY_MSGS__MSG__DETAIL__CAMERA_DATA__STRUCT_H_
