import sys
import os, pickle
import pprint
from pipes import quote
import subprocess

print("Enter 1 for ROS1 and 2 for ROS2")

ros_distro = int(input("Enter ROS distro "))

##For ROS1
if(ros_distro==1):

    #Clean previous build . Change 'week3' to your folder name
    subprocess.call(["rm -rf build "],shell=True,cwd='week3') 
    subprocess.call(["rm -rf install"],shell=True,cwd='week3') 
    subprocess.call(["rm -rf log"],shell=True,cwd='week3') 

    #Compilation
    subprocess.call(["colcon build --symlink-install \--cmake-args \ -Drosversion:string=1"],shell=True,cwd='week3')  

    #Set ROS1 environment variables
    os.environ["LD_LIBRARY_PATH"] = "/opt/ros/melodic/lib"
    os.environ["ROS_ETC_DIR"] = "/opt/ros/melodic/etc/ros"
    os.environ["CMAKE_PREFIX_PATH"] = "/opt/ros/melodic"
    os.environ["ROS_ROOT"] = "/opt/ros/melodic/share/ros"
    os.environ["ROS_MASTER_URI"] = "http://localhost:11311"
    os.environ["ROS_VERSION"] = "1"
    os.environ["ROS_PYTHON_VERSION"] = "2"
    os.environ["PYTHONPATH"] = "/opt/ros/melodic/lib/python2.7/dist-packages"
    os.environ["ROS_PACKAGE_PATH"] = "/opt/ros/melodic/share"
    os.environ["LD_LIBRARY_PATH"] = "/opt/ros/melodic/lib"
    os.environ["PKG_CONFIG_PATH"] = "/opt/ros/melodic/lib/pkgconfig"
    os.environ["ROS_DISTRO"] = "melodic"

    #For debugging
    pprint.pprint(dict(os.environ))

    #Run the script
    subprocess.call("(./week3/build/camera-interface/mainpub 1 2)",shell=True) 

#For ROS2
else:
    
    #Clean previous build. Change 'week3' to your folder name
    subprocess.call(["rm -rf build "],shell=True,cwd='week3') 
    subprocess.call(["rm -rf install"],shell=True,cwd='week3') 
    subprocess.call(["rm -rf log"],shell=True,cwd='week3') 

    #Compilation
    subprocess.call(["colcon build --symlink-install \--cmake-args \ -Drosversion:string=0"],shell=True,cwd='week3')  

    #Set ROS2 environment variables
    os.environ["LD_LIBRARY_PATH"] = "/opt/ros/dashing/opt/yaml_cpp_vendor/lib:/opt/ros/dashing/opt/rviz_ogre_vendor/lib:/usr/lib:/opt/rti.com/rti_connext_dds-5.3.1/lib/x64Linux3gcc5.4.0:/opt/ros/dashing/lib"
    os.environ["AMENT_PREFIX_PATH"] = "/opt/ros/dashing"
    os.environ["OSPL_VERBOSITY"] = "2"
    os.environ["NDDSHOME"] = "/opt/rti.com/rti_connext_dds-5.3.1"
    os.environ["OSPL_URI"] = "///opt/ros/dashing/share/opensplice_cmake_module/config/ros_ospl.xml"
    os.environ["OSPL_HOME"] = "/usr"
    os.environ["OSPL_INFOFILE"] = "<stdout>"
    os.environ["ROS_VERSION"] = "2"
    os.environ["ROS_PYTHON_VERSION"] = "3"
    os.environ["OSPL_ERRORFILE"] = "<stderr>"
    os.environ["PYTHONPATH"] = "PYTHONPATH=/opt/ros/dashing/lib/python3.6/site-packages"
    os.environ["PATH"] = "/opt/rti.com/rti_connext_dds-5.3.1/lib/x64Linux3gcc5.4.0:/opt/rti.com/rti_connext_dds-5.3.1/bin:/opt/ros/dashing/bin:/home/pankhuri/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin"
    os.environ["ROS_DISTRO"] = "dashing"
    os.environ["OSPL_TMPL_PATH"] = "/usr/etc/opensplice/idlpp"

    #For debugging
    pprint.pprint(dict(os.environ))

    #Run the script
    subprocess.call("(./week3/build/camera-interface/mainpub 2)",shell=True) 




