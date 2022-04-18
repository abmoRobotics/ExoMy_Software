// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from exomy_msgs:msg/CameraData.idl
// generated code does not contain a copyright notice

#ifndef EXOMY_MSGS__MSG__DETAIL__CAMERA_DATA__BUILDER_HPP_
#define EXOMY_MSGS__MSG__DETAIL__CAMERA_DATA__BUILDER_HPP_

#include "exomy_msgs/msg/detail/camera_data__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace exomy_msgs
{

namespace msg
{

namespace builder
{

class Init_CameraData_robot_ang_acc
{
public:
  explicit Init_CameraData_robot_ang_acc(::exomy_msgs::msg::CameraData & msg)
  : msg_(msg)
  {}
  ::exomy_msgs::msg::CameraData robot_ang_acc(::exomy_msgs::msg::CameraData::_robot_ang_acc_type arg)
  {
    msg_.robot_ang_acc = std::move(arg);
    return std::move(msg_);
  }

private:
  ::exomy_msgs::msg::CameraData msg_;
};

class Init_CameraData_robot_ang_vel
{
public:
  explicit Init_CameraData_robot_ang_vel(::exomy_msgs::msg::CameraData & msg)
  : msg_(msg)
  {}
  Init_CameraData_robot_ang_acc robot_ang_vel(::exomy_msgs::msg::CameraData::_robot_ang_vel_type arg)
  {
    msg_.robot_ang_vel = std::move(arg);
    return Init_CameraData_robot_ang_acc(msg_);
  }

private:
  ::exomy_msgs::msg::CameraData msg_;
};

class Init_CameraData_robot_rot
{
public:
  explicit Init_CameraData_robot_rot(::exomy_msgs::msg::CameraData & msg)
  : msg_(msg)
  {}
  Init_CameraData_robot_ang_vel robot_rot(::exomy_msgs::msg::CameraData::_robot_rot_type arg)
  {
    msg_.robot_rot = std::move(arg);
    return Init_CameraData_robot_ang_vel(msg_);
  }

private:
  ::exomy_msgs::msg::CameraData msg_;
};

class Init_CameraData_robot_acc
{
public:
  explicit Init_CameraData_robot_acc(::exomy_msgs::msg::CameraData & msg)
  : msg_(msg)
  {}
  Init_CameraData_robot_rot robot_acc(::exomy_msgs::msg::CameraData::_robot_acc_type arg)
  {
    msg_.robot_acc = std::move(arg);
    return Init_CameraData_robot_rot(msg_);
  }

private:
  ::exomy_msgs::msg::CameraData msg_;
};

class Init_CameraData_robot_vel
{
public:
  explicit Init_CameraData_robot_vel(::exomy_msgs::msg::CameraData & msg)
  : msg_(msg)
  {}
  Init_CameraData_robot_acc robot_vel(::exomy_msgs::msg::CameraData::_robot_vel_type arg)
  {
    msg_.robot_vel = std::move(arg);
    return Init_CameraData_robot_acc(msg_);
  }

private:
  ::exomy_msgs::msg::CameraData msg_;
};

class Init_CameraData_robot_pos
{
public:
  explicit Init_CameraData_robot_pos(::exomy_msgs::msg::CameraData & msg)
  : msg_(msg)
  {}
  Init_CameraData_robot_vel robot_pos(::exomy_msgs::msg::CameraData::_robot_pos_type arg)
  {
    msg_.robot_pos = std::move(arg);
    return Init_CameraData_robot_vel(msg_);
  }

private:
  ::exomy_msgs::msg::CameraData msg_;
};

class Init_CameraData_depth_data
{
public:
  Init_CameraData_depth_data()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CameraData_robot_pos depth_data(::exomy_msgs::msg::CameraData::_depth_data_type arg)
  {
    msg_.depth_data = std::move(arg);
    return Init_CameraData_robot_pos(msg_);
  }

private:
  ::exomy_msgs::msg::CameraData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::exomy_msgs::msg::CameraData>()
{
  return exomy_msgs::msg::builder::Init_CameraData_depth_data();
}

}  // namespace exomy_msgs

#endif  // EXOMY_MSGS__MSG__DETAIL__CAMERA_DATA__BUILDER_HPP_
