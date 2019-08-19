#pragma once
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

#include <boost/thread/thread.hpp>
#include <iostream>  
#include <time.h>
#include "caminterface.hpp"

#include <thread>


namespace camViz{

using std::placeholders::_1;
using rclcpp::executors::MultiThreadedExecutor;

 class derivedMultiThreadedExecutor : public rclcpp::executors::MultiThreadedExecutor
    {
    public:
        void runn(size_t this_thread_number) { 
          run(	size_t (1)) ; 
       }
};

///////*******************Class declaration*************************////////
class MinimalSubscriber : public rclcpp::Node, public CameraClient
{
public:
    derivedMultiThreadedExecutor* spinner = new derivedMultiThreadedExecutor();
    MinimalSubscriber(int argc, char** argv, std::string nodeName, std::string topic);
    void start();
    virtual int getRefreshRate();

private:
    pthread_mutex_t mutex;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
		std::string topic;
		std::string  nodeName;
  
protected:
	int refreshRate;
  void topic_callback(const std_msgs::msg::String::SharedPtr msg);

};

    MinimalSubscriber::MinimalSubscriber(int argc, char** argv, std::string nodeName, std::string topic) 
    : Node(nodeName)
    {
      	pthread_mutex_init(&mutex, NULL);
        subscription_ = this->create_subscription<std_msgs::msg::String>(
      topic, 10, std::bind(&MinimalSubscriber::topic_callback, this, _1));
        std::cout << "listen from "+ topic << std::endl;   
        //spinner->add_node(nodeName); //***Is it right to call add_node here??
    }

// std::bind(&MinimalSubscriber::topic_callback, this, _1)

  void
  MinimalSubscriber::start(){
        RCLCPP_INFO(this->get_logger(), "starting");
        this->spinner->runn(size_t (1));

	    }

  void 
  MinimalSubscriber::topic_callback(const std_msgs::msg::String::SharedPtr msg) 
    {
      std::cout << "in topic-callback " << msg->data << std::endl;   
    }

  int MinimalSubscriber::getRefreshRate(){
        int rr;
        pthread_mutex_lock(&mutex);
        rr = this->refreshRate;
        pthread_mutex_unlock(&mutex);
        return rr;
    }
}
