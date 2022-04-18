// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from exomy_msgs:msg/MotorCommands.idl
// generated code does not contain a copyright notice
#include "exomy_msgs/msg/detail/motor_commands__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "exomy_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "exomy_msgs/msg/detail/motor_commands__struct.h"
#include "exomy_msgs/msg/detail/motor_commands__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/primitives_sequence.h"  // motor_velocities, steering_angles
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // motor_velocities, steering_angles

// forward declare type support functions


using _MotorCommands__ros_msg_type = exomy_msgs__msg__MotorCommands;

static bool _MotorCommands__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _MotorCommands__ros_msg_type * ros_message = static_cast<const _MotorCommands__ros_msg_type *>(untyped_ros_message);
  // Field name: motor_velocities
  {
    size_t size = ros_message->motor_velocities.size;
    auto array_ptr = ros_message->motor_velocities.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: steering_angles
  {
    size_t size = ros_message->steering_angles.size;
    auto array_ptr = ros_message->steering_angles.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _MotorCommands__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _MotorCommands__ros_msg_type * ros_message = static_cast<_MotorCommands__ros_msg_type *>(untyped_ros_message);
  // Field name: motor_velocities
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->motor_velocities.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->motor_velocities);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->motor_velocities, size)) {
      return "failed to create array for field 'motor_velocities'";
    }
    auto array_ptr = ros_message->motor_velocities.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: steering_angles
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->steering_angles.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->steering_angles);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->steering_angles, size)) {
      return "failed to create array for field 'steering_angles'";
    }
    auto array_ptr = ros_message->steering_angles.data;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_exomy_msgs
size_t get_serialized_size_exomy_msgs__msg__MotorCommands(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _MotorCommands__ros_msg_type * ros_message = static_cast<const _MotorCommands__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name motor_velocities
  {
    size_t array_size = ros_message->motor_velocities.size;
    auto array_ptr = ros_message->motor_velocities.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name steering_angles
  {
    size_t array_size = ros_message->steering_angles.size;
    auto array_ptr = ros_message->steering_angles.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _MotorCommands__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_exomy_msgs__msg__MotorCommands(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_exomy_msgs
size_t max_serialized_size_exomy_msgs__msg__MotorCommands(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: motor_velocities
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: steering_angles
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _MotorCommands__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_exomy_msgs__msg__MotorCommands(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_MotorCommands = {
  "exomy_msgs::msg",
  "MotorCommands",
  _MotorCommands__cdr_serialize,
  _MotorCommands__cdr_deserialize,
  _MotorCommands__get_serialized_size,
  _MotorCommands__max_serialized_size
};

static rosidl_message_type_support_t _MotorCommands__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_MotorCommands,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, exomy_msgs, msg, MotorCommands)() {
  return &_MotorCommands__type_support;
}

#if defined(__cplusplus)
}
#endif
