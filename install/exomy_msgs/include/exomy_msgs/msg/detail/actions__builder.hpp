// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from exomy_msgs:msg/Actions.idl
// generated code does not contain a copyright notice

#ifndef EXOMY_MSGS__MSG__DETAIL__ACTIONS__BUILDER_HPP_
#define EXOMY_MSGS__MSG__DETAIL__ACTIONS__BUILDER_HPP_

#include "exomy_msgs/msg/detail/actions__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace exomy_msgs
{

namespace msg
{

namespace builder
{

class Init_Actions_ang_vel
{
public:
  explicit Init_Actions_ang_vel(::exomy_msgs::msg::Actions & msg)
  : msg_(msg)
  {}
  ::exomy_msgs::msg::Actions ang_vel(::exomy_msgs::msg::Actions::_ang_vel_type arg)
  {
    msg_.ang_vel = std::move(arg);
    return std::move(msg_);
  }

private:
  ::exomy_msgs::msg::Actions msg_;
};

class Init_Actions_lin_vel
{
public:
  Init_Actions_lin_vel()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Actions_ang_vel lin_vel(::exomy_msgs::msg::Actions::_lin_vel_type arg)
  {
    msg_.lin_vel = std::move(arg);
    return Init_Actions_ang_vel(msg_);
  }

private:
  ::exomy_msgs::msg::Actions msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::exomy_msgs::msg::Actions>()
{
  return exomy_msgs::msg::builder::Init_Actions_lin_vel();
}

}  // namespace exomy_msgs

#endif  // EXOMY_MSGS__MSG__DETAIL__ACTIONS__BUILDER_HPP_
