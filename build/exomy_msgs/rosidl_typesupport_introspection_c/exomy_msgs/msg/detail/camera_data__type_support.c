// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from exomy_msgs:msg/CameraData.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "exomy_msgs/msg/detail/camera_data__rosidl_typesupport_introspection_c.h"
#include "exomy_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "exomy_msgs/msg/detail/camera_data__functions.h"
#include "exomy_msgs/msg/detail/camera_data__struct.h"


// Include directives for member types
// Member `depth_data`
// Member `robot_pos`
// Member `robot_vel`
// Member `robot_acc`
// Member `robot_rot`
// Member `robot_ang_vel`
// Member `robot_ang_acc`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void CameraData__rosidl_typesupport_introspection_c__CameraData_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  exomy_msgs__msg__CameraData__init(message_memory);
}

void CameraData__rosidl_typesupport_introspection_c__CameraData_fini_function(void * message_memory)
{
  exomy_msgs__msg__CameraData__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember CameraData__rosidl_typesupport_introspection_c__CameraData_message_member_array[7] = {
  {
    "depth_data",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(exomy_msgs__msg__CameraData, depth_data),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "robot_pos",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(exomy_msgs__msg__CameraData, robot_pos),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "robot_vel",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(exomy_msgs__msg__CameraData, robot_vel),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "robot_acc",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(exomy_msgs__msg__CameraData, robot_acc),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "robot_rot",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(exomy_msgs__msg__CameraData, robot_rot),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "robot_ang_vel",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(exomy_msgs__msg__CameraData, robot_ang_vel),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "robot_ang_acc",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(exomy_msgs__msg__CameraData, robot_ang_acc),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers CameraData__rosidl_typesupport_introspection_c__CameraData_message_members = {
  "exomy_msgs__msg",  // message namespace
  "CameraData",  // message name
  7,  // number of fields
  sizeof(exomy_msgs__msg__CameraData),
  CameraData__rosidl_typesupport_introspection_c__CameraData_message_member_array,  // message members
  CameraData__rosidl_typesupport_introspection_c__CameraData_init_function,  // function to initialize message memory (memory has to be allocated)
  CameraData__rosidl_typesupport_introspection_c__CameraData_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t CameraData__rosidl_typesupport_introspection_c__CameraData_message_type_support_handle = {
  0,
  &CameraData__rosidl_typesupport_introspection_c__CameraData_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_exomy_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, exomy_msgs, msg, CameraData)() {
  if (!CameraData__rosidl_typesupport_introspection_c__CameraData_message_type_support_handle.typesupport_identifier) {
    CameraData__rosidl_typesupport_introspection_c__CameraData_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &CameraData__rosidl_typesupport_introspection_c__CameraData_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
