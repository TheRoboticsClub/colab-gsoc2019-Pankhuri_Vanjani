#include <iostream>
#include <chrono>
#include "mainsubcpp.hpp"

using namespace std; 

int main(int argc, char** argv){

	int server = 2;
        std::string topic = "/chatter";
	std::string  nodeName = "ros2cam";

// ***********Get from camera-interface*************
	camViz::CameraClient* camRGB;

	camRGB = camViz::getClient(argc,argv,server,topic,nodeName);

	int kl;
	kl = camRGB->getRefreshRate();
	cout << kl;

	return 0;
}
