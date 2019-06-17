cmake_minimum_required(VERSION 3.5)
project(dummyexample)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic -Wunused-parameter)
endif()

SET(rosversion "1" CACHE STRING "Some user-specified option")

if(rosversion) 
    message("THIS IS ROS1")

    SET(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH} /home/pankhuri/catkin_ws/install;/opt/ros/melodic")

    find_package(roscpp REQUIRED)
    find_package(std_msgs REQUIRED)
    find_package(image_transport REQUIRED)
    find_package(sensor_msgs REQUIRED)
    find_package(OpenCV REQUIRED)
    find_package(cv_bridge REQUIRED)

    if(roscpp_FOUND) 
      message("ROS1 found")
      add_definitions(-DROS1_H) 
      add_definitions(-DROS1S_H)
      SET(ROS1_H ON) 
      SET(ROS1S_H ON)
    ELSE()
      message("ROS1 not found")
      SET(ROS1_H OFF) 
      SET(ROS1S_H OFF)
    endif()

    include_directories(${roscpp_INCLUDE_DIRS} ${image_transport_INCLUDE_DIRS} ${sensor_msgs_INCLUDE_DIRS} )
    include_directories(${std_msgs_INCLUDE_DIRS}${OpenCV_INCLUDE_DIRS}${cv_bridge_INCLUDE_DIRS})

    add_executable(mainpub mainpub.cpp)
    add_executable(mainsub mainsub.cpp)

    target_link_libraries(mainpub ${roscpp_LIBRARIES} ${std_msgs_LIBRARIES} ${image_transport_LIBRARIES}  ${OpenCV_LIBRARIES} ${cv_bridge_LIBRARIES} ${sensor_msgs_LIBRARIES})
    target_link_libraries(mainsub ${roscpp_LIBRARIES} ${std_msgs_LIBRARIES} ${image_transport_LIBRARIES}  ${OpenCV_LIBRARIES} ${cv_bridge_LIBRARIES} ${sensor_msgs_LIBRARIES})
 
    install(TARGETS mainpub
            DESTINATION bin)
    install(TARGETS mainsub 
            DESTINATION bin)
else()
    message("THIS IS ROS2")

    SET(ENV{PYTHONPATH} "/opt/ros/dashing/lib/python3.6/site-packages/")
    SET(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH} home/pankhuri/ros2_ws/install;/opt/ros/dashing")

    find_package(ament_cmake REQUIRED)
    find_package(rclcpp REQUIRED)
    find_package(sensor_msgs REQUIRED)
    find_package(OpenCV REQUIRED)
    find_package(yaml-cpp REQUIRED)

    if(rclcpp_FOUND) 
      message("ROS2 found")
      add_definitions(-DROS2_H) 
      add_definitions(-DROS2S_H) 

      SET(ROS2_H ON) 
      SET(ROS2S_H ON) 
    ELSE()
      message("ROS2 not found")
      SET(ROS2_H OFF) 
      SET(ROS2S_H OFF)
    endif()
 
    include_directories(
    include
      ${rclcpp_INCLUDE_DIRS}
      ${rmw_connext_cpp_INCLUDE_DIRS}
      ${std_interfaces_INCLUDE_DIRS}
      )

    add_executable(mainpub mainpub.cpp)
    add_executable(mainsub mainsub.cpp)
    #target_link_libraries(main ${rclcppLIBRARIES} ${std_msgs_LIBRARIES} )
    #ament_target_dependencies(main rclcpp std_msgs )
    ament_target_dependencies(mainpub "rclcpp" "std_msgs" "sensor_msgs" "OpenCV" "yaml-cpp")
    ament_target_dependencies(mainsub "rclcpp" "std_msgs" "sensor_msgs" "OpenCV")

    install(TARGETS
        mainpub
        mainsub 
        DESTINATION bin)

endif()











