#include <iostream>
#include "sstream"
#include <chrono>
#include <memory>
#include "mainsub.hpp"


int main(int argc, char **argv)
{
	int server = *argv[1];

    	switch (server){
		case '1':
		{
			#ifdef ROS1S_H
			std::cout << "Receiving ROS1 messages" << std::endl;
			std::string topic = argv[2];
            ros::init(argc, argv, "image_listener");
            ros::NodeHandle nh;
            cv::namedWindow("view");
            //cv::startWindowThread();
            image_transport::ImageTransport it(nh);
            image_transport::Subscriber sub = it.subscribe(topic, 1, imageCallback);
            ros::spin();
            cv::destroyWindow("view");
				
			#else
				throw "ERROR: ROS1 is not available";
			#endif
		 	break;
		}
		case '2':
		{
			#ifdef ROS2S_H

				std::cout << "Receiving ROS2 messages" << std::endl;
				
                rclcpp::init(argc, argv);
                if (argc <= 2) {
                    throw "No topic specified";
                }

                std::string topic = argv[2];
                rclcpp::spin(std::make_shared<MinimalSubscriber>(topic));
                rclcpp::shutdown();
  
			#else
				throw "ERROR: ROS2 is not available";
			#endif
			break;
		}
		default:
		{
			printf("Select right distro of ROS");
            break;
		}
return 0;    
}



}
 