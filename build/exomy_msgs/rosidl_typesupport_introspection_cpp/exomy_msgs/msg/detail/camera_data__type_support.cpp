// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from exomy_msgs:msg/CameraData.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "exomy_msgs/msg/detail/camera_data__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace exomy_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void CameraData_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) exomy_msgs::msg::CameraData(_init);
}

void CameraData_fini_function(void * message_memory)
{
  auto typed_message = static_cast<exomy_msgs::msg::CameraData *>(message_memory);
  typed_message->~CameraData();
}

size_t size_function__CameraData__depth_data(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__CameraData__depth_data(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__CameraData__depth_data(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void resize_function__CameraData__depth_data(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

size_t size_function__CameraData__robot_pos(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__CameraData__robot_pos(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__CameraData__robot_pos(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void resize_function__CameraData__robot_pos(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

size_t size_function__CameraData__robot_vel(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__CameraData__robot_vel(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__CameraData__robot_vel(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void resize_function__CameraData__robot_vel(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

size_t size_function__CameraData__robot_acc(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__CameraData__robot_acc(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__CameraData__robot_acc(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void resize_function__CameraData__robot_acc(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

size_t size_function__CameraData__robot_rot(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__CameraData__robot_rot(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__CameraData__robot_rot(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void resize_function__CameraData__robot_rot(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

size_t size_function__CameraData__robot_ang_vel(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__CameraData__robot_ang_vel(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__CameraData__robot_ang_vel(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void resize_function__CameraData__robot_ang_vel(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

size_t size_function__CameraData__robot_ang_acc(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__CameraData__robot_ang_acc(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__CameraData__robot_ang_acc(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void resize_function__CameraData__robot_ang_acc(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember CameraData_message_member_array[7] = {
  {
    "depth_data",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(exomy_msgs::msg::CameraData, depth_data),  // bytes offset in struct
    nullptr,  // default value
    size_function__CameraData__depth_data,  // size() function pointer
    get_const_function__CameraData__depth_data,  // get_const(index) function pointer
    get_function__CameraData__depth_data,  // get(index) function pointer
    resize_function__CameraData__depth_data  // resize(index) function pointer
  },
  {
    "robot_pos",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(exomy_msgs::msg::CameraData, robot_pos),  // bytes offset in struct
    nullptr,  // default value
    size_function__CameraData__robot_pos,  // size() function pointer
    get_const_function__CameraData__robot_pos,  // get_const(index) function pointer
    get_function__CameraData__robot_pos,  // get(index) function pointer
    resize_function__CameraData__robot_pos  // resize(index) function pointer
  },
  {
    "robot_vel",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(exomy_msgs::msg::CameraData, robot_vel),  // bytes offset in struct
    nullptr,  // default value
    size_function__CameraData__robot_vel,  // size() function pointer
    get_const_function__CameraData__robot_vel,  // get_const(index) function pointer
    get_function__CameraData__robot_vel,  // get(index) function pointer
    resize_function__CameraData__robot_vel  // resize(index) function pointer
  },
  {
    "robot_acc",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(exomy_msgs::msg::CameraData, robot_acc),  // bytes offset in struct
    nullptr,  // default value
    size_function__CameraData__robot_acc,  // size() function pointer
    get_const_function__CameraData__robot_acc,  // get_const(index) function pointer
    get_function__CameraData__robot_acc,  // get(index) function pointer
    resize_function__CameraData__robot_acc  // resize(index) function pointer
  },
  {
    "robot_rot",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(exomy_msgs::msg::CameraData, robot_rot),  // bytes offset in struct
    nullptr,  // default value
    size_function__CameraData__robot_rot,  // size() function pointer
    get_const_function__CameraData__robot_rot,  // get_const(index) function pointer
    get_function__CameraData__robot_rot,  // get(index) function pointer
    resize_function__CameraData__robot_rot  // resize(index) function pointer
  },
  {
    "robot_ang_vel",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(exomy_msgs::msg::CameraData, robot_ang_vel),  // bytes offset in struct
    nullptr,  // default value
    size_function__CameraData__robot_ang_vel,  // size() function pointer
    get_const_function__CameraData__robot_ang_vel,  // get_const(index) function pointer
    get_function__CameraData__robot_ang_vel,  // get(index) function pointer
    resize_function__CameraData__robot_ang_vel  // resize(index) function pointer
  },
  {
    "robot_ang_acc",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(exomy_msgs::msg::CameraData, robot_ang_acc),  // bytes offset in struct
    nullptr,  // default value
    size_function__CameraData__robot_ang_acc,  // size() function pointer
    get_const_function__CameraData__robot_ang_acc,  // get_const(index) function pointer
    get_function__CameraData__robot_ang_acc,  // get(index) function pointer
    resize_function__CameraData__robot_ang_acc  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers CameraData_message_members = {
  "exomy_msgs::msg",  // message namespace
  "CameraData",  // message name
  7,  // number of fields
  sizeof(exomy_msgs::msg::CameraData),
  CameraData_message_member_array,  // message members
  CameraData_init_function,  // function to initialize message memory (memory has to be allocated)
  CameraData_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t CameraData_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &CameraData_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace exomy_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<exomy_msgs::msg::CameraData>()
{
  return &::exomy_msgs::msg::rosidl_typesupport_introspection_cpp::CameraData_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, exomy_msgs, msg, CameraData)() {
  return &::exomy_msgs::msg::rosidl_typesupport_introspection_cpp::CameraData_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
