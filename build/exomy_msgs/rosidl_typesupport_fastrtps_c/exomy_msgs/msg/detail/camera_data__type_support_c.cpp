// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from exomy_msgs:msg/CameraData.idl
// generated code does not contain a copyright notice
#include "exomy_msgs/msg/detail/camera_data__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "exomy_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "exomy_msgs/msg/detail/camera_data__struct.h"
#include "exomy_msgs/msg/detail/camera_data__functions.h"
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

#include "rosidl_runtime_c/primitives_sequence.h"  // depth_data, robot_acc, robot_ang_acc, robot_ang_vel, robot_pos, robot_rot, robot_vel
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // depth_data, robot_acc, robot_ang_acc, robot_ang_vel, robot_pos, robot_rot, robot_vel

// forward declare type support functions


using _CameraData__ros_msg_type = exomy_msgs__msg__CameraData;

static bool _CameraData__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _CameraData__ros_msg_type * ros_message = static_cast<const _CameraData__ros_msg_type *>(untyped_ros_message);
  // Field name: depth_data
  {
    size_t size = ros_message->depth_data.size;
    auto array_ptr = ros_message->depth_data.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: robot_pos
  {
    size_t size = ros_message->robot_pos.size;
    auto array_ptr = ros_message->robot_pos.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: robot_vel
  {
    size_t size = ros_message->robot_vel.size;
    auto array_ptr = ros_message->robot_vel.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: robot_acc
  {
    size_t size = ros_message->robot_acc.size;
    auto array_ptr = ros_message->robot_acc.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: robot_rot
  {
    size_t size = ros_message->robot_rot.size;
    auto array_ptr = ros_message->robot_rot.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: robot_ang_vel
  {
    size_t size = ros_message->robot_ang_vel.size;
    auto array_ptr = ros_message->robot_ang_vel.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: robot_ang_acc
  {
    size_t size = ros_message->robot_ang_acc.size;
    auto array_ptr = ros_message->robot_ang_acc.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _CameraData__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _CameraData__ros_msg_type * ros_message = static_cast<_CameraData__ros_msg_type *>(untyped_ros_message);
  // Field name: depth_data
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->depth_data.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->depth_data);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->depth_data, size)) {
      return "failed to create array for field 'depth_data'";
    }
    auto array_ptr = ros_message->depth_data.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: robot_pos
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->robot_pos.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->robot_pos);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->robot_pos, size)) {
      return "failed to create array for field 'robot_pos'";
    }
    auto array_ptr = ros_message->robot_pos.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: robot_vel
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->robot_vel.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->robot_vel);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->robot_vel, size)) {
      return "failed to create array for field 'robot_vel'";
    }
    auto array_ptr = ros_message->robot_vel.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: robot_acc
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->robot_acc.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->robot_acc);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->robot_acc, size)) {
      return "failed to create array for field 'robot_acc'";
    }
    auto array_ptr = ros_message->robot_acc.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: robot_rot
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->robot_rot.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->robot_rot);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->robot_rot, size)) {
      return "failed to create array for field 'robot_rot'";
    }
    auto array_ptr = ros_message->robot_rot.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: robot_ang_vel
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->robot_ang_vel.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->robot_ang_vel);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->robot_ang_vel, size)) {
      return "failed to create array for field 'robot_ang_vel'";
    }
    auto array_ptr = ros_message->robot_ang_vel.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: robot_ang_acc
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->robot_ang_acc.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->robot_ang_acc);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->robot_ang_acc, size)) {
      return "failed to create array for field 'robot_ang_acc'";
    }
    auto array_ptr = ros_message->robot_ang_acc.data;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_exomy_msgs
size_t get_serialized_size_exomy_msgs__msg__CameraData(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _CameraData__ros_msg_type * ros_message = static_cast<const _CameraData__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name depth_data
  {
    size_t array_size = ros_message->depth_data.size;
    auto array_ptr = ros_message->depth_data.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name robot_pos
  {
    size_t array_size = ros_message->robot_pos.size;
    auto array_ptr = ros_message->robot_pos.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name robot_vel
  {
    size_t array_size = ros_message->robot_vel.size;
    auto array_ptr = ros_message->robot_vel.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name robot_acc
  {
    size_t array_size = ros_message->robot_acc.size;
    auto array_ptr = ros_message->robot_acc.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name robot_rot
  {
    size_t array_size = ros_message->robot_rot.size;
    auto array_ptr = ros_message->robot_rot.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name robot_ang_vel
  {
    size_t array_size = ros_message->robot_ang_vel.size;
    auto array_ptr = ros_message->robot_ang_vel.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name robot_ang_acc
  {
    size_t array_size = ros_message->robot_ang_acc.size;
    auto array_ptr = ros_message->robot_ang_acc.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _CameraData__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_exomy_msgs__msg__CameraData(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_exomy_msgs
size_t max_serialized_size_exomy_msgs__msg__CameraData(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: depth_data
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: robot_pos
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: robot_vel
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: robot_acc
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: robot_rot
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: robot_ang_vel
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: robot_ang_acc
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

static size_t _CameraData__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_exomy_msgs__msg__CameraData(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_CameraData = {
  "exomy_msgs::msg",
  "CameraData",
  _CameraData__cdr_serialize,
  _CameraData__cdr_deserialize,
  _CameraData__get_serialized_size,
  _CameraData__max_serialized_size
};

static rosidl_message_type_support_t _CameraData__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_CameraData,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, exomy_msgs, msg, CameraData)() {
  return &_CameraData__type_support;
}

#if defined(__cplusplus)
}
#endif
