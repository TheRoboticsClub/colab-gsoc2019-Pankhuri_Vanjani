#include <iostream>
#include <yaml-cpp/yaml.h>
#include "main.hpp"
#include <chrono>

using namespace std::chrono_literals;

int main(int argc, char **argv)
{
	int server = *argv[1];
    //std::string config_file_;
    //config_file_.assign(argv[1]);
	//YAML::Node config = YAML::LoadFile(config_file_);
    //int server = config["Server"].as<int>();
    	switch (server){
		case '1':
		{
			#ifdef ROS1_H
				std::cout << "Receiving ROS messages" << std::endl;
				ros::init(argc, argv, "talker");
				ros::NodeHandle n;
				ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
				ros::Rate loop_rate(10);
					int count = 0;
				while (ros::ok())
				{
						std_msgs::String msg;

					std::stringstream ss;
					ss << "hello world " << count;
					msg.data = ss.str();
					ROS_INFO("%s", msg.data.c_str());
						chatter_pub.publish(msg);
					ros::spinOnce();
					loop_rate.sleep();
					++count;
				}
			#else
				throw "ERROR: ROS is not available";
			#endif
		 	break;
		}
		case '2':
		{
			#ifdef ROS2_H
				std::cout << "Receiving ROS2 messages" << std::endl;
				rclcpp::init(argc, argv);
				auto node = rclcpp::Node::make_shared("minimal_publisher");
				auto publisher = node->create_publisher<std_msgs::msg::String>("topic", 10);
				std_msgs::msg::String message;
				auto publish_count = 0;
				rclcpp::WallRate loop_rate(500ms);

				while (rclcpp::ok()) {
				message.data = "Hello, world! " + std::to_string(publish_count++);
				RCLCPP_INFO(node->get_logger(), "Publishing: '%s'", message.data.c_str());
				publisher->publish(message);
				rclcpp::spin_some(node);
				loop_rate.sleep();
				}
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
