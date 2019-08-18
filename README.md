# colab-gsoc2019-Pankhuri_Vanjani

Instructions to replicate the error:

Requirements:

* ROS2 Dashing

Terminal 1: (Client side)

1. Get the code in a folder.

2. ```run colcon build```

3. Run: ```source /opt/ros/dashing/setup.bash```

4. cd build/camviz-ros2

5. ./camViz

Terminal 2: (Publisher)

1. ```ros2 topic pub /chatter std_msgs/String "data: Hello ROS Developers"```


P.S. There are two approaches in mainsubcpp.hpp file

Approach 1: It should be improved to get correct results. We should use our own spinner.

Approach 2: This was just a simple repetation of rclcpp::spin to check the results, this will give error anyway and won't provide anything to return.






