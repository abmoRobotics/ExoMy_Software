// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from exomy_msgs:msg/MotorCommands.idl
// generated code does not contain a copyright notice

#ifndef EXOMY_MSGS__MSG__DETAIL__MOTOR_COMMANDS__STRUCT_H_
#define EXOMY_MSGS__MSG__DETAIL__MOTOR_COMMANDS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'motor_velocities'
// Member 'steering_angles'
#include "rosidl_runtime_c/primitives_sequence.h"

// Struct defined in msg/MotorCommands in the package exomy_msgs.
typedef struct exomy_msgs__msg__MotorCommands
{
  rosidl_runtime_c__double__Sequence motor_velocities;
  rosidl_runtime_c__double__Sequence steering_angles;
} exomy_msgs__msg__MotorCommands;

// Struct for a sequence of exomy_msgs__msg__MotorCommands.
typedef struct exomy_msgs__msg__MotorCommands__Sequence
{
  exomy_msgs__msg__MotorCommands * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} exomy_msgs__msg__MotorCommands__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // EXOMY_MSGS__MSG__DETAIL__MOTOR_COMMANDS__STRUCT_H_
