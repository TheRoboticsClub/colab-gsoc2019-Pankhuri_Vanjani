#include <sstream>
#include <yaml-cpp/yaml.h>
#include "main.hpp"

int main(int argc, char **argv)
{
    std::string config_file_;
    config_file_.assign(argv[1]);
	YAML::Node config = YAML::LoadFile(config_file_);
    int server = config["Server"].as<int>();
    	switch (server){
		case 1:
		{
			//system("/opt/ros/melodic/setup.bash");
			#ifdef ROS1_H
				std::cout << "Receiving Image from ROS messages" << std::endl;
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
			#endif
		 	break;
		}
		case 2:
		{
			#if ROS2_H			
            //system("/opt/ros/dashing/setup.bash");
			std::cout << "Receiving Image from ROS2 messages" << std::endl;
			#endif
		 	break;
		}
		default:
		{
			printf("No ROS1; ROS2");
            break;
		}
return 0;    
}



}
