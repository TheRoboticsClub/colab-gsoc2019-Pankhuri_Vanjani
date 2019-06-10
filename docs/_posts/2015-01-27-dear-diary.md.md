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

**Conditional Compilation with pre-processor directives**

First part involved learning about pre-processor directives in C++ and define them in CMakeLists.txt

Our concern is with conditional compilation directives which are
* idfef ( if defined )
* ifndef (if not defined)
For better clarity these are the links studied for understanding [link1](https://www.geeksforgeeks.org/cc-preprocessors/), [link2](https://docs.microsoft.com/en-us/cpp/preprocessor/hash-ifdef-and-hash-ifndef-directives-c-cpp?view=vs-2019)

**Dummy example with ROS1 and ROS2**

Challenge of enabling path 

*Getting right path to get rid of sourcing environment.*

Discussion in issues:
[Issue#01](https://github.com/TheRoboticsClub/colab-gsoc2019-Pankhuri_Vanjani/issues/1)

[Issue#02](https://github.com/TheRoboticsClub/colab-gsoc2019-Pankhuri_Vanjani/issues/2)

* For ROS1
            
              
    '''                        
    --solved for ROS1
    '''
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
