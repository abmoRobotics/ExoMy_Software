// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from exomy_msgs:msg/MotorCommands.idl
// generated code does not contain a copyright notice

#ifndef EXOMY_MSGS__MSG__DETAIL__MOTOR_COMMANDS__STRUCT_HPP_
#define EXOMY_MSGS__MSG__DETAIL__MOTOR_COMMANDS__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__exomy_msgs__msg__MotorCommands __attribute__((deprecated))
#else
# define DEPRECATED__exomy_msgs__msg__MotorCommands __declspec(deprecated)
#endif

namespace exomy_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MotorCommands_
{
  using Type = MotorCommands_<ContainerAllocator>;

  explicit MotorCommands_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit MotorCommands_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _motor_velocities_type =
    std::vector<double, typename ContainerAllocator::template rebind<double>::other>;
  _motor_velocities_type motor_velocities;
  using _steering_angles_type =
    std::vector<double, typename ContainerAllocator::template rebind<double>::other>;
  _steering_angles_type steering_angles;

  // setters for named parameter idiom
  Type & set__motor_velocities(
    const std::vector<double, typename ContainerAllocator::template rebind<double>::other> & _arg)
  {
    this->motor_velocities = _arg;
    return *this;
  }
  Type & set__steering_angles(
    const std::vector<double, typename ContainerAllocator::template rebind<double>::other> & _arg)
  {
    this->steering_angles = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    exomy_msgs::msg::MotorCommands_<ContainerAllocator> *;
  using ConstRawPtr =
    const exomy_msgs::msg::MotorCommands_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<exomy_msgs::msg::MotorCommands_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<exomy_msgs::msg::MotorCommands_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      exomy_msgs::msg::MotorCommands_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<exomy_msgs::msg::MotorCommands_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      exomy_msgs::msg::MotorCommands_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<exomy_msgs::msg::MotorCommands_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<exomy_msgs::msg::MotorCommands_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<exomy_msgs::msg::MotorCommands_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__exomy_msgs__msg__MotorCommands
    std::shared_ptr<exomy_msgs::msg::MotorCommands_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__exomy_msgs__msg__MotorCommands
    std::shared_ptr<exomy_msgs::msg::MotorCommands_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MotorCommands_ & other) const
  {
    if (this->motor_velocities != other.motor_velocities) {
      return false;
    }
    if (this->steering_angles != other.steering_angles) {
      return false;
    }
    return true;
  }
  bool operator!=(const MotorCommands_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MotorCommands_

// alias to use template instance with default allocator
using MotorCommands =
  exomy_msgs::msg::MotorCommands_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace exomy_msgs

#endif  // EXOMY_MSGS__MSG__DETAIL__MOTOR_COMMANDS__STRUCT_HPP_
