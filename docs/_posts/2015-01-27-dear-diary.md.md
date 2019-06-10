---
layout: post
title: Week-2 progress
subtitle: ROS1 Or ROS2 Or both?
date: 2019-06-10
---
**DUMMY Libraries**
Second week commenced with discussion over creating an interface for tools to support both ROS1 and ROS2. There were many challenges which were discussed with mentors over the meeting. For achieving this task I was suggested to use conditional compilation and building for both distros in a single code. To start with it, this week I was supposed to create a dummy library.

First it is important to understand what is it and how it works?
 
We wish to develop the tool which can work when both distros are present, one of them is present or even none is present. Dependencies of ROS should not result in errors. After reading the required config from a configuration file the interface decides internally to shake hands with selected distro (i.e. set up the environment to include necessary header files and compile that ROS code).

 
![link-tool](../img/ROS1-ROS2.png)



(Text on ROS1 Or ROS2 Or both? with image)

Discuss conditional compilation

*Goals planned for this week*
--dummmy libraries

1. Dummy example without involving ROS1 and ROS2

Pre-processor directives in cpp
#ifdef, #ifndef #if how do they work

--Challenges here especially with CMakeLists and how they were solved


2. Dummy example with ROS1 and ROS2

--Biggest challenge:
    
    Getting right path to get rid of sourcing environment.
    
    --solved for ROS1
    
    Problems in ROS2
    --AMENT PACKAGE- a python package so needs right pythonpath
    
    --solved for ROS2
    
  Cases tested for ROS1 and ROS2 path individually
  
  Next challenge : How to set path for both ROS1 and ROS2 during environment and select during runtime?
  
  one solution: --cmake-args ' -DVARIABLE=1 '
                  then if(variable-ROS1=on)
                          set ROS1 path
                       elif (variable -ROS2= on /ROS1=on)
                           set ROS2 path
  
              Solev: how to get variable
      
  Final: Test Hello World publisher!
