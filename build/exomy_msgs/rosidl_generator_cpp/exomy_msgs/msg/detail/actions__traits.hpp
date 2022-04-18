// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from exomy_msgs:msg/Actions.idl
// generated code does not contain a copyright notice

#ifndef EXOMY_MSGS__MSG__DETAIL__ACTIONS__TRAITS_HPP_
#define EXOMY_MSGS__MSG__DETAIL__ACTIONS__TRAITS_HPP_

#include "exomy_msgs/msg/detail/actions__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<exomy_msgs::msg::Actions>()
{
  return "exomy_msgs::msg::Actions";
}

template<>
inline const char * name<exomy_msgs::msg::Actions>()
{
  return "exomy_msgs/msg/Actions";
}

template<>
struct has_fixed_size<exomy_msgs::msg::Actions>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<exomy_msgs::msg::Actions>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<exomy_msgs::msg::Actions>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // EXOMY_MSGS__MSG__DETAIL__ACTIONS__TRAITS_HPP_
