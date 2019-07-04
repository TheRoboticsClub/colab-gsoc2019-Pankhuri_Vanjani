Terminal 1:

cd ros2_ws

colcon build --symlink-install

cd build/teleop

./teleo /cmd_vel:=/dolly/cmd_vel
