#include <memory>

#include </opt/jderobot/include/jderobot/types/image.hpp>
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "std_msgs/msg/string.hpp"
#include "translatorsros2.hpp"
#include <boost/thread/thread.hpp>
#include <iostream>  
#include "common.hpp"
//#include <cv_bridge/cv_bridge.h>
#include <time.h>




namespace camViz {

	using std::placeholders::_1;
	using rclcpp::executors::MultiThreadedExecutor;


	class ListenerCameraros2 
	{
		public:

			class derivedMultiThreadedExecutor : public rclcpp::executors::MultiThreadedExecutor
			{
			public:

				//void rclcpp::executors::MultiThreadedExecutor::run	(	size_t 	this_thread_number	)	;
				void runn(size_t this_thread_number) { 
				return  run(	size_t (4)) ; 
				}
    		};
			ListenerCameraros2(int argc, char** argv, std::string nodeName, std::string topic);
			~ListenerCameraros2();

			rclcpp::Node::SharedPtr g_node = rclcpp::Node::make_shared(nodeName);

			void start();
			void stop();
			virtual JdeRobotTypes::Image getImage();
			virtual int getRefreshRate();


    		//MultiThreadedExecutor* spinner = new MultiThreadedExecutor();
			derivedMultiThreadedExecutor* spinner = new derivedMultiThreadedExecutor();





		private:
			pthread_mutex_t mutex;
			std::string topic;
			std::string  nodeName;


		protected:
			JdeRobotTypes::Image image;
			int refreshRate;
			bool on;

		int cont = 0; //used to count Frames per seconds
		time_t timer; // used to save time for FPS

	
		//rclcpp::AsyncSpinner* spinner;
		//For ros2 dashing:



		void imagecallback(const sensor_msgs::msg::Image::SharedPtr image_msg);
		//rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscription_;

		rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscription_ ;
	};

		ListenerCameraros2::ListenerCameraros2(int argc, char** argv, std::string nodeName, std::string topic){
		pthread_mutex_init(&mutex, NULL);
		if ("" == topic){
			this->on = false;
			std::cout << "insideclass\n";

			std::cerr <<"Invalid camera topic" <<std::endl;
		}else{
			this->on = true;
			this->topic = topic;
			this->nodeName = nodeName;
			std::cout << "iinsideclass2\n";

			const std::string nodeName = std::string(this->nodeName);
			time(&timer);
			int a = 0;
			//rclcpp::init(argc, argv);


			subscription_ = g_node->create_subscription<sensor_msgs::msg::Image>(topic, std::bind(&ListenerCameraros2::imagecallback, this, _1), 10);
			std::cout << "listen from "+ this->topic << std::endl;
			//this->spinner = new ros::AsyncSpinner(1);
			//this->spinner = 			spinner.add_node(g_node);
			this->spinner->add_node(g_node);




		}
	}

	//ListenerCameraros2::~ListenerCameraros2(){
		//this->stop();
	//}

	void ListenerCameraros2::start(){
		this->spinner->runn(size_t (1));


	}

	void ListenerCameraros2::stop(){
		//ssthis->spinner->stop();
		rclcpp::shutdown();
	}

	void
    ListenerCameraros2::imagecallback(const sensor_msgs::msg::Image::SharedPtr image_msg){
			this->cont++;
			time_t now;
			time(&now);
			pthread_mutex_lock(&mutex);

		this->image = translate_image_messages(image_msg);

			if (difftime(this->timer, now)>=1){
				this->refreshRate = this->cont;
				this->cont = 0;
				this->timer = now;
			}
			pthread_mutex_unlock(&mutex);

		}

		JdeRobotTypes::Image  ListenerCameraros2::getImage(){
			std::cout << "hi\n";
			JdeRobotTypes::Image img;
			pthread_mutex_lock(&mutex);
			img = this->image;
			pthread_mutex_unlock(&mutex);
			return img;
		}

		int ListenerCameraros2::getRefreshRate(){

			int rr;
			pthread_mutex_lock(&mutex);
			rr = this->refreshRate;
			pthread_mutex_unlock(&mutex);

			return rr;
		}

}
