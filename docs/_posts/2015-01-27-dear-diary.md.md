---
layout: post
title: Week-2 progress
subtitle: ROS1 Or ROS2 Or both?
date: 2019-06-10
---
**DUMMY Libraries**
(Rough sketch --to be completed)

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
