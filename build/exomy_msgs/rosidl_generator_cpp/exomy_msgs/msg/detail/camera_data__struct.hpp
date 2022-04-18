// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from exomy_msgs:msg/CameraData.idl
// generated code does not contain a copyright notice

#ifndef EXOMY_MSGS__MSG__DETAIL__CAMERA_DATA__STRUCT_HPP_
#define EXOMY_MSGS__MSG__DETAIL__CAMERA_DATA__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__exomy_msgs__msg__CameraData __attribute__((deprecated))
#else
# define DEPRECATED__exomy_msgs__msg__CameraData __declspec(deprecated)
#endif

namespace exomy_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CameraData_
{
  using Type = CameraData_<ContainerAllocator>;

  explicit CameraData_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit CameraData_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _depth_data_type =
    std::vector<double, typename ContainerAllocator::template rebind<double>::other>;
  _depth_data_type depth_data;
  using _robot_pos_type =
    std::vector<double, typename ContainerAllocator::template rebind<double>::other>;
  _robot_pos_type robot_pos;
  using _robot_vel_type =
    std::vector<double, typename ContainerAllocator::template rebind<double>::other>;
  _robot_vel_type robot_vel;
  using _robot_acc_type =
    std::vector<double, typename ContainerAllocator::template rebind<double>::other>;
  _robot_acc_type robot_acc;
  using _robot_rot_type =
    std::vector<double, typename ContainerAllocator::template rebind<double>::other>;
  _robot_rot_type robot_rot;
  using _robot_ang_vel_type =
    std::vector<double, typename ContainerAllocator::template rebind<double>::other>;
  _robot_ang_vel_type robot_ang_vel;
  using _robot_ang_acc_type =
    std::vector<double, typename ContainerAllocator::template rebind<double>::other>;
  _robot_ang_acc_type robot_ang_acc;

  // setters for named parameter idiom
  Type & set__depth_data(
    const std::vector<double, typename ContainerAllocator::template rebind<double>::other> & _arg)
  {
    this->depth_data = _arg;
    return *this;
  }
  Type & set__robot_pos(
    const std::vector<double, typename ContainerAllocator::template rebind<double>::other> & _arg)
  {
    this->robot_pos = _arg;
    return *this;
  }
  Type & set__robot_vel(
    const std::vector<double, typename ContainerAllocator::template rebind<double>::other> & _arg)
  {
    this->robot_vel = _arg;
    return *this;
  }
  Type & set__robot_acc(
    const std::vector<double, typename ContainerAllocator::template rebind<double>::other> & _arg)
  {
    this->robot_acc = _arg;
    return *this;
  }
  Type & set__robot_rot(
    const std::vector<double, typename ContainerAllocator::template rebind<double>::other> & _arg)
  {
    this->robot_rot = _arg;
    return *this;
  }
  Type & set__robot_ang_vel(
    const std::vector<double, typename ContainerAllocator::template rebind<double>::other> & _arg)
  {
    this->robot_ang_vel = _arg;
    return *this;
  }
  Type & set__robot_ang_acc(
    const std::vector<double, typename ContainerAllocator::template rebind<double>::other> & _arg)
  {
    this->robot_ang_acc = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    exomy_msgs::msg::CameraData_<ContainerAllocator> *;
  using ConstRawPtr =
    const exomy_msgs::msg::CameraData_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<exomy_msgs::msg::CameraData_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<exomy_msgs::msg::CameraData_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      exomy_msgs::msg::CameraData_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<exomy_msgs::msg::CameraData_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      exomy_msgs::msg::CameraData_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<exomy_msgs::msg::CameraData_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<exomy_msgs::msg::CameraData_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<exomy_msgs::msg::CameraData_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__exomy_msgs__msg__CameraData
    std::shared_ptr<exomy_msgs::msg::CameraData_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__exomy_msgs__msg__CameraData
    std::shared_ptr<exomy_msgs::msg::CameraData_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CameraData_ & other) const
  {
    if (this->depth_data != other.depth_data) {
      return false;
    }
    if (this->robot_pos != other.robot_pos) {
      return false;
    }
    if (this->robot_vel != other.robot_vel) {
      return false;
    }
    if (this->robot_acc != other.robot_acc) {
      return false;
    }
    if (this->robot_rot != other.robot_rot) {
      return false;
    }
    if (this->robot_ang_vel != other.robot_ang_vel) {
      return false;
    }
    if (this->robot_ang_acc != other.robot_ang_acc) {
      return false;
    }
    return true;
  }
  bool operator!=(const CameraData_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CameraData_

// alias to use template instance with default allocator
using CameraData =
  exomy_msgs::msg::CameraData_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace exomy_msgs

#endif  // EXOMY_MSGS__MSG__DETAIL__CAMERA_DATA__STRUCT_HPP_
