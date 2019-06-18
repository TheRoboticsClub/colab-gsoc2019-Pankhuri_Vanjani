FROM ubuntu:bionic



#ROS1
RUN apt update
RUN apt-get install -y lsb-release
RUN apt-get update && apt-get install -y gnupg2
RUN sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'
RUN apt-key adv --keyserver 'hkp://keyserver.ubuntu.com:80' --recv-key C1CF6E31E6BADE8868B172B4F42ED6FBAB17C654
RUN apt update
RUN apt-get install -y tzdata
RUN apt install -y ros-melodic-desktop-full
RUN apt install -y python-rosinstall python-rosinstall-generator python-wstool build-essential
RUN rosdep init
RUN rosdep update

# setup entrypoint
COPY ./ros1_entrypoint.sh /

RUN chmod +x ros1_entrypoint.sh 
ENTRYPOINT ["/ros1_entrypoint.sh"]
CMD ["bash"]

#ROS2
RUN apt update
#RUN sudo locale-gen en_US en_US.UTF-8
#RUN update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8
#RUN export LANG=en_US.UTF-8
RUN apt update
RUN apt-get -y install lsb-release
RUN apt install -y curl gnupg2 lsb-release
RUN curl http://repo.ros2.org/repos.key | apt-key add -
RUN sh -c 'echo "deb [arch=amd64,arm64] http://packages.ros.org/ros2/ubuntu `lsb_release -cs` main" > /etc/apt/sources.list.d/ros2-latest.list'
RUN apt update
RUN apt-get install -y tzdata
RUN apt install -y ros-dashing-desktop
RUN apt install -y python3-argcomplete
RUN apt update

# setup entrypoint
COPY ./ros2_entrypoint.sh /

RUN chmod +x ros2_entrypoint.sh 

ENTRYPOINT ["/ros2_entrypoint.sh"]
CMD ["bash"]
