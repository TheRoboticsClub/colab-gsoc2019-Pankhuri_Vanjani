cmake_minimum_required(VERSION 2.8.3)
project(dummyexample)

find_package( PythonLibs 3 REQUIRED )
find_package(yaml-cpp REQUIRED)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra)
endif()

if(roscpp_FOUND)
    add_definitions(-DROS1_H)
    SET(ROS1_H ON)
    #//SET(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH} /home/pankhuri/YOUR_CATKIN_WORKSPACE/install")
if(rclcpp_FOUND)
    add_definitions(-DROS2_H)
    SET(ROS2_H ON)
    #//SET(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH} /home/pankhuri/ros2_ws/install")
ELSE()
    SET(ROS1_H OFF)
    SET(ROS2_H OFF)
endif()
endif()

IF (ROS1_H)
    message(STATUS "Using ROS1_H")
    set(ROS1_H ${CMAKE_CURRENT_SOURCE_DIR}/opt/ros/melodic/include)
    find_package(roscpp REQUIRED)
    find_package(std_msgs REQUIRED)
    target_include_directories(main PRIVATE ${"/opt/ros/melodic/include/"})
    #set(SOURCES file.cpp file2.cpp ${YOUR_DIRECTORY}/file1.h ${YOUR_DIRECTORY}/file2.h)
    add_executable(main main.cpp)
    target_link_libraries(main ${roscpp_LIBRARIES} ${std_msgs_LIBRARIES})

ENDIF()

IF (ROS2_H)
   message(STATUS "Using ROS2_H")
   set(ROS2_H ${CMAKE_CURRENT_SOURCE_DIR}/opt/ros/dashing/include)
   find_package(ament_cmake REQUIRED)
   find_package(rclcpp REQUIRED)
   find_package(sensor_msgs REQUIRED)
   target_include_directories(main PRIVATE ${"/opt/ros/dashing/include/"})
   #set(SOURCES file.cpp file2.cpp ${YOUR_DIRECTORY}/file1.h ${YOUR_DIRECTORY}/file2.h)
   add_executable(main main.cpp)
   target_link_libraries(main ${rclcpp_LIBRARIES} ${std_msgs_LIBRARIES})

ENDIF() 

   add_executable(main main.cpp)

    include_directories(include
    ${ament_cmake_INCLUDE_DIRS}
    ${roscpp_INCLUDE_DIRS}
    ${rclcpp_INCLUDE_DIRS}
    ${std_msgs_INCLUDE_DIRS}
    
    )

   target_link_libraries(main 
   ${yaml-cpp}
   ${roscpp_LIBRARIES}
   ${rclcpp_LIBRARIES}
   ${std_msgs_LIBRARIES})


install(TARGETS
  main
  DESTINATION lib/${PROJECT_NAME}
)
