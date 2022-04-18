// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from exomy_msgs:msg/CameraData.idl
// generated code does not contain a copyright notice

#ifndef EXOMY_MSGS__MSG__DETAIL__CAMERA_DATA__FUNCTIONS_H_
#define EXOMY_MSGS__MSG__DETAIL__CAMERA_DATA__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "exomy_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "exomy_msgs/msg/detail/camera_data__struct.h"

/// Initialize msg/CameraData message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * exomy_msgs__msg__CameraData
 * )) before or use
 * exomy_msgs__msg__CameraData__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_exomy_msgs
bool
exomy_msgs__msg__CameraData__init(exomy_msgs__msg__CameraData * msg);

/// Finalize msg/CameraData message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_exomy_msgs
void
exomy_msgs__msg__CameraData__fini(exomy_msgs__msg__CameraData * msg);

/// Create msg/CameraData message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * exomy_msgs__msg__CameraData__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_exomy_msgs
exomy_msgs__msg__CameraData *
exomy_msgs__msg__CameraData__create();

/// Destroy msg/CameraData message.
/**
 * It calls
 * exomy_msgs__msg__CameraData__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_exomy_msgs
void
exomy_msgs__msg__CameraData__destroy(exomy_msgs__msg__CameraData * msg);


/// Initialize array of msg/CameraData messages.
/**
 * It allocates the memory for the number of elements and calls
 * exomy_msgs__msg__CameraData__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_exomy_msgs
bool
exomy_msgs__msg__CameraData__Sequence__init(exomy_msgs__msg__CameraData__Sequence * array, size_t size);

/// Finalize array of msg/CameraData messages.
/**
 * It calls
 * exomy_msgs__msg__CameraData__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_exomy_msgs
void
exomy_msgs__msg__CameraData__Sequence__fini(exomy_msgs__msg__CameraData__Sequence * array);

/// Create array of msg/CameraData messages.
/**
 * It allocates the memory for the array and calls
 * exomy_msgs__msg__CameraData__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_exomy_msgs
exomy_msgs__msg__CameraData__Sequence *
exomy_msgs__msg__CameraData__Sequence__create(size_t size);

/// Destroy array of msg/CameraData messages.
/**
 * It calls
 * exomy_msgs__msg__CameraData__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_exomy_msgs
void
exomy_msgs__msg__CameraData__Sequence__destroy(exomy_msgs__msg__CameraData__Sequence * array);

#ifdef __cplusplus
}
#endif

#endif  // EXOMY_MSGS__MSG__DETAIL__CAMERA_DATA__FUNCTIONS_H_
