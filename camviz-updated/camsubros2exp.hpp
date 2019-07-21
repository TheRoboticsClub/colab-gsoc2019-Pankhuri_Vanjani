#include <memory>

#include </opt/jderobot/include/jderobot/types/image.hpp>


#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "common.hpp"
#include "std_msgs/msg/string.hpp"

#include "translatorsros2.hpp"
#include <boost/thread/thread.hpp>
#include <iostream>  
#include <cv_bridge/cv_bridge.h>
#include <time.h>



namespace camViz{

using std::placeholders::_1;
using rclcpp::executors::MultiThreadedExecutor;


class MinimalSubscriber : public rclcpp::Node
{
public:

    MultiThreadedExecutor* spinner = new MultiThreadedExecutor();


  MinimalSubscriber(int argc, char** argv, std::string nodeName, std::string topic)
  : Node(nodeName)
  {
    RCLCPP_INFO(this->get_logger(), "constructor Called");
    rclcpp::Node::SharedPtr g_node = rclcpp::Node::make_shared(nodeName);

    subscription_ = this->create_subscription<sensor_msgs::msg::Image>(
      topic, std::bind(&MinimalSubscriber::imagecallback, this, _1), 10);
	std::cout << "listen from "+ topic << std::endl;   

    spinner->add_node(g_node);

    void start();


  }

	void start(){
		this->spinner->spin();

	}
    
	//virtual int getRefreshRate();

    int getRefreshRate(){

        int rr;
        pthread_mutex_lock(&mutex);
        rr = this->refreshRate;
        pthread_mutex_unlock(&mutex);

        return rr;
    }

private:
    pthread_mutex_t mutex;

  void topic_callback(const sensor_msgs::msg::Image::SharedPtr message)
  {
    RCLCPP_INFO(this->get_logger(), "In callback");

    cv::Mat cv_mat = cv::imdecode(cv::Mat(message->data), cv::IMREAD_UNCHANGED);

    //RCLCPP_INFO(this->get_logger(), "I heard: '%s'", "Image");

    cv::Mat c_mat = cv_mat;

    //std::cout << c_mat.rows << " " << c_mat.cols << std::endl;

    //cv::imshow("camViz", c_mat);

    char key = cv::waitKey(1);

    if (key == 27 /* ESC */ || key == 'q') {
      rclcpp::shutdown();
    }
    
  }

  	void
    imagecallback(const sensor_msgs::msg::Image::SharedPtr image_msg){
			this->cont++;
			time_t now;
			time(&now);
			pthread_mutex_lock(&mutex);

		this->image = translate_image_messages(image_msg);

        //this->image.data  = cv::imdecode(cv::Mat(image_msg->data), cv::IMREAD_UNCHANGED);

			if (difftime(this->timer, now)>=1){
				this->refreshRate = this->cont;
				this->cont = 0;
				this->timer = now;
			}
			pthread_mutex_unlock(&mutex);

		}
  
  rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscription_;

protected:
	JdeRobotTypes::Image image;
	int refreshRate;
	int cont = 0; //used to count Frames per seconds
	time_t timer; // used to save time for FPS
};






}