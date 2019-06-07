cmake_minimum_required(VERSION 2.8.3)
project(dummyexample)

find_package( PythonLibs 3 REQUIRED )

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra)
endif()

if(roscpp_FOUND)
    SET(ROS1_H ON)
ELSE()
    SET(ROS1_H OFF)
endif()

if(rclcpp_FOUND)
    SET(ROS2_H ON)
ELSE()
    SET(ROS2_H OFF)
endif()

IF (ROS1_H)
    message(STATUS "Using ROS1_H")
    find_package(roscpp REQUIRED)
    find_package(std_msgs REQUIRED)
  
ENDIF()

IF (ROS2_H)
    message(STATUS "Using ROS2_H")
   find_package(ament_cmake REQUIRED)
   find_package(rclcpp REQUIRED)
   find_package(sensor_msgs REQUIRED)
  
ENDIF() 

IF(ROS1_H)
    set(SOURCES
        ${SOURCES}
        main.cpp
    )
ENDIF()

    include_directories(include
    ${ament_cmake_INCLUDE_DIRS}
    ${roscpp_INCLUDE_DIRS}
    ${rclcpp_INCLUDE_DIRS}
    ${std_msgs_INCLUDE_DIRS}
    
    )
    add_executable(main main.cpp)
    #ament_target_dependencies(main "rclcpp" "sensor_msgs")

    target_link_libraries(main ${roscpp_LIBRARIES} ${std_msgs_LIBRARIES})


install(TARGETS
  main
  DESTINATION lib/${PROJECT_NAME}
)