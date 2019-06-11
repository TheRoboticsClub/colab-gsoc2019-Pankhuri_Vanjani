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

*Getting right path to get rid of sourcing environment.*

Discussion in issues:

1. Source the ROS and ROS2 environment for different cases from the cpp file (Intended interface) [Issue#01](https://github.com/TheRoboticsClub/colab-gsoc2019-Pankhuri_Vanjani/issues/1)

2. Conditional compilation failing [Issue#02](https://github.com/TheRoboticsClub/colab-gsoc2019-Pankhuri_Vanjani/issues/2)

Now, moving to the solution:

* For ROS1

     ---Solved for ROS1 by Adding these lines in CMakeLists.txt 
              
    ```                        
    SET(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH} /home/pankhuri/ros2_ws/install";/opt/ros/melodic)
    ```
    Challenge: Since our files are in ```/opt/ros/melodic``` path or in```/install``` for workspace I was using these two paths individually. But using them together with help of dilimiter ';' solved the issue. 
    
    Helpful links: [answers.ros #01](Sourcing Error solved using http://answers.ros.org/question/251262/qt-creator-42-cmake/)
    
* For ROS2   
    
    --AMENT PACKAGE- 'ament_package is a Python module. Python uses the PYTHONPATH variable. It doesn't retrieve the CMAKE_PREFIX_PATH, so setting it will not extend the Python search path'. First we need to set the right path.
   
    
    ---Solved for ROS2 by adding these lines in CMakeLists.txt 
    
    ```
    SET(ENV{PYTHONPATH} "/opt/ros/dashing/lib/python3.6/site-packages/")
    SET(CMAKE_PREFIX_PATH "${CMAKE_REFIX_PATH} home/pankhuri/ros2_ws/install;/opt/ros/dashing")
    
    ```
    Challenge: I tried it in a way simialar to ROS1 but there was an error of 'No module named ament package'. Resolving it consumed a lot of time.
    
     Helpful links studied for this:
     
     [answers.ros.org](http://answers.ros.org/question/325087/modulenotfounderror-no-module-named-ament_package/)
     
     [ament/ament_tools](https://github.com/ament/ament_tools/issues/76)
     
     [How to properly set AMENT_PREFIX_PATH?](http://answers.ros.org/question/318205/how-to-properly-set-ament_prefix_path/)
    
     [ImportError: 'from ament_package](https://github.com/ament/ament_package/issues/5)
    
    
  **Testing the tool**
  
  Initially cases were tasted for ROS1 and ROS2 path individually with different CMake file and after successful runs they were integrated into one using --cmake-args and if()..else()..endif() conditions in CMakeLists.txt
  
  **Hello World Publisher!**
  
  This tool works for all 4 cases:
  
  * Both ROS1 and ROS2 installed
  
  * Only ROS1 present
  
  * Only ROS2 present
  
  * Neither ROS1 nor ROS2 present
 
 [![ROS1-ROS2 Interface](http://img.https://youtu.be/ziAgkfG3tBc/0.jpg)](https://www.youtube.com/watch?v=ziAgkfG3tBc&feature=youtu.be "ROS1-ROS2 Interface")	
 

*******************************************************************************************************
**Steps to run this example:**

1. Download the dummyexample

2. Build the code:

  ```  colcon build --symlink-install \--cmake-args \ -Drosversion:string=0  ```
  
 Note: 
 
 ```-Drosversion:string=1 ```//For ROS1
 
 ```-Drosversion:string=0 ```//For ROS2
 
3. To run it:
    
    Go to build directory where the main file is located (/build/dummyexample/)
    
    ```./main 1``` //For ROS1
    
    ```./main 2``` //For ROS2

*********************************************************************************************************
       
       



  
  

  

