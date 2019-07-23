/*
 *
 *  Copyright (C) 1997-2015 JdeRobot Developers Team
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see http://www.gnu.org/licenses/. 
 *
 *  Authors : 	Roberto Calvo <rocapal [at] gsyc [dot] es>
 *  			David Lobato Bravo <dav.lobato [dat] gmail [dot] com>
 *
 */

#include <iostream>
#include <chrono>


#include </opt/jderobot/include/jderobot/visionlib/colorspaces/colorspacesmm.h>
#include "viewer.h"
#include "mainsubcpp.hpp"
#include </opt/jderobot/include/jderobot/types/image.h>
#include <yaml-cpp/yaml.h>



using namespace std; 

int main(int argc, char** argv){

	camViz::Viewer viewer;

		/*
    	std::string config_file_;
        config_file_.assign(argv[1]);
		
	    YAML::Node config = YAML::LoadFile(config_file_); 
        int server = config["Server"].as<int>();

        std::string topic = config["Topic"].as<std::string>();
        int fps = config["Fps"].as<int>();
        std::string  nodeName = config["Name"].as<std::string>();
		
		
        */
		int server = 2;
        std::string topic = "/camserver/rgb";
        int fps = 30;
		std::string  nodeName = "camViz";

// ***********Get from camera-interface*************
	camViz::CameraClient* camRGB;
		std::cout << "ho";


	//Comm::Communicator* jdrc = new Comm::Communicator(cfg);

	camRGB = camViz::getCameraClient(argc,argv,server,topic,nodeName);
		std::cout << "cameraclientfound";


//////****************View in GUI******************************
	JdeRobotTypes::Image rgb;

   		std::cout << "hie";

	std::cout << viewer.isVisible();
			std::cout << "hiee";


	while(viewer.isVisible()){
		//jderobot::ImageDataPtr data = camRGB->getImageData(format);
		rgb = camRGB->getImage();
		std::cout << "imageaagyi\n";

		viewer.display(rgb.data);
		viewer.displayFrameRate(0);
	}

	//delete jdrc;

	return 0;
}
