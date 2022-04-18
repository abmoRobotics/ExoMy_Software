// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from exomy_msgs:msg/Actions.idl
// generated code does not contain a copyright notice

#ifndef EXOMY_MSGS__MSG__DETAIL__ACTIONS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define EXOMY_MSGS__MSG__DETAIL__ACTIONS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "exomy_msgs/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "exomy_msgs/msg/detail/actions__struct.hpp"

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

#include "fastcdr/Cdr.h"

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
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_exomy_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  exomy_msgs::msg::Actions & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_exomy_msgs
get_serialized_size(
  const exomy_msgs::msg::Actions & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_exomy_msgs
max_serialized_size_Actions(
  bool & full_bounded,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace exomy_msgs

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_exomy_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, exomy_msgs, msg, Actions)();

#ifdef __cplusplus
}
#endif

#endif  // EXOMY_MSGS__MSG__DETAIL__ACTIONS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
