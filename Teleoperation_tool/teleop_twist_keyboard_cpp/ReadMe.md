source /opt/ros/melodic/setup.bash

cd catkin_ws

catkin_make

cd src

"put the code here from git"

cd..

catkin_make

source devel/setup.bash

rosrun teleop_twist_keyboard_cpp teleop_twist_keyboard
