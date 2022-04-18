// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from exomy_msgs:msg/MotorCommands.idl
// generated code does not contain a copyright notice

#ifndef EXOMY_MSGS__MSG__DETAIL__MOTOR_COMMANDS__BUILDER_HPP_
#define EXOMY_MSGS__MSG__DETAIL__MOTOR_COMMANDS__BUILDER_HPP_

#include "exomy_msgs/msg/detail/motor_commands__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace exomy_msgs
{

namespace msg
{

namespace builder
{

class Init_MotorCommands_steering_angles
{
public:
  explicit Init_MotorCommands_steering_angles(::exomy_msgs::msg::MotorCommands & msg)
  : msg_(msg)
  {}
  ::exomy_msgs::msg::MotorCommands steering_angles(::exomy_msgs::msg::MotorCommands::_steering_angles_type arg)
  {
    msg_.steering_angles = std::move(arg);
    return std::move(msg_);
  }

private:
  ::exomy_msgs::msg::MotorCommands msg_;
};

class Init_MotorCommands_motor_velocities
{
public:
  Init_MotorCommands_motor_velocities()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MotorCommands_steering_angles motor_velocities(::exomy_msgs::msg::MotorCommands::_motor_velocities_type arg)
  {
    msg_.motor_velocities = std::move(arg);
    return Init_MotorCommands_steering_angles(msg_);
  }

private:
  ::exomy_msgs::msg::MotorCommands msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::exomy_msgs::msg::MotorCommands>()
{
  return exomy_msgs::msg::builder::Init_MotorCommands_motor_velocities();
}

}  // namespace exomy_msgs

#endif  // EXOMY_MSGS__MSG__DETAIL__MOTOR_COMMANDS__BUILDER_HPP_
