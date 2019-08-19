#include <iostream>
#include "sstream"
#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"  	    
#include "sensor_msgs/msg/image.hpp"    
#include "subros2.hpp"

#include "mainpubros12.hpp"

using rclcpp::executors::MultiThreadedExecutor;

namespace camViz{

	CameraClient* 
	getClient(int argc, char** argv, int server, std::string topic,std::string  nodeName){
		CameraClient* client = NULL;		
			std::cout << "Receiving ROS2 messages" << std::endl;
			rclcpp::init(argc, argv);
			
			//Approach 1
			MinimalSubscriber* lc2;
			lc2 = new MinimalSubscriber(0, nullptr, nodeName,topic);
			return (camViz::CameraClient*) lc2;

		}
	

}


