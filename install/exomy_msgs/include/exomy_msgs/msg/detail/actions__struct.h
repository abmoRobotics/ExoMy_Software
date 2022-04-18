// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from exomy_msgs:msg/Actions.idl
// generated code does not contain a copyright notice

#ifndef EXOMY_MSGS__MSG__DETAIL__ACTIONS__STRUCT_H_
#define EXOMY_MSGS__MSG__DETAIL__ACTIONS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/Actions in the package exomy_msgs.
typedef struct exomy_msgs__msg__Actions
{
  double lin_vel;
  double ang_vel;
} exomy_msgs__msg__Actions;

// Struct for a sequence of exomy_msgs__msg__Actions.
typedef struct exomy_msgs__msg__Actions__Sequence
{
  exomy_msgs__msg__Actions * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} exomy_msgs__msg__Actions__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // EXOMY_MSGS__MSG__DETAIL__ACTIONS__STRUCT_H_
