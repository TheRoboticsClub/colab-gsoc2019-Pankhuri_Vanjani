cmake_minimum_required(VERSION 3.5)
project(camviz)
set(CMAKE_BUILD_TYPE Debug)
# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()


if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic -Wunused-parameter)
endif()

        message("THIS IS ROS2")

        SET(ENV{PYTHONPATH} "/opt/ros/dashing/lib/python3.6/site-packages/")
        SET(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH} home/pankhuri/ros2_ws/install;/opt/ros/dashing")


        SET( SOURCE_FILES camViz.cpp )
        #add_definitions(-DGLADE_DIR="${gladedir}")

        find_package(ament_cmake REQUIRED)
        find_package(rclcpp REQUIRED)
        find_package(sensor_msgs REQUIRED)
        #find_package(OpenCV REQUIRED)
        find_package(yaml-cpp REQUIRED)
        find_package(image_transport REQUIRED)
        find_package(cv_bridge REQUIRED)
	find_package (Threads)
        find_package(Boost 1.65 REQUIRED COMPONENTS system)


        find_package(PkgConfig)
        pkg_check_modules(GTKMM gtkmm-3.0)


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
    

        include_directories(${GTKMM_INCLUDE_DIRS}
            ${Boost_INCLUDE_DIRS}
            ${ZLIB_INCLUDE_DIRS}
        )

        include_directories(
        
          ${rclcpp_INCLUDE_DIRS}
          ${rmw_connext_cpp_INCLUDE_DIRS}
          ${std_interfaces_INCLUDE_DIRS}
          ${cv_bridge_INCLUDE_DIRS}
          )

        link_directories(
            ${GTKMM_LIBRARY_DIRS}
        )

        add_executable (camViz ${SOURCE_FILES})

        TARGET_LINK_LIBRARIES(camViz
            ${GTKMM_LIBRARIES}
          # ${libglademm_LIBRARIES}
            ${ZLIB_LIBRARIES}
            ${CMAKE_THREAD_LIBS_INIT}
            ${resourcelocator_LIBRARIES}
            ${GLOG_LIBRARIES}
            ${cv_bridge_LIBRARIES}

            )
        target_link_libraries(camViz 
        ${OpenCV_LIBS}
        ${YAML_CPP_LIBRARIES}
	${CMAKE_THREAD_LIBS_INIT}
        ${Boost_LIBRARIES}
        )

        #target_link_libraries(main ${rclcppLIBRARIES} ${std_msgs_LIBRARIES} )
        #ament_target_dependencies(main rclcpp std_msgs )
        ament_target_dependencies(camViz "rclcpp" "std_msgs" "sensor_msgs" "OpenCV" "yaml-cpp" "cv_bridge")
        #ament_target_dependencies(camViz "rclcpp" "std_msgs" "sensor_msgs" "OpenCV")

        install(TARGETS camViz
            DESTINATION ${CMAKE_INSTALL_PREFIX}/bin/
            COMPONENT camviz
            )

#INSTALL (FILES ${CMAKE_CURRENT_SOURCE_DIR}/camViz.glade DESTINATION ${CMAKE_INSTALL_PREFIX}/share/jderobot/glade COMPONENT camviz)
#INSTALL (FILES ${CMAKE_CURRENT_SOURCE_DIR}/camViz.yml DESTINATION ${CMAKE_INSTALL_PREFIX}/share/jderobot/conf COMPONENT camviz)
