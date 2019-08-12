#include <iostream>
#include "sstream"
#include <chrono>
#include <memory>

#include "mainsub.hpp"
#include "mainpubros12.hpp"


namespace camViz{

	CameraClient* 
	getCameraClient(int argc, char** argv, int server, std::string topic,std::string  nodeName){
		CameraClient* client = 0;
		
		switch (server){
			case 1:
			{
				#ifdef ROS1S_H
				std::cout << "Receiving ROS1 messages" << std::endl;
				//std::string topic = argv[2];
				//ros::init(argc, argv, "image_listener");
				//ros::NodeHandle nh;
				////cv::namedWindow("view");
				////cv::startWindowThread();
				ListenerCamera* lc;
				lc = new ListenerCamera(0, nullptr, nodeName, topic);
				lc->start();
						std::cout << "lc-startyo";

				client = (camViz::CameraClient*) lc;
						std::cout << "clientform";


				//cv::destroyWindow("view");
					
				#else
					throw "ERROR: ROS1 is not available";
				#endif
				break;
			}
			case 2:
			{
				#ifdef ROS2S_H
				using rclcpp::executors::MultiThreadedExecutor;


				std::cout << "Receiving ROS2 messages" << std::endl;
					
				/*ListenerCameraros2* lc2;
				std::cout << "hi2\n";

				//rclcpp::init(argc,argv);
				std::cout << "hi2\n";

				lc2 = new ListenerCameraros2(0, nullptr, nodeName, topic);

				lc2->start();

				std::cout << "hi\n";

				//rclcpp::spin(std::make_shared<ListenerCameraros2>(0,nullptr,nodeName,topic));
			    //rclcpp::spin(std::make_shared<ListenerCameraros2>(0,nullptr,nodeName,topic));


				client = (camViz::CameraClient*) lc2;

				rclcpp::shutdown();*/
				MinimalSubscriber* lc2;
				rclcpp::init(argc, argv);
				lc2 = new  MinimalSubscriber(0, nullptr, nodeName,topic);	
				lc2->start();

				std::cout << "lc-start";
                //rclcpp::spin(std::make_shared<MinimalSubscriber>(0, nullptr, nodeName, topic));

				std::cout << "comeout";

				client = (camViz::CameraClient*) lc2;
				std::cout << "received client";
				
				if(client==NULL)
				{
					std::cout << "clientnulls";

					client->getImage();
					
				}
				else
				{
					std::cout << "clientnotnull";

					lc2->getImage();
				}
	
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

		}
	
		return client;


	}

}
