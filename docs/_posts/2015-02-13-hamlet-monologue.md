---
layout: post
title: Week-1
subtitle: Let's Viz....visualize!
date: 2019-05-27
---

**Progress of First week:**

First week of official coding period began with the interaction with mentors and setting goals for this week. This week focused on:
* Connect Camviz tool to ROS1 image driver
* Connect Camviz tool to ROS2 image driver

Currently JdeRobot has two tools camviz and camviz_py for this purpose. 
This week focused on understanding the code of camviz for modifying the tools to support ROS2.
A part of this work included fixing the issue discussed in [Issue#31](https://github.com/JdeRobot/viz/issues/31) and solved in [PR#32](https://github.com/JdeRobot/viz/pull/32).

Note. Camviz too: Error in compiling as viz tool doesn't have a compilation chain yet as discussed in  (Camviz-compile-Issue)[https://github.com/JdeRobot/viz/issues/33]. It has to be resolved later.

Second part of the work involved updating the current ros-2 image drivers in [Jderobot-ros2-drivers](https://github.com/JdeRobot/ros2-drivers) for reading the required information from a configuration file (yaml). I worked to solve the [Issue#01](https://github.com/JdeRobot/ros2-drivers/issues/1) with [#PR1](https://github.com/JdeRobot/ros2-drivers/pull/4). 
These drivers have a publisher and a subscriber. Video can be accessed by clicking on the image.

[![ROS2 image Driver](https://www.youtube.com/watch?v=QzxCfA791Ns&feature=youtu.be/0.jpg)](https://www.youtube.com/watch?v=QzxCfA791Ns&feature=youtu.be "ROS2 image Driver ")


Next part is to support these drivers to Camviz tools. But there are some challenges with this. Current JdeRobot is supported on Communication library which is built on ICE drivers. 
I read the codebase and implementation of communication library to understand it for better clarity.
With further discussion it was concluded:
* For supporting the camViz tools we need to alter the current communication library.
* ROS will definitely overshadow the current ICE based drivers.
* It would be better to write a new library from scratch for supporting both ROS1 and ROS2 and to get away with the ICE based tools, libraries and drivers.

More challenges...
* Release of ROS2-Dashing supported till May 2021. Current distro i.e. ROS2 Crystal will not be maintained after Dec 2019. Best platform to work on this project is ROS-Melodic and ROS2- Dashing. 

**Time to shift to Ubuntu 18.04 (Bionic)!!!!**

Install:

* ROS-Melodic
Follow this link [ROS-Melodic](http://wiki.ros.org/melodic/Installation/Ubuntu)
* ROS2- Dashing 
Follow this link [ROS2-Dashing](https://index.ros.org/doc/ros2/Installation/Dashing/Linux-Install-Debians/)
* JdeRobot branch (Currently in progress of Migration to Bionic)
 Branch: (JdeRobot-Ubuntu-Bionic)[https://github.com/JdeRobot/base/tree/ubuntu_bionic] 
 Current Status: Not build properly, still some errors from third-party-repository left to be resolved.
  
There are few changes in Dashing Diademata. Before working with this distro one should read the changes in documentation.

Ongoing work:
* Writing the interface for supporting ROS and ROS2 standlone. 
  * Fetch images with this interface 
* Use ListenerCamera of ROS with newer interface
* New ListenerCamera of ROS2 

Note: Codes of ingoing work have not been uploaded on github yet. Once completed and tested. they will be posted soon.



