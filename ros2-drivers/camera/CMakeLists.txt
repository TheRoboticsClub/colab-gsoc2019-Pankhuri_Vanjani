cmake_minimum_required(VERSION 3.5)

project(camera)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()


if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic -Wunused-parameter)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(OpenCV REQUIRED)
find_package(yaml-cpp REQUIRED)

add_executable(publisher publisher/publisher.cpp)
ament_target_dependencies(publisher "rclcpp" "sensor_msgs" "OpenCV" "yaml-cpp")

target_link_libraries(publisher ${YAML_CPP_LIBRARIES})

add_executable(subscriber subscriber/subscriber.cpp)
ament_target_dependencies(subscriber "rclcpp" "sensor_msgs" "OpenCV")

install(TARGETS
  publisher
  subscriber
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
