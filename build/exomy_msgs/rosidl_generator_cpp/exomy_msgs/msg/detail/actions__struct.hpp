// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from exomy_msgs:msg/Actions.idl
// generated code does not contain a copyright notice

#ifndef EXOMY_MSGS__MSG__DETAIL__ACTIONS__STRUCT_HPP_
#define EXOMY_MSGS__MSG__DETAIL__ACTIONS__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__exomy_msgs__msg__Actions __attribute__((deprecated))
#else
# define DEPRECATED__exomy_msgs__msg__Actions __declspec(deprecated)
#endif

namespace exomy_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Actions_
{
  using Type = Actions_<ContainerAllocator>;

  explicit Actions_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->lin_vel = 0.0;
      this->ang_vel = 0.0;
    }
  }

  explicit Actions_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->lin_vel = 0.0;
      this->ang_vel = 0.0;
    }
  }

  // field types and members
  using _lin_vel_type =
    double;
  _lin_vel_type lin_vel;
  using _ang_vel_type =
    double;
  _ang_vel_type ang_vel;

  // setters for named parameter idiom
  Type & set__lin_vel(
    const double & _arg)
  {
    this->lin_vel = _arg;
    return *this;
  }
  Type & set__ang_vel(
    const double & _arg)
  {
    this->ang_vel = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    exomy_msgs::msg::Actions_<ContainerAllocator> *;
  using ConstRawPtr =
    const exomy_msgs::msg::Actions_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<exomy_msgs::msg::Actions_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<exomy_msgs::msg::Actions_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      exomy_msgs::msg::Actions_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<exomy_msgs::msg::Actions_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      exomy_msgs::msg::Actions_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<exomy_msgs::msg::Actions_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<exomy_msgs::msg::Actions_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<exomy_msgs::msg::Actions_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__exomy_msgs__msg__Actions
    std::shared_ptr<exomy_msgs::msg::Actions_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__exomy_msgs__msg__Actions
    std::shared_ptr<exomy_msgs::msg::Actions_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Actions_ & other) const
  {
    if (this->lin_vel != other.lin_vel) {
      return false;
    }
    if (this->ang_vel != other.ang_vel) {
      return false;
    }
    return true;
  }
  bool operator!=(const Actions_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Actions_

// alias to use template instance with default allocator
using Actions =
  exomy_msgs::msg::Actions_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace exomy_msgs

#endif  // EXOMY_MSGS__MSG__DETAIL__ACTIONS__STRUCT_HPP_
