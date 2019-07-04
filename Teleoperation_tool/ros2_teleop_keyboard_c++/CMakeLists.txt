cmake_minimum_required(VERSION 3.5)

project(teleop)

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
find_package(geometry_msgs REQUIRED)

add_executable(teleo teleo.cpp)
#ament_target_dependencies(teleo "rclcpp" "sensor_msgs" "OpenCV" "geometry_msgs" "yaml-cpp")
ament_target_dependencies(teleo rclcpp std_msgs geometry_msgs)
target_link_libraries(teleo ${YAML_CPP_LIBRARIES})



install(TARGETS
  teleo
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
