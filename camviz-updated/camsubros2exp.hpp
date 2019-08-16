#pragma once
#include <memory>
#include </opt/jderobot/include/jderobot/types/image.hpp>
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

//#include "common.hpp"
#include "std_msgs/msg/string.hpp"

#include "translatorsros2.hpp"
#include <boost/thread/thread.hpp>
#include <iostream>  
#include <cv_bridge/cv_bridge.h>
#include <time.h>
#include "caminterface.hpp"

static const std::string OPENCV_WINDOW = "Image window";

namespace camViz{

using std::placeholders::_1;
using rclcpp::Node;
using rclcpp::executors::MultiThreadedExecutor;


class MinimalSubscriber : public CameraClient
{
public:

 class derivedMultiThreadedExecutor : public rclcpp::executors::MultiThreadedExecutor
    {
    public:

        //void rclcpp::executors::MultiThreadedExecutor::run	(	size_t 	this_thread_number	)	;
         void runn(size_t this_thread_number) { 
          return  run(	size_t (1)) ; 
       }
    

    };

     derivedMultiThreadedExecutor* spinner = new derivedMultiThreadedExecutor();
       //rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscription_;


    MinimalSubscriber(int argc, char** argv, std::string nodeName, std::string topic);
    ~MinimalSubscriber();
    void start();
    void stop();
    virtual JdeRobotTypes::Image getImage();
    virtual int getRefreshRate();

private:
    pthread_mutex_t mutex;
    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscription_;
		std::string topic;
		std::string  nodeName;
  

protected:
	JdeRobotTypes::Image image;
	int refreshRate;
  bool on;
	int cont = 0; //used to count Frames per seconds
	time_t timer; // used to save time for FPS
  void imagecallback (const sensor_msgs::msg::Image::SharedPtr image_msg);
};

    MinimalSubscriber::MinimalSubscriber(int argc, char** argv, std::string nodeName, std::string topic) 
    //: Node(nodeName)
    {
      	pthread_mutex_init(&mutex, NULL);

        //rclcpp::RCLCPP_INFO(this->get_logger(), "constructor Called");

        rclcpp::Node::SharedPtr g_node = rclcpp::Node::make_shared(nodeName);

        //auto g_node = rclcpp::Node::make_shared(nodeName);

        subscription_ = g_node->create_subscription<sensor_msgs::msg::Image>(
        topic,10,std::bind(&MinimalSubscriber::imagecallback, this, _1));

        std::cout << "listen from "+ topic << std::endl;   

        spinner->add_node(g_node);
        //rclcpp::spin_some(std::make_shared<camViz::MinimalSubscriber>(0, nullptr, nodeName,topic));

    }

  MinimalSubscriber::~MinimalSubscriber(){
        this->stop();
    }

  void
  MinimalSubscriber::start(){
        //RCLCPP_INFO(this->get_logger(), "starting");
        //spinner->run(size_t (4));
        this->spinner->runn(size_t (1));
        //this->spinner->spin();
        //rclcpp::spin_some(nodeName);

	    }

  void 
    MinimalSubscriber::stop(){
		//ssthis->spinner->stop();
		rclcpp::shutdown();
	}

  void
    MinimalSubscriber::imagecallback(const sensor_msgs::msg::Image::SharedPtr image_msg){
			this->cont++;
			time_t now;
			time(&now);

			pthread_mutex_lock(&mutex);
      //RCLCPP_INFO(this->get_logger(), "getting22 images");
      this->image = translate_image_messages(image_msg);
      std::cout << "in imagecallback"<< std::endl;   
      //this->image.data  = cv::imdecode(cv::Mat(image_msg->data), cv::IMREAD_UNCHANGED);
   

			if (difftime(this->timer, now)>=1){
				this->refreshRate = this->cont;
				this->cont = 0;
				this->timer = now;
			}
			pthread_mutex_unlock(&mutex);

		}


	JdeRobotTypes::Image MinimalSubscriber::getImage(){
		JdeRobotTypes::Image img;
		pthread_mutex_lock(&mutex);
		img = this->image;
		pthread_mutex_unlock(&mutex);
    std::cout << "get image"<< std::endl;   
		return img;
	}

  int MinimalSubscriber::getRefreshRate(){
        int rr;
        pthread_mutex_lock(&mutex);
        rr = this->refreshRate;
        pthread_mutex_unlock(&mutex);

        return rr;
    }



}
