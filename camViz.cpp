#include <iostream>
#include <chrono>
#include "mainsubcpp.hpp"
#include "subros2.hpp"

using namespace std; 

int main(int argc, char** argv){

	int server = 2;
    std::string topic = "/chatter";
	std::string  nodeName = "ros2cam";

/*	rclcpp::init(argc, argv);
  	rclcpp::spin(std::make_shared<camViz::MinimalSubscriber>(0, nullptr, nodeName, topic));
  	rclcpp::shutdown();
*/

// ***********Get from camera-interface*************
	camViz::CameraClient* camRGB;

	camRGB = camViz::getClient(argc,argv,server,topic,nodeName);

	cout << "here" << endl;

	//rclcpp::spin(camRGB);
	//rclcpp::shutdown();

	if (camRGB == NULL)
		cout << "here" << endl;

	shared_ptr<camViz::MinimalSubscriber> ptr((camViz::MinimalSubscriber*)camRGB);
 
	rclcpp::executors::SingleThreadedExecutor exec;
	exec.add_node(ptr);

	auto spin_exec = [&exec]() {
    	exec.spin();
  	};

	std::thread execution_thread(spin_exec);

	cout << "Prining Something in Between" << endl;

	cout << "Prining Something in Between" << endl;

	cout << "Prining Something in Between" << endl;

	cout << "Prining Something in Between" << endl;

	execution_thread.join();

	return 0;

}
