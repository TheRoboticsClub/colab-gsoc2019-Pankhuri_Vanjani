---
layout: post
title: Final Report 
date: 2019-08-23
---	

**About Project**


*Why ROS2?*



**Working Videos of the tools** 

(Click on image to watch video:)

1. Basic Image Tool 

A simple tool was developed which showed the use of ROS1+ROS2 interface efficiently. Images were subscribed to publsiher and displayed with  OpenCV GUI.

[![Image-tool-final](http://img.youtube.com/vi/E6v-G0QFUSg/0.jpg)](http://www.youtube.com/watch?v=E6v-G0QFUSg "Simplified image-tool-final")

2. CamViz Tool 

CamViz is a simple tool which takes image from Pubisher, sends it to GUI (it has it's own Gtk based GUI, unlike Image Tool) and displays the continous stream of images. It can be used to take images from USB-cam as well as camera attached on a Robot.

This is a cpp tool, concerned with the client side.

(Put video here)

3. ColorTuner Tool

Colortuner component implements three different image color filters in the next color spaces: RGB, HSV, YUV. It is an application to configure tailored color filters in HSV, RGB, or YUV color spaces. It is used to obtain optimal values of tint and saturation, as well as lighting, in that kind of filters. To perform the different color conversions between spaces we used the conventions appear in wikipedia, (HSV color conversions), and for YUV, (YUV color conversions) .

This tool only has one thread who cares about getting images and showing them throug the GUI. 

ColorTuner connects the new ROS1+ROS2 interface to a camera server (real or simulated) and takes images from it and each image is shown through an GUI class (called viewer').

It is a python based tool which uses Qt for GUI

 [![ColorTuner Tool- ROS1+ROS2 Interface](http://img.youtube.com/vi/-bwSsLItVi0/0.jpg)](http://www.youtube.com/watch?v=-bwSsLItVi0 "ColorTuner Tool- ROS1+ROS2 Interface")
 
 4. CarViz Tool
 
 CarViz is a teleoperation tool which can be used for Mobile robots like turtlebot, Dolly etc..
 
 It gives the functionality of teleoperation as well as viewing the raw data of sensors like laser and camera placed on Robot.
 
  [![carviz-turtlebot-ros-only](http://img.youtube.com/vi/Cto_d_tk12I/0.jpg)](http://www.youtube.com/watch?v=Cto_d_tk12I "carviz-turtlebot-ros-only")
 
 5. VisualStates Tool



**A summary of major work done with their links and PR's:**

| *Sub-project* |  *Status*     |  *Timeline* | *Links*  | *Additional Comments* |*Merged PR'S* |
| ------------- | ------------- | ----------- | ---------| --------------------- | -------------|     
| Debug Camviz      | Done | Week-1      |   [Link](https://github.com/JdeRobot/viz/pull/32)       |  PR merged for bug fixing        |   [PR#32](https://github.com/JdeRobot/viz/pull/32)       |                     |
| yaml support for ROS2 image drivers      | Done     |  Week-1       | [ros2-drivers](https://github.com/TheRoboticsClub/colab-gsoc2019-Pankhuri_Vanjani/tree/master/ros2-drivers)         | Fixed the error which was coming pre-gsoc period. These drivers were used in image tool later    |  N/A |            
| Migration to Dashing | Done      | Week-1          |    -      |   Installation and learning task                   | N/A|
| ROS1-ROS2 Interface | Done      |  Week-2         |  [cmakefile](https://github.com/TheRoboticsClub/colab-gsoc2019-Pankhuri_Vanjani/blob/master/dummyexample/CMakeLists.txt)        |    Getting right CMakelists.txt was the challenges of this task                 | N/A |
| Dummy library- 'Hello World!' | Done      |  Week-2         |    [dummy-library](https://github.com/TheRoboticsClub/colab-gsoc2019-Pankhuri_Vanjani/tree/master/dummyexample)      | Important to work on simplified problem before moving to complex so hello world! library helped in creating a basic tool whose complexity was increased later            | N/A|
| Image tool | Done      |   week-3  + week4      | [Youtube](https://www.youtube.com/watch?v=E6v-G0QFUSg&feature=youtu.be) , [scripts](https://github.com/TheRoboticsClub/colab-gsoc2019-Pankhuri_Vanjani/tree/master/image-tool-scripts) [codes](https://github.com/TheRoboticsClub/colab-gsoc2019-Pankhuri_Vanjani/tree/master/camera-interface) |  Finished succesfully   | N/A|                 |
| Docker | Done      |  week-3 + weeek4         | [docker](https://github.com/TheRoboticsClub/colab-gsoc2019-Pankhuri_Vanjani/tree/master/Dockerfiles)         |  Course done on docker. Since a workaround was found no need of docker right now. Facing error in starting video drivers from docker    |  N/A|
| Teleoperation tool | drivers completed in C++ and Python with interface   |  week5   + 6    |   [Teleoperation-drivers](https://github.com/TheRoboticsClub/colab-gsoc2019-Pankhuri_Vanjani/tree/master/Teleoperation_tool)     |  Searching for robot support was one big challenge in this week | N/A|
| Study CamViz tool | Done      |  week7       | N/A  | studied codebase of this tool and comm library which has ICE+ ROS drivers | N/A|
| CamViz-Rosify   | Done      |  Week8       | N/A  | Isolated CamViz tool from official repository and rosified tool | N/A|
| CamViz-ROS1+ROS2 support   | done      |  Week9 - Week12      | (put link to repo) | Challenge of using threading as a workaround as an alternative of ros::Asyncspinner in ROS1 | (put link of PR)|
| Refactor Carviz    | Done      |  week10      | (put link to repo) | Isolation and rosification of CarViz tool was done| N/A|
| Carviz-ROS1+ROS2 support   | Done      |  week10 -Week12     | (put link to repo) | Solving threading issue in camViz solved issues in thi repo too| (put PR link here)|
| ColorTuner tool   | Done      |  week10 -Week11   | (put link to repo) | First Python tool completed | (put PR link here)|
| ColorTuner tool   | Done      |  week10 -Week11   | (put link to repo) | First Python tool completed | [PR#6](https://github.com/JdeRobot/ColorTuner/pull/6)|
| VisualStates Tool   | in-progress   |  week12  | (put link to repo) | Error in generated ros2 node  | (in -progress)|





**Future Work**





**New skills developed during GSoC period**

This was a great learning period, I got the opportunity to grasp new skills and polish old ones. Some mentionable ones are: 

* Learnt Docker

* Learnt Working with GUI tools especially GTK and Qt

* Improved OOPS(Object oriented programming)

* Learnt basics of threading

* ROS1 and ROS2 concepts in depth 

* Improved CMake skills 

* Learnt how to study and work with large codebase

*Other than these tech-skills there were other lessons learnt from mistakes:*
 
* Patience 
 
* Don't ignore the approaches if not getting results. It might be just a syntax error. Dig out the correct one.

* Don't stick to the provided code architecture. If a problem is not getting solved feel free to create a new one.

**Major Challenges & GSoC journey**

* Frequently Switching between Versions while migrating tools from ROS1 -> ROS2

    * Ubuntu 16.04 -> Ubunutu 18.04
     
    * Python 2 -> Python3
    
* Lack of support of a Mobile Robot and several drivers during many weeks of GSoC period 

* Due to Electronics and Communication background I was unfamiliar with few fundamental CS concepts. Studying them side by side while implementing was a challenge but due to it I was able to push my boundaries.
    
**Acknowledgements**






