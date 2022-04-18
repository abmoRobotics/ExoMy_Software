// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from exomy_msgs:msg/Actions.idl
// generated code does not contain a copyright notice
#include "exomy_msgs/msg/detail/actions__rosidl_typesupport_fastrtps_cpp.hpp"
#include "exomy_msgs/msg/detail/actions__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace exomy_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_exomy_msgs
cdr_serialize(
  const exomy_msgs::msg::Actions & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: lin_vel
  cdr << ros_message.lin_vel;
  // Member: ang_vel
  cdr << ros_message.ang_vel;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_exomy_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  exomy_msgs::msg::Actions & ros_message)
{
  // Member: lin_vel
  cdr >> ros_message.lin_vel;

  // Member: ang_vel
  cdr >> ros_message.ang_vel;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_exomy_msgs
get_serialized_size(
  const exomy_msgs::msg::Actions & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: lin_vel
  {
    size_t item_size = sizeof(ros_message.lin_vel);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: ang_vel
  {
    size_t item_size = sizeof(ros_message.ang_vel);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_exomy_msgs
max_serialized_size_Actions(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: lin_vel
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: ang_vel
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static bool _Actions__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const exomy_msgs::msg::Actions *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Actions__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<exomy_msgs::msg::Actions *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Actions__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const exomy_msgs::msg::Actions *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Actions__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_Actions(full_bounded, 0);
}

static message_type_support_callbacks_t _Actions__callbacks = {
  "exomy_msgs::msg",
  "Actions",
  _Actions__cdr_serialize,
  _Actions__cdr_deserialize,
  _Actions__get_serialized_size,
  _Actions__max_serialized_size
};

static rosidl_message_type_support_t _Actions__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Actions__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace exomy_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_exomy_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<exomy_msgs::msg::Actions>()
{
  return &exomy_msgs::msg::typesupport_fastrtps_cpp::_Actions__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, exomy_msgs, msg, Actions)() {
  return &exomy_msgs::msg::typesupport_fastrtps_cpp::_Actions__handle;
}

#ifdef __cplusplus
}
#endif
